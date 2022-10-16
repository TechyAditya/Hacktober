#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define SIZE 1024
#define PORT 8080
int main()
{
    int sockfd, n;
    char mess[SIZE];
    struct sockaddr_in servaddr;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))!=(-1))
    {
        printf("Create Socket: S\n");
    }
    else
    {
        printf("Create Socket: F\n");
        exit(0);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    if(connect(sockfd, ((struct sockaddr *)&servaddr), sizeof(servaddr))==0)
    {
        printf("Connection: S\n");
    }
    else
    {
        printf("Connection: F\n");
        exit(0);
    }
    printf("Enter a request message:\n");
    scanf("%[^\n]s", mess);
    send(sockfd, mess, strlen(mess), 0);
    n = recv(sockfd, mess, SIZE, 0);
    mess[n] = '\0';
    printf("Server's Message: %s\n", mess);
    close(sockfd);
}
