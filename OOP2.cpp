// OOP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Client.h"
#include "Catalog.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>  
#endif
using namespace std; 

void Client::show_client(void)
{
	cout << surname << endl;
	cout << name << endl;
	cout << pobatk << endl;
	cout << date_zamov << endl;
}
void Client::audit(bool a)
{
	if (a == 1)
	{
		cout << "Вибирайте серед наявних чоловічу стрижку" << endl;
	}
	else
	{
		cout << "Вибирайте серед наявних жіночу стрижку" << endl;
	}
}

void Client::audit(int age)
{
	if (age < 18)
	{
		cout << "Вартість стрижки на 20% дешевша" << endl;
		
	}
	else
	{
		cout << "Вартість стрижки без знижок " << endl;
	}
}

void Client::write(string sur, string nam, string pob, string dat, bool gen, string nom, int ag)
{
	ofstream student_file("INFO.DAT", ios::app);
	student_file << sur << endl;
	student_file << nam << endl;
	student_file << pob << endl;
	student_file << dat << endl;
	student_file << gen << endl;
	student_file << nom << endl;
	student_file << ag << endl;

}

void Client::read()
{
	ifstream student_file("INFO.DAT");
	if (!student_file.is_open())
	{
		cout << "Не вдалося відкрити файл INFO.DAT" << endl;
		return;
	}
	getline(student_file, surname);
	getline(student_file, name);
	getline(student_file, pobatk);
	getline(student_file, date_zamov);
	student_file >> gender;
	getline(student_file, nomer_phone); 
	student_file >> age;
	cout << "Читання з файлу" << endl;
	cout << surname << endl;
	cout << name << endl;
	cout << pobatk << endl;
	cout << date_zamov << endl;
}

void Client::Sort_Random(int count)
{
	srand(static_cast<unsigned int>(time(nullptr))); // Ініціалізація генератора випадкових чисел
	int* ages = new int[count]; // Виділення динамічної пам'яті для масиву

	for (int i = 0; i < count; ++i)
	{
		ages[i] = rand() % 100; // Генерація віку від 0 до 99
	}

	// Сортування масиву
	sort(ages, ages + count);

	// Виведення відсортованих значень
	cout << "Відсортовані значення віку:" << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << ages[i] << " ";
	}
	cout << endl;

	// Звільнення виділеної пам'яті
	delete[] ages;
}

int main()
{
#ifdef _WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif
	//6. Масив об'єктів
	Client clients[2];
	clients[0].setsur("Petrova");
	clients[0].setname("Alina");
	clients[0].setpobat("Ivanivna");
	clients[0].date_zamov = "2024-10-22";
	clients[0].gender = false;
	clients[0].nomer_phone = "";
	clients[0].age = 29;

	clients[1].setsur("Petrova");
	clients[1].setname("Alina");
	clients[1].setpobat("Ivanivna");
	clients[1].date_zamov = "2024-10-28";
	clients[1].gender = false;
	clients[1].nomer_phone = "";
	clients[1].age = 29;

	/*clients[2].setsur("Petrova");
	clients[2].setname("Alina");
	clients[2].setpobat("Ivanivna");
	clients[2].date_zamov = "2024-10-28";
	clients[2].gender = false;
	clients[2].nomer_phone = "";
	clients[2].age = 29;*/
	//7. Робота з об'єктами масиву
	cout << "Виведення через масив" << endl;
	for (int i = 0; i < 2; i++) {
		clients[i].show_client();
		cout << "-------------------" << endl;
	}
	
	//5. П'ять об'єктів у статичній пам'яті
	Client client;
	client.setsur("Ivanov");
	client.setname("Ivan");
	client.setpobat("Ivanovich");
	client.date_zamov = "2024-10-28";
	client.gender = true;
	client.age = 29;

	Client client5;
	client5.setsur("Petrova");
	client5.setname("Alina");
	client5.setpobat("Ivanivna");
	client5.date_zamov = "2024-10-22";
	client5.gender = false;
	client5.age = 29;
	Client client6;
	client6.setsur("Petrova");
	client6.setname("Alina");
	client6.setpobat("Ivanivna");
	client6.date_zamov = "2024-10-28";
	client6.gender = false;
	client6.age = 29;
	Client client7;
	client7.setsur("Petrova");
	client7.setname("Alina");
	client7.setpobat("Ivanivna");
	client7.date_zamov = "2024-10-28";
	client7.gender = false;
	client7.age = 29;
	Client client8;
	client8.setsur("Ivanov");
	client8.setname("Ivan");
	client8.setpobat("Ivanovich");
	client8.date_zamov = "2024-10-28";
	client8.gender = true;
	client8.age = 29;
	
	//5. П'ять об'єктів у динамічні й пам'яті
	//10. Покажчик на екземпляр класу
	Client* client2 = new Client();
	client2->setsur("Ivanov");
	client2->setname("Ivan");
	client2->setpobat("Ivanovich");
	client2->date_zamov = "2024-10-28";
	client2->gender = true;
	client2->age = 29;
	Client* client3 = new Client();;
	client3->setsur("Ivanov");
	client3->setname("Ivan");
	client3->setpobat("Ivanovich");
	client3->date_zamov = "2024-10-28";
	client3->gender = true;
	client3->age = 29;
	Client* client4 = new Client();;
	client4->setsur("Ivanov");
	client4->setname("Ivan");
	client4->setpobat("Ivanovich");
	client4->date_zamov = "2024-10-28";
	client4->gender = true;
	client4->age = 29;
	Client* client9 = new Client();
	client9->setsur("Ivanov");
	client9->setname("Ivan");
	client9->setpobat("Ivanovich");
	client9->date_zamov = "2024-10-28";
	client9->gender = true;
	client9->age = 29;
	Client* client10 = new Client();
	client10->setsur("Ivanov");
	client10->setname("Ivan");
	client10->setpobat("Ivanovich");
	client10->date_zamov = "2024-10-28";
	client10->gender = true;
	client10->age = 29;

	//8. Робота усіх методів
	cout << "Виведення одного екземпляра класу" << endl;
	client.show_client();

	// Виклик методу audit(bool)
	cout << "\nПеревірка статі клієнта:" << endl;
	client.audit(client.gender);

	// Виклик методу audit(int)
	cout << "\nПеревірка віку клієнта для знижки:" << endl;
	client.audit(client.age);
	

	
	
	client2->write(client2->getsur(), client2->getname(), client2->getpobat(), client2->date_zamov, client2->gender, client2->nomer_phone, client2->age);
	client2->read();
	client2->Sort_Random(22);
	//delete[] clients;
	delete client2;
	delete client3;
	delete client4;
	delete client9;
	delete client10;
	
	//delete client1;

   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
