#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

// static 클래스 멤버 초기화
int String::num_strings = 0;

// static 메서드
int String::HowMany() { return num_strings; }

// 클래스 메서드
String::String(const char* s) // C 스타일의 문자열로부터 String을 생성
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

// String을 String에 대입한다.
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;

	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// C 스타일의 문자열을 String에 대입한다.
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}


// const가 아닌 String에 읽기/쓰기 개별 문자 접근 가능
char& String::operator[](int i)
{
	return str[i];
}

// const String에 읽기 전용 개별 문자 접근
const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	// 첫 번째 매개변수가 두 번째 매개변수보다 앞에 오면 음수
	// 같으면 0
	// 첫 번째 매개변수가 두 번째 매개변수보다 뒤에 오면 양수
	return (std::strcmp(st1.str, st2.str) < 0);
}

// 헷갈려...
bool operator>(const String& st1, const String& st2)
{
	// true를 만들려면?
	// st1 이 st2 보다 뒤에 있어야 한다.
	// st2 < str1 의미는?
	// st2 가 st1 보다 앞에 있다는 의미
	// -> 즉 st1은 st2보다 크게 만들자라는 의미!
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

// 한 줄의 키보드 입력을 String 객체에 읽어들이는 간단한 방법을 제공
istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);

	// get(char*, int)의 경우에 빈 줄을 읽는 것과 같은,
	// 어떤 이유 때문에 입력이 실패했을 경우, false로 평가된다.
	if (is)
		st = temp;

	while (is && is.get() != '\n')
		continue;
	
	return is;
}
