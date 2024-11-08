#pragma once
#include <iostream>
#include <string>
#include "Catalog.h"
using namespace std;
//1. Створено користувацький клас
class Client
{
//2. Три приватних поля, а решта публічні
private:
	string surname;
	string name;
	string pobatk;
public:
	void setsur(string surname)
	{
		this->surname = surname;
	}
	string getsur()
	{
		return surname;
	}

	void setname(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}

	void setpobat(string pobatk)
	{
		this->pobatk = pobatk;
	}
	string getpobat()
	{
		return pobatk;
	}

	string date_zamov;
	bool gender;
	string nomer_phone;
	int age;

	/*Client(string sur, string nam, string pob, string dat, bool gen, string nom, int ag)
	{
		surname = sur;
		name = nam;
		pobatk = pob;
		date_zamov = dat;
		gender = gen;
		nomer_phone = nom;
		age = ag;
    }

	Client(const Client& other)
	{
		surname = other.surname;
		name = other.name;
		pobatk = other.pobatk;
		date_zamov = other.date_zamov;
		gender = other.gender;
		nomer_phone = other.nomer_phone;
		age = other.age;
	}*/
	//3. Методи, які опрацьовую дані, два з яких є перевантажені
	void show_client(void);
	void audit(bool a);
	void audit(int age);
	//4. Метод для запису у файл
	void write(string sur, string nam, string pob, string dat, bool gen, string nom, int ag);
	//4. Метод для читання з файлу
	void read();
	//9. Визначити додатковий метод в класі, який виділяє випадкову величину динамічної пам’яті
	void Sort_Random(int fieldIndex);
};

