

// TCP CLIENT SIDE CODE:


#include <stdio.h>
#include <stdlib.h>

// Socket libraries:
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main() {

    printf("\n\n TCP Client Program \n\n");


    // Create a socket:
    int network_socket = 0;                                     
    network_socket = socket(AF_INET, SOCK_STREAM, 0);           


    // Specify an adress to connect to for the socket:
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;                        
    server_address.sin_port = htons(9000);                      
    server_address.sin_addr.s_addr = INADDR_ANY;                


    // Connect to server:
    int connection_status = 0;                                  
    connection_status = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    
    if (connection_status == 0) {
        // Success = 0 returned by connect()
        printf(" Connection established successfully. \n\n");
    } else if (connection_status == -1) {
        // Fail = -1 returned by connect()
        printf(" Connection couldn't be established :( \n\n");
    }


    // Recieve data from the server:
    char server_response[300];                                  
    recv(network_socket, &server_response, sizeof(server_response), 0);


    // Print the data recieved from server:
    printf(" The server sent the data: %s \n\n", server_response);


    // Close the socket:
    close(network_socket);


    return 0;
}