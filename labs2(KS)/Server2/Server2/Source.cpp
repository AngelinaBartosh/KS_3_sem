#pragma comment(lib,"ws2_32.lib")

#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#pragma warning(disable:4996)

void main()
{
	setlocale(LC_ALL, "Russian");
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	struct sockaddr_in ad;
	SOCKET s;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	ad.sin_port = htons(1024);
	ad.sin_family = AF_INET;
	ad.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(s, (struct sockaddr*) & ad, sizeof(ad));
	char b[255];
	cout << "Server was connected, await client...";
	int l, i = 0, j = 0;
	l = sizeof(ad);
	int rv = recvfrom(s, b, strlen(b), 0, (struct sockaddr*) & ad, &l);
	b[rv] = '\0';
	cout << b << endl;
	char* str = new char[rv]();
	if (rv % 2 == 0)
	{
		for (i = 3; i < rv - 2; i++, j++)
		{
			str[j] = b[i];
		}
		str[j] = '\0';
		sendto(s, str, strlen(str), 0, (struct sockaddr*) & ad, l);
	}
	else
	{
		sendto(s, b, strlen(b), 0, (struct sockaddr*) & ad, l);
	}
	closesocket(s);
	WSACleanup();
}