#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int main()
{
    struct sockaddr_in server_address, client_address;
    int number, client_number, socket_file_descriptor, length, last_digit, message_length;
    if((socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0))<0)
    {
        perror("Sorry! I'm unable to create the socket.\n");
        exit(EXIT_FAILURE);
    }
    memset(&server_address, 0, sizeof(server_address));
    memset(&client_address, 0, sizeof(client_address));
    server_address.sin_port = htons(PORT);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    if(bind(socket_file_descriptor, ((struct sockaddr *) &server_address), sizeof(server_address))<0)
    {
        perror("Sorry! I'm unable to bind information to the socket.\n");
        exit(EXIT_FAILURE);
    }
    length = sizeof(client_address);
    message_length = recvfrom(socket_file_descriptor, &client_number, sizeof(int), 0, ((struct sockaddr *) &client_address), &length);
    printf("Client's Number: %d\n", client_number);
    number = 0;
    while(client_number>0)
    {
        last_digit = client_number % 10;
        number = number + last_digit;
        client_number = client_number / 10;
    }
    sendto(socket_file_descriptor, &number, sizeof(int), 0, ((const struct sockaddr *) &client_address), length);
    printf("I've sent the number.\n");
    return (0);
}
