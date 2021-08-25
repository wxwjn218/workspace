#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
	//1、创建socket
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket == -1){
		printf("创建socket失败!\n");
		return -1;
	}
	printf("创建socket成功！\n");

	//2、向服务器发起连接请求
	struct sockaddr_in clientAddr;
	clientAddr.sin_family = AF_INET;
	struct hostent* h;
	h = gethostbyname("qhlovejcx.cloud");
	if(h == 0){
		printf("获取host失败！\n");
		close(clientSocket);
		return -1;
	}
	memcpy(&clientAddr.sin_addr, h->h_addr, h->h_length);
	clientAddr.sin_port = htons(39002);

	int connectRes = connect(clientSocket, (struct sockaddr*)& clientAddr, sizeof(clientAddr));
	if(connectRes == -1){
		printf("连接失败！\n");
		close(clientSocket);
		return -1;
	}
	
	printf("连接成功！\n");

	
}
