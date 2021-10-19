//Client
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <exception>
#include <string>
#include <iomanip>

#define BUFF 512
#pragma warning(disable: 4996)
SOCKET Connection;
using namespace std;

void term_func();

class Client {
protected:
	char name[BUFF];
	char surname[BUFF];
	char login[BUFF];
	char password[BUFF];
public:
	Client() {
		std::strncpy(this->name, "", sizeof(this->name));
		std::strncpy(this->surname, "", sizeof(this->surname));
		std::strncpy(this->login, "", sizeof(this->login));
		std::strncpy(this->password, "", sizeof(this->password));
	};
	//void addExpert();
	void addClient(char name[BUFF], char surname[BUFF], char login[BUFF], char password[BUFF]) {
		std::strncpy(this->name, name, sizeof(this->name));
		std::strncpy(this->surname, surname, sizeof(this->surname));
		std::strncpy(this->login, login, sizeof(this->login));
		std::strncpy(this->password, password, sizeof(this->password));
	}
	//void editExpert();
	//void delExpert();
	void changePass(char pass[BUFF]) {
		strncpy(this->password, pass, sizeof(this->password));
	}
	string getName() {
		return string(name);
	};
	string getSurname() {
		return string(surname);
	};
	string getLogin() {
		return string(login);
	};
	string getPass() {
		return string(password);
	};
	string getInfo() {
		string result;
		result += string(login) + " " + string(password) + " " + string(name) + " " + string(surname);
		return result;
	}
};

//unsigned int Client::id = 0;
class Admin : public Client {
public:
	Admin() {
		std::strncpy(this->login, "", sizeof(this->login));
		std::strncpy(this->password, "", sizeof(this->password));
	}
	void setAutorisation(const char login[BUFF], const char password[BUFF]) {
		std::strncpy(this->login, login, sizeof(this->login));
		std::strncpy(this->password, password, sizeof(this->password));
	}
	//void setMarks();
	//void calculate();
	//void addClient();
	//void generateReExpert();
};

class Service {
private:
	string name;
	double markCity, markStreet, markCountRoom, markS, markType, markFloor, markYear, markPrice;
public:
	Service(string name) {
		this->name = name;
	};
	void setmCity(double markCity) {
		this->markCity = markCity;
	}
	void setmStreet(double markStreet) {
		this->markStreet = markStreet;
	}
	void setmCR(double markCountRoom) {
		this->markCountRoom = markCountRoom;
	}
	void setmS(double markS) {
		this->markS = markS;
	}
	void setmType(double markType) {
		this->markType = markType;
	}
	void setmFloor(double markFloor) {
		this->markFloor = markFloor;
	}
	void setmYear(double markYear) {
		this->markYear = markYear;
	}
	void setmPrice(double markPrice) {
		this->markPrice = markPrice;
	}
	string getName() {
		return name;
	}
	string getInfo() {
		string result;
		result += to_string(markCity) + " " + to_string(markStreet) + " "
			+ to_string(markCountRoom) + " " + to_string(markS) + " "
			+ to_string(markType) + " " + to_string(markFloor) + " "
			+ to_string(markYear) + " " + to_string(markPrice);
		return result;
	}
	void getInfoInTable(int id) {
		cout << setw(1) << "|" << setw(4) << id << setw(1) << "|" <<
			setw(25) << this->name << setw(5) << "|" <<
			setw(8) << this->markCity << setw(5) << "|" <<
			setw(15) << this->markStreet << setw(12) << "|" <<
			setw(8) << this->markCountRoom << setw(5) << "|" <<
			setw(12) << this->markS << setw(11) << "|" <<
			setw(8) << this->markType << setw(5) << "|" <<
			setw(8) << this->markFloor << setw(5) << "|" <<
			setw(8) << this->markYear << setw(5) << "|" <<
			setw(8) << this->markPrice << setw(5);
	}
	void getInfoInWholeTable(int id) {
		cout << setw(112) << setfill('=') << "=" << endl;
		cout << setfill(' ');
		cout << setw(1) << "|" << setw(4) << "id" << setw(1) << "|" <<
			setw(25) << "Название услуги" << setw(5) << "|" <<
			setw(8) << "Оценка по городу" << setw(5) << "|" <<
			setw(25) << "Оценка по улице" << setw(2) << "|" <<
			setw(8) << "Оценка по количеству комнат" << setw(5) << "|" <<
			setw(20) << "Оценка по площади" << setw(3) << "|" <<
			setw(8) << "Оценка по типу" << setw(5) << "|" <<
			setw(8) << "Оценка по этажу" << setw(5) << "|" <<
			setw(8) << "Оценка по году постройки" << setw(5) << "|" <<
			setw(8) << "Оценка по цене" << setw(5) << "|" << endl;
		cout << setw(112) << setfill('=') << "=" << endl;
		cout << setfill(' ');
		this->getInfoInTable(id);
		cout << endl;
		cout << setw(112) << setfill('=') << "=" << endl;
		cout << setfill(' ');
	}
	string getmCity() {
		return to_string(this->markCity);
	}
	string getmStreet() {
		return to_string(this->markStreet);
	}
	string getmCountRoom() {
		return to_string(this->markCountRoom);
	}
	string getmS() {
		return to_string(this->markS);
	}
	string getmType() {
		return to_string(this->markType);
	}
	string getmFloor() {
		return to_string(this->markFloor);
	}
	string getmYear() {
		return to_string(this->markYear);
	}
	string getmPrice() {
		return to_string(this->markPrice);
	}
};

class Apartment {
public:
	char city[BUFF], street[BUFF], countRoom[BUFF], S[BUFF], type[BUFF], floor[BUFF], year[BUFF], price[BUFF];
	Apartment() {
		std::strncpy(this->city, "", sizeof(this->city));
		std::strncpy(this->street, "", sizeof(this->street));
		std::strncpy(this->countRoom, "", sizeof(this->countRoom));
		std::strncpy(this->S, "", sizeof(this->S));
		std::strncpy(this->type, "", sizeof(this->type));
		std::strncpy(this->floor, "", sizeof(this->floor));
		std::strncpy(this->year, "", sizeof(this->year));
		std::strncpy(this->price, "", sizeof(this->price));
	}
	void addApartment(char city[BUFF], char street[BUFF], char countRoom[BUFF], char S[BUFF], char type[BUFF], char floor[BUFF], char year[BUFF], char price[BUFF]) {
		std::strncpy(this->city, city, sizeof(this->city));
		std::strncpy(this->street, street, sizeof(this->street));
		std::strncpy(this->countRoom, countRoom, sizeof(this->countRoom));
		std::strncpy(this->S, S, sizeof(this->S));
		std::strncpy(this->type, type, sizeof(this->type));
		std::strncpy(this->floor, floor, sizeof(this->floor));
		std::strncpy(this->year, year, sizeof(this->year));
		std::strncpy(this->price, price, sizeof(this->price));
	}
	string getCity() {
		return string(city);
	};
	string getStreet() {
		return string(street);
	};
	string getCountRoom() {
		return string(countRoom);
	};
	string getS() {
		return string(S);
	};
	string getType() {
		return string(type);
	};
	string getFloor() {
		return string(floor);
	};
	string getYear() {
		return string(year);
	};
	string getPrice() {
		return string(price);
	};
	string getInfo() {
		string result;
		result += string(city) + " " + string(street) + " " + string(countRoom) + " " + string(S) + " "
			+ string(type) + " " + string(floor) + " " + string(year) + " " + string(price);
		return result;
	}

};

class ExpertException : public std::exception {
private:
	std::string m_error;
public:
	ExpertException(std::string error) :m_error(error) {}
	const char* what() const noexcept {
		return m_error.c_str();
	}
};

string beautiful(string original) {
	for (int i = 0; i < original.length(); i++) {
		if (original[i] == ' ') {
			original[i] = '_';
		}
	}
	return original;
}

class Konditersk {
private:
	char name[BUFF];
	char owner_name[BUFF];
	std::vector<Service> services;
	std::vector<Apartment> apart;
	bool isChecked = false;
	double marks[5];
public:
	Konditersk(const char owner_name[BUFF]) {
		strncpy(this->name, "", sizeof(this->name));
		strncpy(this->owner_name, owner_name, sizeof(this->owner_name));
		for (int i = 0; i < 5; i++) marks[i] = 0;
	};
	void setMarks(double marks[5]) {
		for (int i = 0; i < 5; i++) {
			this->marks[i] = marks[i];
		}
	}
	bool checkMarks(int expertMark, int marks[5]) {
		for (int i = 0; i < 5; i++) {
			if (marks[i] == expertMark) return true;
		}
		return false;
	}
	void setMarks() {
		system("cls");
		//int expertsCount = 0;
		/*while (true) {
			try
			{
				cout << "Введите количество экспертов: ";
				cin >> expertsCount;
				if (!cin.good() || expertsCount < 2 || expertsCount > 10) {
					throw ExpertException("Количество экспертов может быть от 2 до 10");
				}

				break;
			}
			catch (ExpertException& error)
			{
				cout << error.what() << endl;
				cin.clear();
				rewind(stdin);
				cout << "Попробуйте еще раз" << endl;
			}
		}*/
		char countOfExperts[BUFF] = "1";
		//itoa(expertsCount, countOfExperts, sizeof(countOfExperts));
		send(Connection, countOfExperts, sizeof(countOfExperts), NULL);
		for (int i = 0; i < 5; i++) {
			system("cls");
			int expertMarks[5];
			for (int i = 0; i < 5; i++) {
				expertMarks[i] = -1;
			}
			vector<Service>::iterator itService;
			itService = services.begin();
			for (int serviceNum = 0; serviceNum < 5; serviceNum++) {
				cout << setw(112) << setfill('=') << "=" << endl;
				cout << setfill(' ');
				cout << setw(1) << "|" << setw(4) << "id" << setw(1) << "|" <<
					setw(25) << "Название услуги" << setw(5) << "|" <<
					setw(8) << "Затраты" << setw(5) << "|" <<
					setw(25) << "Процент заинтересованных" << setw(2) << "|" <<
					setw(8) << "Прибыль" << setw(5) << "|" <<
					setw(20) << "Количество рабочих" << setw(3) << "|" << endl;
				cout << setw(112) << setfill('=') << "=" << endl;
				cout << setfill(' ');
				itService->getInfoInTable(serviceNum + 1);
				cout << endl;
				cout << setw(112) << setfill('=') << "=" << endl;
				cout << setfill(' ');
				while (true) {
					try
					{
						cout << "Введите оценку для этого сервиса: ";
						int mark;
						cin >> mark;
						if (!cin.good() || mark < 1 || mark > 10 || checkMarks(mark, expertMarks))
							throw ExpertException("Ошибка! Оценка должна быть в пределах от 1 до 10 и не повторятся");
						expertMarks[serviceNum] = mark;
						break;
					}
					catch (ExpertException & error)
					{
						cout << error.what() << endl << "Попробуйте еще раз!" << endl;
						cin.clear();
						rewind(stdin);

					}
				}
				itService++;
			}
			char sendMarksString[BUFF];
			strcpy(sendMarksString, "");
			for (int i = 0; i < 4; i++) {
				char mark[BUFF];
				itoa(expertMarks[i], mark, 10);
				strcat(sendMarksString, mark);
				strcat(sendMarksString, " ");
			}

			char mark[BUFF];
			itoa(expertMarks[4], mark, 10);
			strcat(sendMarksString, mark);
			send(Connection, sendMarksString, sizeof(sendMarksString), NULL);
		}
	}
	void addService(string service_name) {
		double markCity, markStreet, markCountRoom, markS, markType, markFloor, markYear, markPrice;
		Service temp(service_name);
		int choice;
		while (true)
		{
			try {
				cout << "\tВведите оценку по городу: "; cin >> markCity;
				if (markCity < 0 || markCity > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по улице: "; cin >> markStreet;
				if (markStreet < 0 || markStreet > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по количеству комнат: "; cin >> markCountRoom;
				if (markCountRoom < 0 || markCountRoom > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по площади квартиры: "; cin >> markS;
				if (markS < 0 || markS > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по типу дома: "; cin >> markType;
				if (markType < 0 || markType > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по этажу: "; cin >> markFloor;
				if (markFloor < 0 || markFloor > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по году постройки: "; cin >> markYear;
				if (markYear < 0 || markYear > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				cout << "\tВведите оценку по цене: "; cin >> markPrice;
				if (markPrice < 0 || markPrice > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
				temp.setmCity(markCity);
				temp.setmStreet(markStreet);
				temp.setmCR(markCountRoom);
				temp.setmS(markS);
				temp.setmType(markType);
				temp.setmFloor(markFloor);
				temp.setmYear(markYear);
				temp.setmPrice(markPrice);
				services.push_back(temp);
				break;
			}
			catch (ExpertException & expert_error)
			{
				cout << expert_error.what();
				cout << "Попробовать еще раз?\n1. Да\n0. Нет" << endl;
				while (!scanf_s("%d", &choice) || (choice < 0 || choice > 1))
				{
					rewind(stdin);
					cout << "Ошибка. Введите 1 или 0!\n";
				}
				if (choice == 0) {
					throw 1;
					cin.clear();
					rewind(stdin);
					return;
				}
			}
			catch (...) {
				term_func();
			}
			cin.clear();
			rewind(stdin);
		}
	};
	void createExpert() {
		cin.clear();
		rewind(stdin);
		int choice;
		//string city, street, countRoom, S, type, floor, year, price;
		//while (true)
		//{
		try
		{
			cout << "Введите название компании: ";
			char Expertname[BUFF], city[BUFF], street[BUFF], countRoom[BUFF], S[BUFF], type[BUFF], floor[BUFF], year[BUFF], price[BUFF];
			cin.getline(Expertname, BUFF, '\n');
			rewind(stdin);
			strncpy(this->name, beautiful(Expertname).c_str(), sizeof(this->name));
			if (strlen(this->name) < 2) throw ExpertException("Название компании слишком короткое!\n");
			cout << "Введите город\n";
			cin.getline(city, BUFF, '\n');
			cout << "Введите улицу\n";
			cin.getline(street, BUFF, '\n');
			cout << "Количество комнат\n";
			cin.getline(countRoom, BUFF, '\n');
			cout << "Общая площадь квартиры\n";
			cin.getline(S, BUFF, '\n');
			cout << "Тип дома\n";
			cin.getline(type, BUFF, '\n');
			cout << "Этаж\n";
			cin.getline(floor, BUFF, '\n');
			cout << "Год постройки\n";
			cin.getline(year, BUFF, '\n');
			cout << "Цена\n";
			cin.getline(price, BUFF, '\n');



			//break;
		}
		catch (ExpertException & expert_error)
		{
			cout << expert_error.what();
			cout << "Попробовать еще раз?\n1. Да\n0. Нет" << endl;
			while (!scanf_s("%d", &choice) || (choice < 0 || choice > 1))
			{
				rewind(stdin);
				cout << "Ошибка. Введите 1 или 0!\n";
			}
			if (choice == 0) {
				throw 1;
				cin.clear();
				rewind(stdin);
				return;
			}
		}
		catch (int) {
			throw 1;
			cin.clear();
			rewind(stdin);
			return;
		}
		catch (...) {
			term_func();
		}
		cin.clear();
		rewind(stdin);
		//}
	}
	string getInfo() {
		string infoExpert;

		infoExpert += beautiful(string(name)) + " " + string(owner_name) + " " + (isChecked ? "1" : "0") + " ";
		for (Service temp : services) {
			infoExpert += temp.getInfo() + " ";
		}
		for (int i = 0; i < 9; i++) {
			infoExpert += to_string(marks[i]) + " ";
		}
		infoExpert += to_string(marks[4]);
		return infoExpert;
	}
	void addService(const char service_name[BUFF], double mC, double mSt, double mCo, double mS, double mT, double mF, double mY, double mP) {
		Service temp(service_name);
		temp.setmCity(mC);
		temp.setmStreet(mSt);
		temp.setmCR(mCo);
		temp.setmS(mS);
		temp.setmType(mT);
		temp.setmFloor(mF);
		temp.setmYear(mY);
		temp.setmPrice(mP);
		services.push_back(temp);
	}
	void isCheckedSet(int isChecked) {
		this->isChecked = isChecked;
	}
	void setExpertname(const char name[BUFF]) {
		strncpy(this->name, name, sizeof(this->name));
	}
	string getName() {
		return string(name);
	}
	string getIsChecked() {
		return this->isChecked ? "Проверено" : "Не проверено";
	}
	string getOwnerName() {
		return string(owner_name);
	}
	string getMarks() {
		string marks;
		for (int mark = 0; mark < 4; mark++) {
			marks += to_string(this->marks[mark]) + " ";
		}
		marks += to_string(this->marks[4]);
		return marks;
	}
	void changeInfo() {
		char choice;
		cout << "1. Изменить название компании" << endl;
		cout << "2. Изменить параметры компании" << endl;
		while (true) {
			cin.clear();
			rewind(stdin);
			choice = _getch();
			if (choice == '1' || choice == '2') break;
		}
		switch (choice) {
		case('1'):
		{
			//Изменить Название компании
			while (true) {
				try
				{
					cout << "\tВведите название компании: ";
					char Expertname[BUFF];
					cin.getline(Expertname, BUFF, '\n');
					rewind(stdin);
					strncpy(this->name, beautiful(Expertname).c_str(), sizeof(this->name));
					if (strlen(this->name) < 2) throw ExpertException("\tНазвание компании слишком короткое!\n");
					break;
				}
				catch (ExpertException & error) {
					cout << error.what() << endl;
					cout << "\tПопробуйте еще раз!\nНажмите Enter..." << endl;
					cin.clear();
					rewind(stdin);
					cin.get();
				}
			}
		}
		break;
		case('2'):
		{
			//Изменить сервисы
			cout << "При изменении оценок компаний потребуется повторная проверка экспертов\n";
			vector<Service>::iterator itService;
			itService = services.begin();
			for (int i = 0; i < 5; i++, itService++) {
				cout << "\t" << i + 1 << ". " << itService->getName() << endl;
			}
			itService = services.begin();
			char choice;
			while (true) {
				cin.clear();
				rewind(stdin);
				choice = _getch();
				if (choice >= 49 && choice <= 53) break;
			}
			advance(itService, (int(choice) - 49));

			double markCity, markStreet, markCountRoom, markS, markType, markFloor, markYear, markPrice;
			while (true)
			{
				try {
					system("cls");
					itService->getInfoInWholeTable(int(choice - 48));
					cout << "\tВведите оценку по городу: "; cin >> markCity;
					if (markCity < 0 || markCity > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по улице: "; cin >> markStreet;
					if (markStreet < 0 || markStreet > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по количеству комнат: "; cin >> markCountRoom;
					if (markCountRoom < 0 || markCountRoom > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по площади квартиры: "; cin >> markS;
					if (markS < 0 || markS > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по типу дома: "; cin >> markType;
					if (markType < 0 || markType > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по этажу: "; cin >> markFloor;
					if (markFloor < 0 || markFloor > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по году постройки: "; cin >> markYear;
					if (markYear < 0 || markYear > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					cout << "\tВведите оценку по цене: "; cin >> markPrice;
					if (markPrice < 0 || markPrice > 10) throw ExpertException("Оценка не может быть меньше 0 и больше 10!");
					itService->setmCity(markCity);
					itService->setmStreet(markStreet);
					itService->setmCR(markCountRoom);
					itService->setmS(markS);
					itService->setmType(markType);
					itService->setmFloor(markFloor);
					itService->setmYear(markYear);
					itService->setmPrice(markPrice);
					break;
				}
				catch (ExpertException & expert_error)
				{
					cout << expert_error.what();
					cout << "Попробуйте еще раз!\nНажмите Enter..." << endl;
					cin.clear();
					rewind(stdin);
					cin.get();
				}
				catch (...) {
					term_func();
				}
				cin.clear();
				rewind(stdin);
			}
			this->isChecked = false;
			double defMarks[] = { 0,0,0,0,0 };
			this->setMarks(defMarks);
			system("cls");
			itService->getInfoInWholeTable(int(choice - 48));
			cout << "Нажмите Enter" << endl;
			cin.clear();
			rewind(stdin);
			cin.get();

		}
		break;
		}
	}
	void reExpert(int id) {
		if (this->marks[0] == 0) {
			cout << "Нельзя сформировать отчет для непроверенной компании!\n";
			cout << "Нажмите Enter..." << endl;
			cin.clear();
			rewind(stdin);
			cin.get();
			return;
		}
		char file_name[BUFF];
		cin.clear();
		rewind(stdin);
		while (true) {
			try {
				cout << "Введите имя файла: ";
				cin.getline(file_name, BUFF, '\n');
				rewind(stdin);
				strncpy(file_name, beautiful(file_name).c_str(), sizeof(file_name));
				if (strlen(file_name) < 2) throw ExpertException("Имя файла слишком короткое!\n");
				break;
			}
			catch (ExpertException & error) {
				cout << error.what() << endl;
				cout << "Попробуйте ещё раз!\nНажмите Enter...\n";
				cin.clear();
				rewind(stdin);
				cin.get();
			}
		}
		strcat(file_name, "_Company.txt");
		fstream outfile;
		outfile.open(file_name, ios::out);
		outfile << "\t\tОтчет по компании " + string(this->name) << endl << endl;

		outfile << "\tid: " << id << endl;
		outfile << "\tНазвание: " << this->getName() << endl;
		outfile << "\tВладелец: " << this->getOwnerName() << endl;
		outfile << "\tПроверка от эксперта: " << this->getIsChecked() << endl;
		outfile << "\tОценки: " << this->getMarks() << endl << endl << endl;

		outfile << "\t\tСервисы компании" << endl << endl;

		vector<Service>::iterator itService;
		itService = services.begin();
		int i;
		for (itService = services.begin(), i = 1; itService != services.end(); itService++, i++) {
			outfile << i << ". " + itService->getName() << endl;
			outfile << "\t" << "Оценка по городу: " << itService->getmCity() << endl;
			outfile << "\t" << "Оценка по улице: " << itService->getmStreet() << endl;
			outfile << "\t" << "Оценка по количеству комнат: " << itService->getmCountRoom() << endl;
			outfile << "\t" << "Оценка по площади: " << itService->getmS() << endl;
			outfile << "\t" << "Оценка по типу: " << itService->getmType() << endl;
			outfile << "\t" << "Оценка по этажу: " << itService->getmFloor() << endl;
			outfile << "\t" << "Оценка по году постройки: " << itService->getmYear() << endl;
			outfile << "\t" << "Оценка по цене: " << itService->getmPrice() << endl;
		}
	}
};

class Company {
private:
	char companyName[BUFF];
	Admin admin;
	std::vector<Client> clients;
	std::vector<Konditersk> experts;
	std::vector<Client>::iterator itClient;
	std::vector<Konditersk>::iterator itExpert;
	std::vector<Apartment> apart;
	std::vector<Apartment>::iterator itApart;
public:
	Company(const char companyName[BUFF]) {
		std::strncpy(this->companyName, companyName, sizeof(this->companyName));
		admin.setAutorisation("admin", "admin");
	};
	~Company() {
		clients.clear();
		experts.clear();
	}
	void sendexperts() {
		std::vector<Konditersk>::iterator it;
		int countexperts = experts.size();
		char count[BUFF];
		itoa(countexperts, count, 10);
		send(Connection, count, sizeof(count), NULL);
		for (it = experts.begin(); it != experts.end(); it++) {
			char expertInfo[BUFF];
			strncpy(expertInfo, it->getInfo().c_str(), sizeof(expertInfo));
			send(Connection, expertInfo, sizeof(expertInfo), NULL);
		}
	}
	void sendClient() {
		char countClient[BUFF];
		itoa(clients.size(), countClient, 10);
		send(Connection, countClient, sizeof(countClient), NULL);
		for (itClient = clients.begin(); itClient != clients.end(); itClient++) {
			char clientInfo[BUFF];
			strncpy(clientInfo, itClient->getInfo().c_str(), sizeof(clientInfo));
			send(Connection, clientInfo, sizeof(clientInfo), NULL);
		}
	}
	void sendApart() {
		char apartClient[BUFF];
		itoa(apart.size(), apartClient, 10);
		send(Connection, apartClient, sizeof(apartClient), NULL);
		for (itApart = apart.begin(); itApart != apart.end(); itApart++) {
			char clientInfo[BUFF];
			strncpy(clientInfo, itApart->getInfo().c_str(), sizeof(clientInfo));
			send(Connection, clientInfo, sizeof(clientInfo), NULL);
		}
	}
	void addExpert(const char Expertname[BUFF]) {
		Konditersk temp(Expertname);
		try
		{
			temp.createExpert();
		}
		catch (int)
		{
			send(Connection, "-1", sizeof("-1"), NULL);
			return;
		}
		experts.push_back(temp);
		sendexperts();
	}
	void recvClient() {
		char clientCount[BUFF];
		recv(Connection, clientCount, sizeof(clientCount), NULL);
		for (int i = 0; i < atoi(clientCount); i++) {
			char clientInfo[BUFF];
			Client temp;
			recv(Connection, clientInfo, sizeof(clientInfo), NULL);
			if (strlen(clientInfo) < 4) return;
			char login[BUFF], pass[BUFF], name[BUFF], surname[BUFF];
			strncpy(login, strtok(clientInfo, " "), sizeof(login));
			strncpy(pass, strtok(pass, " "), sizeof(pass));
			strncpy(name, strtok(name, " "), sizeof(name));
			strncpy(surname, strtok(surname, " "), sizeof(surname));
			temp.addClient(name, surname, login, pass);
			clients.push_back(temp);
		}
	}
	void recvApart() {
		char apartCount[BUFF];
		recv(Connection, apartCount, sizeof(apartCount), NULL);
		for (int i = 0; i < atoi(apartCount); i++) {
			char city[BUFF], street[BUFF], countRoom[BUFF], S[BUFF], type[BUFF], floor[BUFF], year[BUFF], price[BUFF];
			char apartInfo[BUFF];
			Apartment tmp;
			recv(Connection, apartInfo, sizeof(apartInfo), NULL);
			if (strlen(apartInfo) < 4) return;
			char login[BUFF], pass[BUFF], name[BUFF], surname[BUFF];
			strncpy(city, strtok(apartInfo, " "), sizeof(city));
			strncpy(street, strtok(NULL, " "), sizeof(street));
			strncpy(countRoom, strtok(NULL, " "), sizeof(countRoom));
			strncpy(S, strtok(NULL, " "), sizeof(S));
			strncpy(type, strtok(NULL, " "), sizeof(type));
			strncpy(floor, strtok(NULL, " "), sizeof(floor));
			strncpy(year, strtok(NULL, " "), sizeof(year));
			strncpy(price, strtok(NULL, " "), sizeof(price));
			tmp.addApartment(city, street, countRoom, S, type, floor, year, price);
			cout << city << " " << street << " " << countRoom << " " << S << " "
				<< type << " " << floor << " " << year << " " << price << endl;
			apart.push_back(tmp);
		}
	}
	//void recvExperts() {
	//	char expertCount[BUFF];
	//	recv(Connection, expertCount, sizeof(expertCount), NULL);
	//	for (int i = 0; i < atoi(expertCount); i++) {
	//		char expertInfo[BUFF];
	//		recv(Connection, expertInfo, sizeof(expertInfo), NULL);
	//		if (strlen(expertInfo) < 4) return;
	//		char Expertname[BUFF], owner_name[BUFF], isChecked[BUFF];
	//		strncpy(Expertname, strtok(expertInfo, " "), sizeof(Expertname));
	//		strncpy(owner_name, strtok(expertInfo, " "), sizeof(owner_name));
	//		strncpy(isChecked, strtok(expertInfo, " "), sizeof(isChecked));
	//		Konditersk temp(owner_name);
	//		temp.setExpertname(Expertname);
	//		for (int service = 0; service < 5; service++) {
	//			char ex[BUFF], pI[BUFF], pf[BUFF], cE[BUFF];
	//			strncpy(ex, strtok(expertInfo, "-"), sizeof(ex));
	//			strncpy(pI, strtok(expertInfo, " "), sizeof(pI));
	//			strncpy(pf, strtok(expertInfo, " "), sizeof(pf));
	//			strncpy(cE, strtok(expertInfo, " "), sizeof(cE));
	//			double expenses, perInterest, profit;
	//			int countEmployee;
	//			expenses = atoi(ex);
	//			perInterest = atoi(pI);
	//			profit = atoi(pf);
	//			countEmployee = atoi(cE);
	//			//double expenses = atoi(strtok(expertInfo, "-"));
	//			//double perInterest = atoi(strtok(NULL, " "));
	//			//double profit = atoi(strtok(NULL, " "));
	//			//int countEmployee = atoi(strtok(NULL, " "));
	//			switch (service) {
	//			case(0):
	//				temp.addService("Наличие Trade-In", expenses, perInterest, profit, countEmployee);
	//				break;
	//			case(1):
	//				temp.addService("Проведение осмотра", expenses, perInterest, profit, countEmployee);
	//				break;
	//			case(2):
	//				temp.addService("Регистрация квартиры", expenses, perInterest, profit, countEmployee);
	//				break;
	//			case(3):
	//				temp.addService("Покупка квартиры", expenses, perInterest, profit, countEmployee);
	//				break;
	//			case(4):
	//				temp.addService("Аренда квартиры", expenses, perInterest, profit, countEmployee);
	//				break;
	//			}
	//		}
	//		temp.isCheckedSet(atoi(isChecked));
	//		double marks[5];
	//		for (int i = 0; i < 5; i++) {
	//			marks[i] = atoi(strtok(expertInfo, " "));
	//		}
	//		temp.setMarks(marks);
	//		experts.push_back(temp);
	//	}
	//}



	void printClientInfo() {
		int id = 0;
		cout << setw(89) << setfill('=') << "=" << endl;
		cout << setfill(' ');
		cout << setw(1) << "|" << setw(4) << "id" << setw(4) << "|" <<
			setw(12) << "Имя" << setw(8) << "|" <<
			setw(12) << "Фамилия" << setw(8) << "|" <<
			setw(12) << "Логин" << setw(8) << "|" <<
			setw(12) << "Пароль" << setw(8) << "|" << endl;
		cout << setw(89) << setfill('=') << "=" << endl;
		cout << setfill(' ');
		for (itClient = clients.begin(); itClient != clients.end(); itClient++, id++) {
			cout << setw(1) << "|" << setw(4) << id << setw(4) << "|" <<
				setw(12) << itClient->getName() << setw(8) << "|" <<
				setw(12) << itClient->getSurname() << setw(8) << "|" <<
				setw(12) << itClient->getLogin() << setw(8) << "|" <<
				setw(12) << itClient->getPass() << setw(8) << "|" << endl;
		}
		cout << setw(89) << setfill('=') << "=" << endl;
	};
	int getClientsSize() {
		return clients.size();
	}
	int getExpertsSize() {
		return experts.size();
	}
	void delClient() {
		int id;
		while (true) {
			try
			{
				cout << "Введите ID для удаления."; cin >> id;
				if (!cin.good() || id < 0 || (id > (clients.size() - 1))) throw ExpertException("Неверный ID");
				break;
			}
			catch (ExpertException & error)
			{
				cin.clear();
				rewind(stdin);
				cout << error.what() << endl << "Попробуйте еще раз!" << endl;

			}
		}
		itClient = clients.begin();
		advance(itClient, id);
		clients.erase(itClient);
	}

	void addClient() {
		Client temp;
		char login[BUFF], pass[BUFF], name[BUFF], surname[BUFF];
		while (true) {
			try {
				system("cls");
				cout << "Введите имя пользователя: "; cin >> name;
				if (strlen(name) < 2) throw ExpertException("Имя пользователя слишком короткое!");
				for (int i = 0; i < clients.size(); i++) {
					if (strcmp(clients[i].getName().c_str(), name) == 0) {
						throw ExpertException("Пользователь с таким именем уже зарегистрирован!");
					}
				}
				cout << "Введите фамилию пользователя: "; cin >> surname;
				if (strlen(surname) < 2) throw ExpertException("Слишком короткая фамилия!");
				cout << "Введите логин пользователя: "; cin >> login;
				if (strlen(login) < 6) throw ExpertException("Слишком короткий логин!");
				cout << "Введите пароль пользователя: "; cin >> pass;
				if (strlen(pass) < 6) throw ExpertException("Слишком короткий пароль!");

				break;
			}
			catch (ExpertException & error) {
				rewind(stdin);
				cout << error.what() << endl << "Попробуйте еще раз!\nНажмите Enter...\n";
				cin.clear();
				cin.get();
			}
		}
		temp.addClient(name, surname, login, pass);
		clients.push_back(temp);
	}

	void addApartmentt() {
		Apartment temp;
		char city[BUFF], street[BUFF], countRoom[BUFF], S[BUFF], type[BUFF], floor[BUFF], year[BUFF], price[BUFF];
		while (true) {
			try {
				system("cls");
				cout << "Введите город\n";
				cin.getline(city, BUFF, '\n');
				cout << "Введите улицу\n";
				cin.getline(street, BUFF, '\n');
				cout << "Количество комнат\n";
				cin.getline(countRoom, BUFF, '\n');
				cout << "Общая площадь квартиры\n";
				cin.getline(S, BUFF, '\n');
				cout << "Тип дома\n";
				cin.getline(type, BUFF, '\n');
				cout << "Этаж\n";
				cin.getline(floor, BUFF, '\n');
				cout << "Год постройки\n";
				cin.getline(year, BUFF, '\n');
				cout << "Цена\n";
				cin.getline(price, BUFF, '\n');
				break;
			}
			catch (ExpertException & error) {
				rewind(stdin);
				cout << error.what() << endl << "Попробуйте еще раз!\nНажмите Enter...\n";
				cin.clear();
				cin.get();
			}
		}
		temp.addApartment(city, street, countRoom, S, type, floor, year, price);
		apart.push_back(temp);
	}

	void printExpertInfo() {
		int id = 0;
		cout << setw(114) << setfill('=') << "=" << endl;
		cout << setfill(' ');
		cout << setw(1) << "|" << setw(4) << "ID" << setw(4) << "|" <<
			setw(5) << "Город" << setw(5) << "|" <<
			setw(5) << "Улица" << setw(5) << "|" <<
			setw(5) << "Кол-во комнат" << setw(5) << "|" <<
			setw(5) << "Площадь" << setw(5) << "|" <<
			setw(5) << "Тип" << setw(5) << "|" <<
			setw(5) << "Этаж" << setw(5) << "|" <<
			setw(5) << "Год" << setw(5) << "|" <<
			setw(5) << "Цена" << setw(5) << "|" << endl;
		cout << setw(114) << setfill('=') << "=" << endl;
		cout << setfill(' ');
		for (itApart = apart.begin(); itApart != apart.end(); itApart++, id++) {
			cout << setw(1) << "|" << setw(4) << id << setw(5) << "|" <<
				setw(5) << itApart->getCity() << setw(5) << "|" <<
				setw(5) << itApart->getStreet() << setw(5) << "|" <<
				setw(5) << itApart->getCountRoom() << setw(5) << "|" <<
				setw(5) << itApart->getS() << setw(5) << "|" <<
				setw(5) << itApart->getType() << setw(5) << "|" <<
				setw(5) << itApart->getFloor() << setw(5) << "|" <<
				setw(5) << itApart->getYear() << setw(5) << "|" <<
				setw(5) << itApart->getPrice() << setw(5) << endl;
		}
		/*for (itExpert = experts.begin(); itExpert != experts.end(); itExpert++, id++) {
			cout << setw(1) << "|" << setw(4) << id << setw(4) << "|" <<
				setw(15) << itExpert->getName() << setw(5) << "|" <<
				setw(15) << itExpert->getOwnerName() << setw(5) << "|" <<
				setw(12) << itExpert->getIsChecked() << setw(8) << "|" <<
				setw(12) << itExpert->getMarks() << setw(33) << endl;*/
				//}
		cout << setw(114) << setfill('=') << "=" << endl;
	}
	void printExpertInfo(string owner_name) {
		int CountExpert = 0;
		for (itExpert = experts.begin(); itExpert != experts.end(); itExpert++) {
			if (itExpert->getOwnerName() == owner_name) CountExpert++;
		}
		if (CountExpert > 0) {
			int id = 0;
			cout << setw(114) << setfill('=') << "=" << endl;
			cout << setfill(' ');
			cout << setw(1) << "|" << setw(4) << "ID" << setw(4) << "|" <<
				setw(15) << "Название" << setw(5) << "|" <<
				setw(15) << "Владелец" << setw(5) << "|" <<
				setw(12) << "Проверено" << setw(8) << "|" <<
				setw(12) << "Оценки" << setw(33) << "|" << endl;
			cout << setw(114) << setfill('=') << "=" << endl;
			cout << setfill(' ');
			for (itApart = apart.begin(); itApart != apart.end(); itApart++, id++) {
				cout << setw(1) << "|" << setw(4) << id << setw(5) << "|" <<
					setw(5) << itApart->getCity() << setw(5) << "|" <<
					setw(5) << itApart->getStreet() << setw(5) << "|" <<
					setw(5) << itApart->getCountRoom() << setw(5) << "|" <<
					setw(5) << itApart->getS() << setw(5) << "|" <<
					setw(5) << itApart->getType() << setw(5) << "|" <<
					setw(5) << itApart->getFloor() << setw(5) << "|" <<
					setw(5) << itApart->getYear() << setw(5) << "|" <<
					setw(5) << itApart->getPrice() << setw(5) << endl;
			}
			/*for (itExpert = experts.begin(); itExpert != experts.end(); itExpert++, id++) {
				if (itExpert->getOwnerName() == owner_name) {
					cout << setw(1) << "|" << setw(4) << id << setw(4) << "|" <<
						setw(15) << itExpert->getName() << setw(5) << "|" <<
						setw(15) << itExpert->getOwnerName() << setw(5) << "|" <<
						setw(12) << itExpert->getIsChecked() << setw(8) << "|" <<
						setw(12) << itExpert->getMarks() << setw(33) << endl;
				}
			}*/
			cout << setw(108) << setfill('=') << "=" << endl;
		}
		else {
			cout << "Компании отсутствуют!" << endl;
		}
	}
	void setMarks() {
		int numExpert;
		double marks[5];
		while (true) {
			try
			{
				cout << "Введите ID компании: "; cin >> numExpert;
				if (!cin.good() || (numExpert < 0 || numExpert >= this->experts.size()))
					throw(ExpertException("Введите ID от 0 до " + to_string((this->experts.size() - 1))));
				break;
			}
			catch (ExpertException & error)
			{
				cout << error.what() << endl;
			}
		}
		itExpert = experts.begin();
		advance(itExpert, numExpert);
		char result[BUFF];
		itExpert->setMarks();
		system("cls");
		recv(Connection, result, sizeof(result), NULL);
		cout << result;
		//Выводим оценки и устанавливаем что expert проверен
		char mark[BUFF];
		strncpy(mark, strtok(result, " "), sizeof(mark));
		marks[0] = atof(mark);
		for (int i = 1; i < 5; i++) {
			strncpy(mark, strtok(NULL, " "), sizeof(mark));
			marks[i] = atof(mark);
		}
		itExpert->setMarks(marks);
		itExpert->isCheckedSet(1);
	}
	void delExpert() {
		int ExpertNum;
		while (true)
		{
			try {
				cout << "Введите номер компании: ";
				cin >> ExpertNum;
				if (!cin.good() || ExpertNum < 0 || ExpertNum >= experts.size())
					throw ExpertException("Номер компании должен быть в пределах от 0 до " + to_string(experts.size() - 1));
				break;
			}
			catch (ExpertException & error) {
				cout << error.what() << endl;
				cout << "Попробуйте еще раз!" << endl;
				cin.clear();
				rewind(stdin);
			}
		}
		itExpert = experts.begin();
		advance(itExpert, ExpertNum);
		experts.erase(itExpert);
	}
	void edit() {
		int ExpertNum;
		while (true)
		{
			try {
				cout << "Введите номер компании: ";
				cin >> ExpertNum;
				if (!cin.good() || ExpertNum < 0 || ExpertNum >= experts.size())
					throw ExpertException("Номер компании должен быть в пределах от 0 до " + to_string(experts.size() - 1));
				break;
			}
			catch (ExpertException & error) {
				cout << error.what() << endl;
				cout << "Попробуйте еще раз!" << endl;
				cin.clear();
				rewind(stdin);
			}
		}
		itExpert = experts.begin();
		advance(itExpert, ExpertNum);
		itExpert->changeInfo();
	}
	void createReExpert() {
		int ExpertNum;
		while (true)
		{
			try {
				cout << "Введите номер компании: ";
				cin >> ExpertNum;
				if (!cin.good() || ExpertNum < 0 || ExpertNum >= experts.size())
					throw ExpertException("Номер компании должен быть в пределах от 0 до " + to_string(experts.size() - 1));
				break;
			}
			catch (ExpertException & error) {
				cout << error.what() << endl;
				cout << "Попробуйте еще раз!" << endl;
				cin.clear();
				rewind(stdin);
			}
		}
		itExpert = experts.begin();
		advance(itExpert, ExpertNum);
		itExpert->reExpert(ExpertNum);
	}
	void createReExpert(string owner_name) {
		int ExpertNum;
		while (true)
		{
			try {
				cout << "Введите номер компании: ";
				cin >> ExpertNum;
				if (ExpertNum >= experts.size()) throw ExpertException("Компания с таким номером не найдена!");
				if (cin.good()) {
					itExpert = experts.begin();

					advance(itExpert, ExpertNum);
					if (itExpert->getOwnerName() == owner_name) {
						break;
					}
					else throw ExpertException("Компания с таким номером не найдена!");
				}
				if (!cin.good())
					throw ExpertException("Неизвестный ввод");
				break;
			}
			catch (ExpertException & error) {
				cout << error.what() << endl;
				cout << "Попробуйте еще раз!" << endl;
				cin.clear();
				rewind(stdin);
			}
		}
		itExpert = experts.begin();
		advance(itExpert, ExpertNum);
		itExpert->reExpert(ExpertNum);
	}
	////////////////////////////////////////////////////////////////////////////////
	void changeClientPass(string owner_name) {
		char pass[BUFF];
		for (itClient = clients.begin(); itClient != clients.end(); itClient++) {
			if (itClient->getName() == owner_name) {
				break;
			}
		}
		cout << "Введите новый пароль: ";
		cin.getline(pass, BUFF, '\n');
		itClient->changePass(pass);
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////

void menu(int type, char owner_name[BUFF]) {
	Company expert("");
	expert.recvClient();
	//expert.recvExperts();
	Apartment apt;
	rewind(stdin);

	system("cls");
	rewind(stdin);
	std::cin.clear();
	if (type == 1) {
		rewind(stdin);
		bool flag1 = FALSE;
		while (flag1 == FALSE) {
			system("cls");
			std::cout << "\t\t\tМеню администратора" << std::endl;
			std::cout << "1. Управление пользователями." << std::endl;
			std::cout << "2. Добавление квартиры." << std::endl;
			std::cout << "3. Просмотр добаленных квартир." << std::endl;
			std::cout << "4. Редактирование данных." << std::endl;
			std::cout << "5. Удаление данных." << std::endl;
			std::cout << "6. Сортировка данных/----------------------/Экспертные оценки." << std::endl;
			std::cout << "7. Создание отчета." << std::endl;
			std::cout << "8. Выход в меню авторизации" << std::endl;
			rewind(stdin);
			char menu_2;
			menu_2 = _getch();
			switch (menu_2) {
			case('1'):
				//Работа с пользователями
			{
				send(Connection, "2", sizeof("2"), NULL);
				rewind(stdin);
				bool flag21 = FALSE;
				while (flag21 == FALSE) {
					system("cls");
					cout << "\t\t\tУправление пользователями" << endl;
					cout << "(1) Добавление нового пользователя" << endl;
					cout << "(2) Просмотр существующих пользователей" << endl;
					cout << "(3) Удаление пользователя" << endl;
					cout << "(4) Назад" << endl;
					char client_choice;
					client_choice = _getch();
					switch (client_choice) {
					case('1'):
					{
						send(Connection, "1", sizeof("1"), NULL);
						expert.addClient();
						expert.sendClient();
					}
					break;
					case('2'):
					{

						system("cls");
						if (expert.getClientsSize() == 0) {
							cout << "Пользователи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
							rewind(stdin);
							cin.clear();
							rewind(stdin);
							cin.get();
							continue;
						}
						send(Connection, "2", sizeof("2"), NULL);
						expert.printClientInfo();
						rewind(stdin);
						cin.get();
					}
					break;
					case('3'):
					{

						system("cls");
						if (expert.getClientsSize() == 0) {
							cout << "Пользователи отсутствуют" << endl << "Нажмите Enter чтобы продолжить..." << endl;
							rewind(stdin);
							cin.clear();
							rewind(stdin);
							cin.get();
							continue;
						}
						send(Connection, "3", sizeof("3"), NULL);
						expert.printClientInfo();
						expert.delClient();
						system("cls");
						expert.printClientInfo();
						rewind(stdin);
						cin.get();
						expert.sendClient();
					}
					break;
					case('4'):
					{
						send(Connection, "4", sizeof("4"), NULL);
						rewind(stdin);
						flag21 = TRUE;
					}
					break;
					}
				}
			}
			break;
			case('2'):
				//Добавление 
			{
				send(Connection, "1", sizeof("1"), NULL);
				expert.addApartmentt();
				//expert.addExpert(owner_name);
			}
			break;
			case('3'):
				//Чтение данных
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				expert.printExpertInfo();
				cout << endl;
				cout << "Нажмите Enter чтобы продолжить" << endl;
				rewind(stdin);
				cin.clear();
				rewind(stdin);
				cin.get();
			}
			break;
			case('4'):
				//Редактирование записей
			{
				send(Connection, "5", sizeof("5"), NULL);
				system("cls");
				expert.printExpertInfo();
				expert.edit();
				system("cls");
				expert.printExpertInfo();
				expert.sendexperts();
				cout << endl;
				cout << "Нажмите Enter чтобы продолжить" << endl;
				rewind(stdin);
				cin.clear();
				rewind(stdin);
				cin.get();
			}
			break;
			case('5'):
				//Удаление записей
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				send(Connection, "6", sizeof("6"), NULL);
				expert.printExpertInfo();
				cout << endl;
				expert.delExpert();
				system("cls");
				expert.printExpertInfo();
				cin.clear();
				rewind(stdin);
				cout << "Нажмите Enter чтобы продолжить " << endl; cin.get();
				if (expert.getExpertsSize() == 0) {
					send(Connection, "-1", sizeof("-1"), NULL);
					break;
				}
				expert.sendexperts();
			}
			break;
			case('6'):
				//Выставление оценок
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				send(Connection, "3", sizeof("3"), NULL);
				expert.printExpertInfo();
				expert.setMarks();
				expert.sendexperts();
				cout << endl;
				cout << "Нажмите Enter чтобы продолжить" << endl;
				rewind(stdin);
				cin.clear();
				rewind(stdin);
				cin.get();
			}
			break;
			case('7'):
				//Формирование отчетов
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				expert.printExpertInfo();
				expert.createReExpert();

			}
			break;
			case('8'):
				//Выход к авторизации
			{
				send(Connection, "8", sizeof("8"), NULL);
				rewind(stdin);
				flag1 = TRUE;
			}
			break;
			}
		}
	}

	if (type == 2) {
		rewind(stdin);
		bool flag1 = FALSE;
		while (flag1 == FALSE) {
			system("cls");
			std::cout << "\t\t\tДобро пожаловать, " << owner_name << "!" << std::endl;
			std::cout << "1. Добавление квартиры" << std::endl;
			std::cout << "2. Просмотр существующих данных" << std::endl;
			std::cout << "3. Редактирование данных" << std::endl;
			std::cout << "4. Удаление данных" << std::endl;
			std::cout << "5. Создание отчета" << std::endl;
			std::cout << "6. Смена пароля" << std::endl;
			std::cout << "7. Выход в меню авторизации" << std::endl;
			rewind(stdin);
			char menu_2;
			menu_2 = _getch();
			switch (menu_2) {
			case('1'):
				//Добавление 
			{
				send(Connection, "1", sizeof("1"), NULL);
				expert.addExpert(owner_name);
			}
			break;
			case('2'):
				//Чтение данных
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				expert.printExpertInfo(owner_name);
				cout << endl;
				cout << "Нажмите Enter чтобы продолжить" << endl;
				rewind(stdin);
				cin.clear();
				rewind(stdin);
				cin.get();

			}
			break;
			case('3'):
				//Редактирование
			{
				send(Connection, "3", sizeof("3"), NULL);
				system("cls");
				expert.printExpertInfo();
				expert.edit();
				system("cls");
				expert.printExpertInfo();
				expert.sendexperts();
				cout << endl;
				cout << "Нажмите Enter чтобы продолжить" << endl;
				rewind(stdin);
				cin.clear();
				rewind(stdin);
				cin.get();

			}
			break;
			case('4'):
				//Удаление
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				send(Connection, "4", sizeof("4"), NULL);
				expert.printExpertInfo();
				cout << endl;
				expert.delExpert();
				system("cls");
				expert.printExpertInfo();
				cin.clear();
				rewind(stdin);
				cout << "Нажмите Enter чтобы продолжить " << endl; cin.get();
				if (expert.getExpertsSize() == 0) {
					send(Connection, "-1", sizeof("-1"), NULL);
					break;
				}
				expert.sendexperts();
			}
			break;
			case('5'):
				//Формирование отчетов
			{
				system("cls");
				if (expert.getExpertsSize() == 0) {
					cout << "Записи отсутствуют" << endl << "Нажмите Enter чтобы продолжить" << endl;
					rewind(stdin);
					cin.clear();
					rewind(stdin);
					cin.get();
					continue;
				}
				expert.printExpertInfo(owner_name);
				expert.createReExpert(owner_name);
			}
			break;
			case('6'):
				//Смена пароля
			{
				send(Connection, "6", sizeof("6"), NULL);
				system("cls");
				expert.changeClientPass(owner_name);
				cin.clear();
				rewind(stdin);
				cout << "Нажмите Enter чтобы продолжить " << endl; cin.get();
				expert.sendClient();
			}
			break;

			case('7'):
				//Выход к авторизации
			{
				send(Connection, "7", sizeof("7"), NULL);
				rewind(stdin);
				flag1 = TRUE;
			}
			break;
			}
		}
	}
}







































////////////////////////////////////////////////////////////////////////////////
void autorisation(const char companyName[BUFF]) {
	while (true) {
		system("cls");
		std::cout << "Добро пожаловать в " << companyName << "!" << std::endl;
		std::cout << "1. Вход в качестве администратора" << std::endl;
		std::cout << "2. Вход в качестве пользователя" << std::endl;
		std::cout << "3. Выход" << std::endl;
		while (true) {
			rewind(stdin);
			std::cin.clear();
			char choice;
			choice = _getch();
			switch (choice) {
			case('1'):
			{
				send(Connection, "1", sizeof("1"), NULL);
				char login[BUFF], pass[BUFF];
				system("cls");
				while (true)
				{
					rewind(stdin);
					std::cin.clear();
					std::cout << "\t\t\tАвторизация администратора" << std::endl;
					std::cout << "Введите логин: "; std::cin >> login;
					std::cout << "Введите пароль: "; std::cin >> pass;
					if (strlen(login) < 3) {
						system("cls");
						std::cout << "Ошибка! Слишком короткий логин. \nПопробуйте еще раз" << std::endl;
						continue;
					}
					if (strlen(pass) < 1) {
						system("cls");
						std::cout << "Ошибка! Слишком короткий пароль. \nПопробуйте еще раз" << std::endl;
						continue;
					}
					break;
				}
				//std::cout << "login - " << login << " pass - " << pass << std::endl;
				char answer_code[BUFF];//200 or 404
				send(Connection, login, sizeof(login), NULL);
				send(Connection, pass, sizeof(pass), NULL);
				recv(Connection, answer_code, sizeof(answer_code), NULL);
				rewind(stdin);
				//std::cout << answer_code << std:: endl;
				//std::cin.get();
				if (atoi(answer_code) == 200) {
					char owner[BUFF];
					strncpy(owner, "Admin", sizeof(owner));
					menu(1, owner);
				}
			}
			break;
			case('2'):
			{
				send(Connection, "2", sizeof("2"), NULL);
				char login[BUFF], pass[BUFF];
				system("cls");
				while (true)
				{
					rewind(stdin);
					std::cin.clear();
					std::cout << "\t\t\tАвторизация пользователя" << std::endl;
					std::cout << "Введите логин: "; std::cin >> login;
					std::cout << "Введите пароль: "; std::cin >> pass;
					if (strlen(login) < 6) {
						system("cls");
						std::cout << "Ошибка! Слишком короткий логин. \nМинимум 6 символов\nПопробуйте еще раз" << std::endl;
						continue;
					}
					if (strlen(pass) < 6) {
						system("cls");
						std::cout << "Ошибка! Слишком короткий пароль. \nМинимум 6 символов\nПопробуйте еще раз" << std::endl;
						continue;
					}
					break;
				}
				//std::cout << "login - " << login << " pass - " << pass << std::endl;
				char answer_code[BUFF];//200 or 404
				send(Connection, login, sizeof(login), NULL);
				send(Connection, pass, sizeof(pass), NULL);
				recv(Connection, answer_code, sizeof(answer_code), NULL);

				rewind(stdin);
				//std::cout << answer_code << std::endl;
				//std::cin.get();
				if (atoi(answer_code) == 200) {
					char client_name[BUFF];
					recv(Connection, client_name, sizeof(client_name), NULL);
					menu(2, client_name);
				}
			}
			break;
			case('3'):
			{
				send(Connection, "3", sizeof("3"), NULL);
				exit(0);
			}
			break;
			}
			break;
		}
	}
}

void term_func() {
	cout << "Произошла неизвестная ошибка" << endl;
	system("pause");
	exit(-1);
}

int main(int argc, char* argv[]) {
	system("chcp 1251 >> null");
	set_terminate(term_func);
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect to server.\n";
		return 1;
	}
	std::cout << "Connected!\n";



	autorisation("Компания");



	system("pause");
	return 0;
}