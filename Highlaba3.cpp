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
			cout << "�.�.�: ";
			getline(cin, name, '\n');
			cout << "�����: ";
			getline(cin, addres);
			cout << "�����: ";
			getline(cin, number);
			cout << "����� ��������������� ����������: ";
			cin >> timeInCity;
			cout << "����� ������������� ����������: ";
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
	cout << "�������� ����������" << endl;

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
					cout << "��� \t" << current->name << "\n����� \t" << current->addres << "\n����� \t" << current->number << "\n����� �� \t" << current->timeInCity << "\n����� �� \t" << current->timeOtherCity << endl;
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
					cout << "��� \t" << current->name << "\n����� \t" << current->addres << "\n����� \t" << current->number << "\n����� �� \t" << current->timeInCity << "\n����� �� \t" << current->timeOtherCity << endl;
				}
				current = current->pNext;
			}
		}
		cout << "---------------------" << endl;
	}
	else
	{
		cout << "������ ��������� ����" << endl;
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
				cout << "��� \t" << current->name << "\n����� \t" << current->addres << "\n����� \t" << current->number << "\n����� �� \t" << current->timeInCity << "\n����� �� \t" << current->timeOtherCity << endl;
				current = current->pNext;
			}
			cout << "---------------------" << endl;
		}
	}
	else
	{
		cout << "������ ��������� ����" << endl;
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
		cout << "0. �����" << endl;
		cout << "1. ������� ��������� ������ ��������� �������" << endl;
		cout << "2. ������� ��������� ����������� ���. ������" << endl;
		cout << "3. �������� ��������" << endl;
		cout << "4. ����������� �� ��������" << endl;
		cin >> menu;
		switch (menu)
		{
			case 1:
			{
				system("CLS");
				cout << "������� ����������� ����� � ������� ��� ������: ";
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