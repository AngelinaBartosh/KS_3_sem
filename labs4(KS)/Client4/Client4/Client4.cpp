#include <iostream>
#include <sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;
int z = 5;

class Books
{
public:
	Books() {};
	void display();
	void vvod() {
		cout << "VVEDITE FAM" << endl;
		cin >> fam;
		cout << "VVEDITE TELEF" << endl;
		cin >> tel;
		cout << "VVEDITE IMYA" << endl;
		cin >> name;
		cout << "VVEDITE GOD ROZH" << endl;
		cin >> year;
	};
	char fam[255];
private:
	char tel[255];
	char name[255];
	int year;

};

int s;
void task();
void sort();
int menu();
void addn();
void udal1();
void vvodd();
void print_books();
void Books::display() {

	cout << fam << " " << name << " " << year << " " << tel << endl;

}


Books* S = new Books[10];

int main() {

	setlocale(LC_ALL, "Russian");

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;

	addr.sin_port = htons(1280);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	s = socket(AF_INET, SOCK_STREAM, 0);

	if ((connect(s, (struct sockaddr*) & addr, sizeof(addr))) < 0)

	{

		cout << "ERROR." << endl;

		exit(1);

	}

	cout << "CONNECT.\n" << endl;
	while (true)

	{

		switch (menu())

		{

		case 1: task(); break;

		case 2: {int i = 2; send(s, (char*)&i, sizeof(int), 0); print_books(); break; }

		case 3: {int i = 3; send(s, (char*)&i, sizeof(int), 0); sort(); break; }
		case 4: {udal1();  break; }
		case 5: {addn(); break; }

		case 6: {int i = 6; send(s, (char*)&i, sizeof(int), 0); return 0; }

		default:

		{

			cout << "ERROR VIBORA.\n"; break;

		}

		}

	}

}
void addn() {
	if (z != 9) {
		int i = 5;
		Books bf;
		send(s, (char*)&i, sizeof(int), 0);
		while (true)
		{

			bf.vvod();
			break;
		}
		send(s, (char*)&bf, sizeof(Books), 0);
		z++;

	}
	else cout << "MNOGO DANNIH" << endl;
};
int menu() {

	char i;

	while (true) {

		cout << "1 - POISK PO GODU RAZHDENIYA.\n"

			"2 - VIVOD ZAP KNIGI.\n"

			"3 - SORTIROVKA PO FAMILYI.\n"
			"4 - UDALENIE. \n "
			"5- DOBAVLENIE. \n"
			"6 - VIHOD.\n"


			"ENTER: ";

		cin >> i;

		if (atoi(&i) >= 1 && atoi(&i) <= 6) break;

	}

	return atoi(&i);

}

void print_books()

{

	for (int i = 0; i < z; i++)

	{
		if (recv(s, (char*)&S[i], sizeof(Books), 0) < 0)

		{

			cout << "ERROR!" << endl;

			exit(0);

		}

	}

	for (int i = 0; i < z; i++) { cout << i + 1 << " "; S[i].display(); }

}
void udal1() {
	if (z != 0) {
		int i = 4;
		send(s, (char*)&i, sizeof(int), 0);
		for (int i = 0; i < z; i++)

		{

			if (recv(s, (char*)&S[i], sizeof(Books), 0) < 0)

			{

				cout << "ERROR!" << endl;

				exit(0);

			}

		}
		int j = 0;
		while (true)

		{
			for (int i = 0; i < z; i++) { cout << i + 1 << " "; S[i].display(); }
			cout << "vvedite nomer udalyzemogo" << endl;
			cin >> j;

			break;

		}
		z = z - 1;
		send(s, (char*)&j, sizeof(int), 0);
		cout << "udalen";
	}
	else cout << "NELZYA UDAL";

}



void sort() {

	for (int i = 0; i < z; i++)

	{

		if (recv(s, (char*)&S[i], sizeof(Books), 0) < 0)

		{

			cout << "ERROR!" << endl;

			exit(0);

		}

	}
	char c[255];

	for (int i = 0; i < z; i++)

	{
		for (int j = i + 1; j < z; j++) {
			if (strcmp(S[i].fam, S[j].fam) > 0)
			{

				strcpy(c, S[i].fam);

				strcpy(S[i].fam, S[j].fam);

				strcpy(S[j].fam, c);
			}
		}
		cout << i << endl;
		cout << S[i].fam << endl;
	}
}

void task()

{

	int i = 1;

	char GOD[12], buf[60];

	send(s, (char*)&i, sizeof(int), 0);

	while (true)

	{

		cout << "VVEDITE GOD ROZHDENIYA: ";

		cin >> GOD;

		if (atoi(GOD) >= 0 && atoi(GOD) <= 2005) break;

	}

	send(s, GOD, sizeof(GOD), 0);

	while (true) {

		if (recv(s, buf, sizeof(buf), 0) >= 0) {


			if (strlen(buf) >= 3) cout << buf << endl;
			if (strcmp(buf, "end") == 0) break;



		}

	}

}