#include <iostream.>
#include <winsock2.h>
#include <process.h> 
#include <string>
#include <fstream>
#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;

void enter(void* connection)
{
	int f = 0;
	while (f == 0)
	{
		char login[20] = "login1", password[20] = "password1", loginbuff[20], passwordbuff[20];
		recv((SOCKET)connection, loginbuff, sizeof(loginbuff), 0);
		recv((SOCKET)connection, passwordbuff, sizeof(passwordbuff), 0);
		while (true)
		{
			if (strcmp(login, loginbuff) == 0)
			{
				f = 1;
				break;
			}
		}
		while (true)
		{
			if (strcmp(password, passwordbuff) == 0)
			{
				f = 1;
				break;
			}
		}
		send((SOCKET)connection, (char*)&f, sizeof(int), 0);
	}
	return;
}
void command(void* connection)
{
	char command[20], message[100], messagebuff[100];
	while (true)
	{
		recv((SOCKET)connection, command, sizeof(command), 0);
		if (strcmp(command, "send_message") == 0)
		{
			recv(SOCKET(connection), message, sizeof(message), 0);
			ofstream file("Message.txt", ios::out);
			file << message;
			cout << "Message: " << message;
			file.close();
		}
		else if (strcmp(command, "del_message") == 0)
		{
			if (remove("D:\\2 courses\\KS\\labs5(KS)\\Server5\\Server5\\Message.txt") != 0)
				cout << "\nError delete message" << endl;
			else
				cout << "\nMessage successfull delete" << endl;
		}
		else
		{
			if (strcmp(command, "quite") == 0)
			{
				cout << "\nUser disconected!\n";
				break;
			}
		}
	}
}
void working(void* connection)
{
	enter(connection);
	cout << "Client connected!" << endl;
	command(connection);
}

int main()
{
	WORD wVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(wVersion, &wsaData) != 0)
	{
		cerr << "Error server! #" << WSAGetLastError() << endl;
		exit(1);
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1280);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	bind(s, (SOCKADDR*)&addr, sizeof(addr));
	listen(s, 5);

	cout << "Server created!" << endl;

	while (true)
	{
		int size = sizeof(addr);
		SOCKET connection = accept(s, (SOCKADDR*)&addr, &size);
		_beginthread(working, 0, (void*)connection);
	}
	WSACleanup();
}