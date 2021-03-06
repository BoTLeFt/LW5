// LW5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class Credit
{
private:
	std::string name;
	float sum;
	std::string type;
	int perc;
public:
	Credit() //Конструктор по умолчанию
	{
		type = name = sum = perc = 0;
	}
	Credit(std::string n, float s, std::string t, int p) //Конструктор для инициализации полей
	{
		name = n;
		sum = s;
		type = t;
		perc = p;
	}
	friend std::ostream& operator<<(std::ostream &cout, Credit &c);
	friend bool operator< (const Credit & left, const Credit & right);
};

std::ostream &operator<<(std::ostream &cout, Credit &c) //Перегрузка операции вставки в поток
{
	cout << "Name: " << c.name << " Sum: " << c.sum << " Type: " << c.type << " Perc: " << c.perc << std::endl;
	return cout;
}

bool operator< (const Credit & left, const Credit & right) //Перегрузка для сортировки по сумме
{
	return left.sum < right.sum;
}

int main()
{
	std::cout << "New vector:" << std::endl;
	std::vector<Credit> Vec(4); //Создание и инициализация первого вектора
	Vec[0] = Credit("First", 1456.4, "EUR", 15);
	Vec[1] = Credit("Second", 150000, "RUB", 10);
	Vec[2] = Credit("Third", 5435, "USD", 25);
	Vec[3] = Credit("Fourth", 750, "DNK", 12);
	for(int i=0; i<4; i++) //Вывод через перегруженную операцию
	{
		std::cout << Vec[i];
	}
	std::cout << std::endl << "First vector by iterator: " << std::endl;
	for (std::vector<Credit>::iterator it = Vec.begin(); it != Vec.end(); ++it) //Вывод через итератор
	{
		std::cout << *it;
	}
	std::vector<Credit> Vec1;
	Vec1 = Vec; //Копирование одного вектора в другой
	std::cout << std::endl << "Copy vector:" << std::endl;
	for (int i = 0; i<4; i++)
	{
		std::cout << Vec1[i];
	}
	sort(Vec1.begin(), Vec1.end()); //Сортировка вектора
	std::cout << std::endl << "Sorted vector:" << std::endl;
	for (int i = 0; i<4; i++)
	{
		std::cout << Vec1[i];
	}
	system("pause");
    return 0;
}

