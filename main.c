#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int valid_ip(const char *ip);

int main() {
    char ip[100];
    int port, end_port;

    printf("Enter target IP: ");
    scanf("%s", ip);
    if(valid_ip(ip) == 1) {
        printf("Invalid IP (IPv4 formed)\n");
        return 1;
    }

    printf("Enter start port: ");
    scanf("%d", &port);

    printf("Enter end port: ");
    scanf("%d", &end_port);

    if (port < 1 || end_port > 65535 || port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    printf("\nScanning %s from port %d to %d...\n\n", ip, port, end_port);

    int open_count = 0;

    for (; port <= end_port; port++) {

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Socket creation failed.\n");
            return 1;
        }

        struct sockaddr_in target;
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(ip);

        int result = connect(sock, (struct sockaddr*)&target, sizeof(target));

        if (result == 0) {
            printf("Port %d OPEN\n", port);
            open_count++;
        }

        close(sock);
    }

    printf("\nScan complete.\n");
    printf("Total open ports: %d\n", open_count);

    return 0;
}

int valid_ip(const char *ip)
{
    int a,b,c,d;

    if(sscanf(ip, "%d.%d.%d.%d", &a,&b,&c,&d) == 4)
    {
        if(a < 0 || a > 255)return 0;
        if(b < 0 || b > 255)return 0;
        if(c < 0 || c > 255)return 0;
        if(d < 0 || d > 255)return 0;

        return 0;
    }

    return 1;
}
