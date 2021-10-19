#define _CRT_SECURE_NO_WARNINGS

#include <winsock2.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#pragma comment(lib,"Ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;

void TurnStr(char* str)
{
	char tmp;
	int i = 0;
	int size = 0;
	for (size; str[size] != '\0'; size++);
	size--;
	while (i <= size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		size--;
		i++;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(1280);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	int c = bind(s, (struct sockaddr*) & local, sizeof(local));
	int r = listen(s, 5);
	
	while (true) {
		char b[255], res[255]; 
		cout << "Server was connected, await client...";
		sockaddr_in remote_addr;
		int size = sizeof(remote_addr);
		SOCKET s2 = accept(s, (struct sockaddr*) & remote_addr, &size);

		while (recv(s2, b, sizeof(b), 0) != 0) {
			TurnStr(b);
			send(s2, b, sizeof(b), 0);
		}
		closesocket(s2);
	}
	WSACleanup();
}