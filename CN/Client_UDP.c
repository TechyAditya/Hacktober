#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
int main()
{
    struct sockaddr_in server_address;
    int number, server_number, socket_file_descriptor, length, message_length;
    printf("Enter a number:\n");
    scanf("%d", &number);
    if((socket_file_descriptor = socket(AF_INET, SOCK_DGRAM, 0))<0)
    {
        perror("Sorry! I'm unable to create the socket.\n");
        exit(EXIT_FAILURE);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_port = htons(PORT);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    sendto(socket_file_descriptor, &number, sizeof(int), 0, ((struct sockaddr *) &server_address), sizeof(server_address));
    printf("I've sent the number.\n");
    message_length = recvfrom(socket_file_descriptor, &server_number, sizeof(int), 0, ((struct sockaddr *) &server_address), &length);
    printf("Server's Number: %d\n", server_number);
    close(socket_file_descriptor);
    return (0);
}
