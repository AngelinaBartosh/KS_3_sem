#include <iostream>
#include <sys/types.h>
#include<sys/socket.h>
#include<sys/signal.h>
#include<sys/wait.h>
#include<sys/resource.h>
#include<netinet/in.h>

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


using namespace std;

int connection;
void add_books();
void task();
void print();
void sort();
int Func();
void reaper(int);
int z = 0;
class Books
{
public:
	char fam[255];
	Books(const char[], const char[], int, const char[]);
	Books() {}
	int get_year()
	{
		return this->year;
	}
private:
	char name[255];
	char tel[255];
	int year;
}*S = new Books[10];

Books::Books(const char fam[], const char name[], int year, const char tel[])

{

	strcpy(this->fam, fam);

	strcpy(this->name, name);

	this->year = year;

	strcpy(this->tel, tel);

}

int main() {
	setlocale(LC_ALL, "Russian");


	add_books();

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;

	addr.sin_port = htons(1280);

	addr.sin_addr.s_addr = 0;

	int s = socket(AF_INET, SOCK_STREAM, 0);

	bind(s, (sockaddr*)&addr, sizeof(addr));

	listen(s, 5);

	cout << "READY" << endl;

	int size = sizeof(addr);

	(void)signal(SIGCHLD, reaper);

	while (true)

	{
		if ((connection = accept(s, NULL, NULL)) < 0)

		{

			cout << "EROR" << endl;

			exit(1);

		}

		cout << "CLIENT CONNECT" << endl;

		switch (fork()) {

		case 0:

			(void)close(s);

			exit(Func());

		default:

			(void)close(connection);

		}


	}

}
void add_new() {
	if (z <= 10) {
		if (recv(connection, (char*)&S[z], sizeof(Books), 0) < 0)

		{

			cout << "ERROR!" << endl;

			exit(0);

		}

		cout << S[z].fam << endl;
		z++;
	}
}
void remove() {
	int i;
	for (int i = 0; i < z; i++)
		send(connection, (char*)&S[i], sizeof(Books), 0);

	if (recv(connection, (char*)&i, sizeof(int), 0) <= 0)

	{
		cout << "ERROR!" << endl;

		exit(0);
	}
	cout << i << endl;
	i--;
	int n = z - 1;
	if (n == 1)
		z--;
	else {
		for (int j = i; j < z - 1; j++) {
			if (i == z - 1) break;
			else
				S[j] = S[j + 1];
		}
	}
	z--;
	i = i + 1;
	cout << "UDALEN № " << i << endl;
}

void add_books() {

	S[0] = Books("ZHYN", "ANDREY", 2001, "375445760761");
	z++;
	S[1] = Books("KOTOVA", "ELIZAVETA", 2001, "375442124123");
	z++;

	S[2] = Books("BARTOSH", "ANGELINA", 2002, "375293036302");
	z++;

	S[3] = Books("KUC", "LESHA", 2000, "375442025568");
	z++;

	S[4] = Books("LEMESH", "VLAD", 2001, "375445760099");
	z++;

}

void task()

{

	char buf[60];

	if (recv(connection, buf, sizeof(buf), 0) >= 0)

	{
		int comparemark = atoi(buf);

		cout << comparemark << endl;

		for (int i = 0; i < z; i++)

		{

			if (S[i].get_year() == comparemark)

			{

				strcpy(buf, S[i].fam);

				send(connection, buf, sizeof(buf), 0);

			}

		}

	}

	send(connection, "end", sizeof("end"), 0);

}

void print()

{

	for (int i = 0; i < z; i++)

		send(connection, (char*)&S[i], sizeof(Books), 0);

}

void sort() {

	for (int i = 0; i < z; i++)

		send(connection, (char*)&S[i], sizeof(Books), 0);

}

void reaper(int sig) {

	int status;

	while (wait3(&status, WNOHANG, (struct rusage*)0) >= 0);

}

int Func()
{

	int i;

	while (recv(connection, (char*)&i, sizeof(int), 0) >= 0)

	{

		switch (i)

		{

		case 1: cout << "POISK PO GODU RAZHDENIYA " << endl; task(); break;

		case 2: cout << "VIVOD ZAP KNIGI " << endl; print(); break;

		case 3: cout << "SORTIROVKA PO FAMILYI" << endl; sort(); break;
		case 4: cout << "Udalenie" << endl; remove(); break;
		case 5: cout << "Dobavlenie" << endl; add_new(); break;

		case 6: cout << "UDAL KLIENT" << endl; exit(0); break;

		default: system("cls"); cout << "Data transmission error!" << endl; return 1;

		}

	}

	if (i != 5)

		cout << "UDALEN" << endl;

}