#pragma comment(lib,"ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#pragma warning(disable:4996)

int main()
{
	setlocale(LC_ALL, "Russian");
	char buf[255], b[255];
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return 0; }
	SOCKET s;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	sockaddr_in add;
	add.sin_family = AF_INET;
	add.sin_port = htons(1024);
	add.sin_addr.s_addr = inet_addr("127.0.0.1");
	int t;
	t = sizeof(add);
	cout << "Введите строку символов: " << endl;
	cin.getline(buf, 100, '\n');
	sendto(s, buf, strlen(buf), 0, (struct sockaddr*) & add, t);
	int rv = recvfrom(s, b, strlen(b), 0, (struct sockaddr*) & add, &t);
	b[rv] = '\0';
	cout << b << endl;
	closesocket(s);
	WSACleanup();

	return 0;

}