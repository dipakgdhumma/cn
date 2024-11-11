// TCP File Receiver (Server)
#include <iostream>
#include <fstream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind and listen
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 1);
    
    std::cout << "Waiting for client to send file..." << std::endl;
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    // Open file to write
    std::ofstream outFile("received_file.mp3", std::ios::binary);
    char buffer[1024];
    int bytesReceived;
    
    // Receive file data in chunks
    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        outFile.write(buffer, bytesReceived);
    }

    std::cout << "File received and saved as 'received_file.txt'" << std::endl;

    // Close sockets and file
    outFile.close();
    close(clientSocket);
    close(serverSocket);

    return 0;
}
