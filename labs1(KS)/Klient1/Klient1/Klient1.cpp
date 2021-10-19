#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib,"Wsock32.lib")

using namespace std;

int main() {
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(s, (struct sockaddr*) & peer, sizeof(peer)) != 0)
	{
		cout << "Server don't open...";
	}
	else
	{
		char buf[255], b[255];
		cout << "Input string: " << endl;
		cin.getline(buf, 100, '\n');

		send(s, buf, sizeof(buf), 0);
		recv(s, b, sizeof(b), 0);
			cout << "Reverse string: " << b << endl;
			cin.get();
	}
	closesocket(s);
	WSACleanup();
	return 0;
}