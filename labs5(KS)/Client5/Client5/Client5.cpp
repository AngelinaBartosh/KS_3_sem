#include <iostream.>
#include <winsock2.h>
#include <process.h> 
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime> 
#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;


void enter(SOCKET s)
{
	while (true)
	{
		char l_login[] = "admin", p_password[] = "admin";
		char login[20], password[20], ent;
		int i = 0;
		cout << "    <<Авторизация>>\n";
		cout << "Логин: \n";
		cin >> login;
		cout << "Пароль: \n";
		while (true)
		{
			ent = _getch();
			if (ent == 13)
			{
				password[i] = '\0';
				break;
			}
			else
			{
				password[i] = ent;
				printf("*");
				i++;
			}
		}

		send(s, login, sizeof(login), 0);
		send(s, password, sizeof(password), 0);
		
		if (l_login == login && p_password == password)
		{
			cout << "\nIncorrect login or password!\n";
			system("pause & cls");
		}
		else
		{
			cout << "\nYou have successfully signed in!\n";
			system("pause & cls");
			break;
		}
	}
}
void command(SOCKET s)
{
	char command[20], message[100];
	while (true)
	{
		cout << "Enter command \"send_message\" to send a message, \"del_message\" to delete a message or \"quite\" to end work\n";
		cin >> command;
		if (strcmp(command, "send_message") == 0)
		{
			send(s, command, sizeof(command), 0);
			system("cls");
			cout << "Enter message: ";
				getchar();
			cin.getline(message, 100, '\n');
			send(s, message, sizeof(message), 0);
			cout << "Message sent!\n";
			system("pause & cls");
		}
		else if (strcmp(command, "del_message") == 0)
		{
			send(s, command, sizeof(command), 0);
			system("cls");
			cout << "Message deleted successfully!\n";
			system("pause & cls");
		}
		else
		{
			if (strcmp(command, "quite") == 0)
			{
				send(s, command, sizeof(command), 0);
				break;
			}
			else
			{
				cout << "Incorrect input!\n";
				system("pause & cls");
			}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	WORD wVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(wVersion, &wsaData) != 0)
	{
		cerr << "Error client! #" << WSAGetLastError() << endl;
		exit(1);
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1280);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	connect(s, (sockaddr*)&addr, sizeof(addr));

	enter(s);
	command(s);
	WSACleanup();
}