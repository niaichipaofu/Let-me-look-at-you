#include <cstdio>
#include<string.h>
#include"_Socket.h"
int main()
{
	Socket_Server_IPv4_TCP server;
	server._Server();
	char str[20];
	int i=0;
	while (server.Server_accept())
	{
		printf("input\n");
		scanf("%s",str);
		i=strlen(str);
		str[i-1]='\r';
		str[i]='\n';
		str[i+1]='\0';
		server.Server_sendStr(str);
	}
    return 0;
}