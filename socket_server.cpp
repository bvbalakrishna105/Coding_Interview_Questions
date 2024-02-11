#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    // Set up server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080); // Port number

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error binding socket\n";
        return 1;
    }

    // Listen for incoming connections
    listen(serverSocket, 5);

    // Accept incoming connection
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket < 0) {
        std::cerr << "Error accepting connection\n";
        return 1;
    }

    // Send message to client
    const char *message = "Hello from server!";
    send(clientSocket, message, strlen(message), 0);

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
