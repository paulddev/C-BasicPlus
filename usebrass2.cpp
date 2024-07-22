#include <iostream>
#include <string>
#include "brass.h"
const int CLIMITS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass* p_clients[CLIMITS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIMITS; ++i)
	{
		cout << "���� �̸��� �Է��ϼ���: ";
		getline(cin, temp);
		cout << "���� ���� ��ȣ�� �Է��ϼ���: ";
		cin >> tempnum;
		cout << "���� ���� �ܾ��� �Է��ϼ���: $";
		cin >> tempbal;
		cout << "Brass ���´� 1, BrassPlus ���´� 2�� �Է��ϼ���: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1 �ƴϸ� 2, �� �� �ϳ��� �Է��ϼ���: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "���� ��� �ѵ��� �Է��ϼ���: $";
			cin >> tmax;
			cout << "���� ��� �������� �Ҽ��� �������� �Է��ϼ���: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}

		while (cin.get() != '\n')
			continue;
	}
	cout << endl;

	for (int i = 0; i < CLIMITS; ++i)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIMITS; ++i)
	{
		delete p_clients[i];
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}