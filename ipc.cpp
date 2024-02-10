#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

using namespace std;

#define SHM_SIZE 1024 // Size of shared memory segment

int main() {
    key_t key = ftok("/tmp", 'A'); // Generate a key for the shared memory segment
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Create a shared memory segment
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char* shmaddr = (char*)shmat(shmid, NULL, 0); // Attach to the shared memory segment
    if (shmaddr == (char*)(-1)) {
        perror("shmat");
        return 1;
    }

    pid_t pid = fork(); // Fork a child process
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        cout << "Child process writing to shared memory..." << endl;
        snprintf(shmaddr, SHM_SIZE, "Hello from child process!");
        sleep(1); // Wait for the parent process to read
    } else {
        // Parent process
        cout << "Parent process reading from shared memory..." << endl;
        sleep(1); // Wait for the child process to write
        cout << "Message from child process: " << shmaddr << endl;
    }

    // Detach from the shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        return 1;
    }

    // Remove the shared memory segment (optional)
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    return 0;
}
