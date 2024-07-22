#include <iostream>
#include "stock10.h"

int main()
{
	{
		using std::cout;
		cout << "생성자를 사용하여 새로운 객체들을 생성\n";
		
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		Stock stock2 = Stock("Boffo objects", 2, 2.0);
		stock2.show();

		cout << "stock1을 stock2에 대입\n";
		stock2 = stock1;
		stock1.show();
		stock2.show();

		cout << "생성자를 사용하여 객체를 재설정한다.\n";
		stock1 = Stock("Nifty Foods", 10, 50.7); // 임시 객체
		stock1.show();

		cout << "프로그램을 종료합니다.\n";
	}

	std::cout << "메인 프로그램 종료\n";
	return 0;
}