

// TCP SERVER SIDE CODE:


#include <stdio.h>
#include <stdlib.h>

// Socket libraries:
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main() {

    // Send message to connected clients:
    char server_message[256] = "You are connected to the server!";

    // Create the socket:
    int server_socket = 0;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define server address:
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the IP and Port:
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Listen for client requests (passive open)
    listen(server_socket, 5);

    // Accept a request and store the client's socket:
    int client_socket = 0;
    client_socket = accept(server_socket, NULL, NULL);

    // Send the data to the client socket:
    send(client_socket, server_message, sizeof(server_message), 0);

    // Close the server socket:
    close(server_socket);

    return 0;
}
