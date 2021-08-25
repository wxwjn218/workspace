#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
//#include <sys/types.h>
//#include <sys/socket.h>

void byteOrder(){
	union {
		short a;
		char b;
	}test;
	test.a = 0x0001;
	if(test.b == 1){
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}

}

int main(){
	//byteOrder();
	//1、创建socket
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == serverSocket){
		printf("创建socket失败！\n");
		return -1;
	}
	printf("创建socket成功！\n");
	printf("socketId=%d\n", serverSocket);	

	//2、绑定地址和端口
	struct sockaddr_in serverAddr;
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(39002);
	int bindRes = bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(bindRes == -1){
		printf("bind 失败！\n");
		close(serverSocket);
		return -1;
	}
	printf("bind 成功！\n");

	while(1){

	}
	return 0;
}
