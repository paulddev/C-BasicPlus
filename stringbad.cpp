#include <cstring>
#include "stringbad.h"
using std::cout;

// static 클래스 멤버를 초기화
// static 멤버 변수를 클래스 선언 안에서 초기화할 수 없다.
// 선언은 단지 메모리를 어떻게 대입할지에 대한 서술일 뿐, 실제로 메모리를 대입하지 않기 때문
// static 클래스 멤버가 객체의 일부분으로 저장되는 것이 아니라 별도로 저장되기 때문
// 초기화는 클래스 선언 파일이 아니라 메서드 구현 파일에 넣는다.
// 프로그램은 헤더 파일을 여러 파일에 포함시킬 수 있기 때문이다.
// 하지만, static 멤버가 정수형이거나 열거형의 const라면 클래스 선언 자체에서 초기화할 수 있다.
int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 객체생성\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 객체생성\n";
}

// str 멤버는 new에 의해 대입된 메모리를 지시한다.
// str 포인터가 지시하는 메모리를 해제하지 않으면, 그 메모리는 계속해서 대입된 상태를 유지하게 된다.
// 포인터가 지시하는 메모리는 자동으로 해제하지 않는다.
// 그렇기 때문에 파괴자에서 대입한 메모리를 해제시켜야 한다.
StringBad::~StringBad()
{
	cout << "\"" << str << "\" 객체파괴, ";
	--num_strings;
	cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}