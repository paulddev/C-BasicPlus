#include <iostream>
#include "stringbad.h"
using std::cout;

void callme1(StringBad&);// reference로 전달
void callme2(StringBad); // value로 전달

// 모든 객체는 한 번 생성되고, 한 번 파괴된다.
// 생성자 호출 횟수는 파괴자 호출 횟수와 같아야 한다.
// StringBad 클래스가 일으키는 문제점들은 자동으로 정의된 특별 멤버 함수 때문에 일어난다.
/*
* 생성자를 전혀 정의하지 않았다면 디폴트 생성자
* 디폴트 파괴자를 정의하지 않았다면 디폴트 파괴자
* 복사 생성자를 정의하지 않았다면 복사 생성자
* 대입 연산자를 정의하지 않았다면 대입 연산자
* 주소 연산자를 정의하지 않았다면 주소 연산자
* 
* 여기서는 암시적 복사 생성자와 암시적 대입 연산자가 문제
* 암시적 주소 연산자는 호출한 객체(this 포인터 값)의 주소를 리턴한다.
*/
int main()
{
	using std::endl;
	{
		cout << "내부 블록을 시작\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1); // 복사 생성자 사용
		cout << "headline1: " << headline1 << endl;
		callme2(headline2); // 복사 생성자 사용
		cout << "headline2: " << headline2 << endl;

		// 문제점
		// 프로그램에서 하나의 객체를 다른 객체로 초기화하면?
		// 컴파일러는 복사 생성자라고 부르는 생성자를 자동으로 생성한다.
		// 복사 생성자는 객체의 사본을 만드는데
		// 자동으로 발생하는 복사 생성자는, static 변수를 갱신하는 것에 대해서는 알지 못한다.
		cout << "하나의 객체를 다른 객체로 초기화:\n";
		StringBad sailor = sports; // StringBad sailor = StringBad(sports);
		cout << "sailor: " << sailor << endl;

		cout << "하나의 객체를 다른 객체에 대입:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;

		cout << "블록을 빠져나오면\n";
	}
	cout << "main() 끝\n";

	// 자동 기억 공간에 저장되는 객체들은 (스택이므로),
	// 생성된 순서와 반대 순서로 파괴된다.
	// knot, sailor, sports 순
	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "참조로 전달된 StringBad:\n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "값으로 전달된 StringBad:\n";
	cout << "	\"" << sb << "\"\n";
}