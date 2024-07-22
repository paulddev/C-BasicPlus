#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>
class StringBad
{
private:
	char* str;
	int len;
	static int num_strings; // 생성된 객체 수를 추적하기 위한 것.

public:
	StringBad(const char* s);
	StringBad();
	~StringBad();

	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};
#endif