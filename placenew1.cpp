#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;

public:
	JustTesting(const string& s = "Just Testing", int n = 0)
	{
		words = s;
		number = n;
		cout << words << " 생성\n";
	}
	~JustTesting()
	{
		cout << words << " 파괴\n";
	}
	void Show() const
	{
		cout << words << ", " << number << endl;
	}
};

// 위치 지정 new 문제점이 존재
int main()
{
	char* buffer = new char[BUF]; // 메모리 블록을 얻는다.

	JustTesting *pc1, *pc2;
	
	pc1 = new (buffer) JustTesting;     // 객체를 buffer에 놓는다.
	pc2 = new JustTesting("Heap1", 20); // 객체를 heap에 놓는다.

	cout << "메모리 블록 주소:\n" << "buffer: " << (void*)buffer << " heap: " << pc2 << endl;
	cout << "메모리 내용:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting* pc3, * pc4;

	// 문제점: 
	// 두 번째 객체를 생성할 때, 위치 지정 new는 첫 번째 객체에 사용한 것과 동일한 위치를 새로운 객체로 덮어씌운다는 점
	pc3 = new (buffer) JustTesting("Bad Idea", 6); 
	pc4 = new JustTesting("Heap2", 10);

	cout << "메모리 내용:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	// 문제점:
	// pc2, pc4에 delete를 사용하는 것은, pc2와 pc4가 지시하는 두 객체를 위한 파괴자를 자동으로 호출한다.
	// 그런데 buffer에 delete[]를 사용하는 것은, 위치 지정 new에 의해 생성된 객체들을 위한 파괴자를 호출하지 않는다.
	delete pc2;
	delete pc4;
	delete[] buffer;
	cout << "종료\n";
	return 0;
}