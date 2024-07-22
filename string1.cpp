#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

// static Ŭ���� ��� �ʱ�ȭ
int String::num_strings = 0;

// static �޼���
int String::HowMany() { return num_strings; }

// Ŭ���� �޼���
String::String(const char* s) // C ��Ÿ���� ���ڿ��κ��� String�� ����
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

// String�� String�� �����Ѵ�.
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

// C ��Ÿ���� ���ڿ��� String�� �����Ѵ�.
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}


// const�� �ƴ� String�� �б�/���� ���� ���� ���� ����
char& String::operator[](int i)
{
	return str[i];
}

// const String�� �б� ���� ���� ���� ����
const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	// ù ��° �Ű������� �� ��° �Ű��������� �տ� ���� ����
	// ������ 0
	// ù ��° �Ű������� �� ��° �Ű��������� �ڿ� ���� ���
	return (std::strcmp(st1.str, st2.str) < 0);
}

// �򰥷�...
bool operator>(const String& st1, const String& st2)
{
	// true�� �������?
	// st1 �� st2 ���� �ڿ� �־�� �Ѵ�.
	// st2 < str1 �ǹ̴�?
	// st2 �� st1 ���� �տ� �ִٴ� �ǹ�
	// -> �� st1�� st2���� ũ�� �����ڶ�� �ǹ�!
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

// �� ���� Ű���� �Է��� String ��ü�� �о���̴� ������ ����� ����
istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);

	// get(char*, int)�� ��쿡 �� ���� �д� �Ͱ� ����,
	// � ���� ������ �Է��� �������� ���, false�� �򰡵ȴ�.
	if (is)
		st = temp;

	while (is && is.get() != '\n')
		continue;
	
	return is;
}
