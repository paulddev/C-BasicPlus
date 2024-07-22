#include <cstring>
#include "stringbad.h"
using std::cout;

// static Ŭ���� ����� �ʱ�ȭ
// static ��� ������ Ŭ���� ���� �ȿ��� �ʱ�ȭ�� �� ����.
// ������ ���� �޸𸮸� ��� ���������� ���� ������ ��, ������ �޸𸮸� �������� �ʱ� ����
// static Ŭ���� ����� ��ü�� �Ϻκ����� ����Ǵ� ���� �ƴ϶� ������ ����Ǳ� ����
// �ʱ�ȭ�� Ŭ���� ���� ������ �ƴ϶� �޼��� ���� ���Ͽ� �ִ´�.
// ���α׷��� ��� ������ ���� ���Ͽ� ���Խ�ų �� �ֱ� �����̴�.
// ������, static ����� �������̰ų� �������� const��� Ŭ���� ���� ��ü���� �ʱ�ȭ�� �� �ִ�.
int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" ��ü����\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" ��ü����\n";
}

// str ����� new�� ���� ���Ե� �޸𸮸� �����Ѵ�.
// str �����Ͱ� �����ϴ� �޸𸮸� �������� ������, �� �޸𸮴� ����ؼ� ���Ե� ���¸� �����ϰ� �ȴ�.
// �����Ͱ� �����ϴ� �޸𸮴� �ڵ����� �������� �ʴ´�.
// �׷��� ������ �ı��ڿ��� ������ �޸𸮸� �������Ѿ� �Ѵ�.
StringBad::~StringBad()
{
	cout << "\"" << str << "\" ��ü�ı�, ";
	--num_strings;
	cout << "���� ��ü ��: " << num_strings << "\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}