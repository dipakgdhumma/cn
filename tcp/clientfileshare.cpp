// TCP File Sender (Client)
#include <iostream>
#include <fstream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // Open file to read
    std::ifstream inFile("data.mp3", std::ios::binary);
    char buffer[1024];
    
    // Read file and send in chunks
    while (inFile.read(buffer, sizeof(buffer))) {
        send(clientSocket, buffer, sizeof(buffer), 0);
    }
    // Send the remaining bytes
    send(clientSocket, buffer, inFile.gcount(), 0);

    std::cout << "File sent successfully" << std::endl;

    // Close socket and file
    inFile.close();
    close(clientSocket);

    return 0;
}
