#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define SIZE 1024
#define PORT 8080
int main()
{
    int sockfd, connfd, l, n;
    char mess[SIZE];
    struct sockaddr_in servaddr, clieaddr;
    l = sizeof(clieaddr);
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sockfd, ((struct sockaddr *)&servaddr), sizeof(servaddr))==0)
    {
        printf("Bind Socket: S\n");
    }
    else
    {
        printf("Bind Socket: F\n");
        exit(0);
    }
    if(listen(sockfd, 4)==0)
    {
        printf("Listening: S\n");
    }
    else
    {
        printf("Listening: F\n");
        exit(0);
    }
    if((connfd = accept(sockfd, ((struct sockaddr *)&clieaddr), &l))>=0)
    {
        printf("Accept: S\n");
    }
    else
    {
        printf("Accept: F\n");
        exit(0);
    }
    n = recv(connfd, mess, SIZE, 0);
    mess[n] = '\0';
    printf("Client's Message: %s\n", mess);
    printf("Enter a response message:\n");
    scanf("%[^\n]s", mess);
    send(connfd, mess, strlen(mess), 0);
    close(connfd);
    close(sockfd);
}
