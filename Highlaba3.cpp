#include <iostream>
#include <string>
using namespace std;
class phone
{
public:
	phone();
	~phone();
	void get();
	void show(int time, int type);
	void sort();
private:
	class element
	{
	public:
		element *pNext;
		string name;
		string addres;
		string number;
		int timeInCity;
		int timeOtherCity;
		element() 
		{
			std::cin.ignore();
			cout << "Ф.И.О: ";
			getline(cin, name, '\n');
			cout << "Адрес: ";
			getline(cin, addres);
			cout << "Номер: ";
			getline(cin, number);
			cout << "Время внутригородских разговоров: ";
			cin >> timeInCity;
			cout << "Время междугородних разговоров: ";
			cin >> timeOtherCity;
			pNext = nullptr;
		}
	};
	int count_members;
	element *head;
};

phone::phone()
{
	count_members = 0;
	head = nullptr;
}

phone::~phone()
{
	cout << "Сработал деструктор" << endl;

	element *current;
	while (head != NULL)
	{
		current = head;
		head = head->pNext;
		delete current;
	}
	system("pause");
}
void phone::get()
{
	if (count_members)
	{
		phone::element *current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new element();
		current = current->pNext;
		count_members++;
	}
	else
	{
		head = new element();
		count_members++;
	}
}

void phone::show(int time, int type = 2)
{
	system("CLS");
	if (count_members) 
	{
		phone::element *current = head;
		if (type == 1)
		{
			while (current)
			{
				if (current->timeInCity >= time)
				{
					cout << "---------------------" << endl;
					cout << "Имя \t" << current->name << "\nАдрес \t" << current->addres << "\nНомер \t" << current->number << "\nВремя ВГ \t" << current->timeInCity << "\nВремя МГ \t" << current->timeOtherCity << endl;
				}
				current = current->pNext;
			}
		}
		else
		{
			while (current)
			{
				if (current->timeOtherCity > time)
				{
					cout << "---------------------" << endl;
					cout << "Имя \t" << current->name << "\nАдрес \t" << current->addres << "\nНомер \t" << current->number << "\nВремя ВГ \t" << current->timeInCity << "\nВремя МГ \t" << current->timeOtherCity << endl;
				}
				current = current->pNext;
			}
		}
		cout << "---------------------" << endl;
	}
	else
	{
		cout << "Список абонентов пуст" << endl;
	}
}

void phone::sort()
{
	if (count_members)
	{
		phone::element *current = head;
		phone::element *next = head->pNext;
		int noSwap;
		int iBuf;
		string buf;
		while (current)
		{
			for (int i = count_members - 1; i >= 0; i--)
			{
				current = head;
				next = current->pNext;
				noSwap = 1;
				for (int j = 0; j < i; j++)
				{
					if (current->name > next->name)
					{
						//buf = current->name;
						//current->name = next->name;
						//next->name = buf;
						swap(current->name, next->name);
						//buf = current->addres;
						//current->addres = next->addres;
						//next->addres = buf;
						swap(current->addres, next->addres);
						//buf = current->number;
						//current->number = next->number;
						//next->number = buf;
						swap(current->number, next->number);
						swap(current->timeInCity, next->timeInCity);
						swap(current->timeOtherCity, next->timeOtherCity);
						noSwap = 0;
					}
					current = current->pNext;
					next = current->pNext;
				}
				if (noSwap == 1)
					break;
			}
			current = head;
			while (current)
			{
				cout << "---------------------" << endl;
				cout << "Имя \t" << current->name << "\nАдрес \t" << current->addres << "\nНомер \t" << current->number << "\nВремя ВГ \t" << current->timeInCity << "\nВремя МГ \t" << current->timeOtherCity << endl;
				current = current->pNext;
			}
			cout << "---------------------" << endl;
		}
	}
	else
	{
		cout << "Список абонентов пуст" << endl;
	}
}

int main(void)
{
	setlocale(LC_ALL, "ru");
	int menu;
	int time;
	phone list;
	do
	{
		system("cls");
		cout << "0. Выход" << endl;
		cout << "1. Вывести Абонентов больше заданного времени" << endl;
		cout << "2. Вывести Абонентов совершавших Меж. звонки" << endl;
		cout << "3. Добавить Абонента" << endl;
		cout << "4. Сортировать по Алфавиту" << endl;
		cin >> menu;
		switch (menu)
		{
			case 1:
			{
				system("CLS");
				cout << "Введите минимальное время в минутах для вывода: ";
				cin >> time;
				list.show(time, 1);
				system("pause");
				break;
			}
			case 2:
				system("CLS");
				list.show(0);
				system("pause");
				break;
			case 3:
			{
				list.get();
				break;
			}
			case 4:
			{
				list.sort();
				system("pause");
				break;
			}
		}
	}while (menu != 0);
	system("pause");
	return 0;
}