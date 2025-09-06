#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s port\n", argv[0]);
        return -1;
    }

    uint16_t port = atoi(argv[1]);
    int listenfd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    // 1. 创建 socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket failed, ec: %d, info: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // 2. 设置端口复用
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        printf("setsockopt failed, ec: %d, info: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // 3. 绑定地址和端口
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // 任意网卡
    address.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        printf("bind failed, ec: %d, info: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // 4. 监听
    if (listen(listenfd, SOMAXCONN) < 0)
    {
        printf("listen failed, ec: %d, info: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", port);

    while (true)
    {
        struct sockaddr_in clientaddr;
        socklen_t clientaddrlen = sizeof(clientaddr);
		//5. 接受客户端连接
        int clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
        if (clientfd != -1)
        {
			char recvBuf[32] = {0};
			//6. 从客户端接受数据
			int ret = recv(clientfd, recvBuf, 32, 0);
			if (ret > 0)
			{
                printf("recv data from client %s:%d, data: %s\n",
                    inet_ntoa(clientaddr.sin_addr),
                    ntohs(clientaddr.sin_port),
                    recvBuf);
				//7. 将收到的数据回弹给客户端
				ret = send(clientfd, recvBuf, strlen(recvBuf), 0);
				if (ret != strlen(recvBuf))
                    printf("send data error, ec: %d, info: %s\n", errno, strerror(errno));
                printf("send data to client successfully, data: %s\n", recvBuf);
			}
			else
			{
                printf("recv data error, ec: %d, info: %s\n", errno, strerror(errno));
			}

			close(clientfd);
        }
    }

	//8.关闭侦听socket
	close(listenfd);
    return 0;
}
