#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	using namespace std;

	String name;
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n";
	cin >> name;

	cout << name << " ��! ������ �츮 �Ӵ� " << ArSize << "���� �Է��� �ּ���(�������� Enter):\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; ++i)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "(������ ���� �Ӵ���� �Է��Ͽ����ϴ�.)\n";
		for (i = 0; i < total; ++i)
			cout << sayings[i] << '\n';

		// C++ ���α׷��� ��ü�� �����ϴ� �����͸� ���� ����Ѵ�.
		String* shortest = &sayings[0];
		String* first = &sayings[0];
		for (i = 1; i < total; ++i)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}

		cout << "���� ª�� �Ӵ�:\n" << *shortest << endl;
		cout << "���������� ���� �տ� ������ �Ӵ�:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;

		String* favorite = new String(sayings[choice]);
		cout << "���� ���� �����ϴ� �Ӵ�:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "�˰� �ִ� �Ӵ��� �ϳ��� �����?\n";
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}