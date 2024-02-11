#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Set up server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Port number
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // IP address

    // Connect to server
    if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error connecting to server\n";
        return 1;
    }

    // Receive message from server
    char buffer[1024] = {0};
    int valread = read(clientSocket, buffer, 1024);
    std::cout << "Server message: " << buffer << std::endl;

    // Close socket
    close(clientSocket);

    return 0;
}
