#include <iostream>
#include "stock10.h"

int main()
{
	{
		using std::cout;
		cout << "�����ڸ� ����Ͽ� ���ο� ��ü���� ����\n";
		
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo objects", 2, 2.0);
		stock2.show();

		cout << "stock1�� stock2�� ����\n";
		stock2 = stock1;
		stock1.show();
		stock2.show();

		cout << "�����ڸ� ����Ͽ� ��ü�� �缳���Ѵ�.\n";
		stock1 = Stock("Nifty Foods", 10, 50.7); // �ӽ� ��ü
		stock1.show();

		cout << "���α׷��� �����մϴ�.\n";
	}

	std::cout << "���� ���α׷� ����\n";
	return 0;
}