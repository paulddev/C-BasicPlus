#include <cstring>
#include "dma.h"

baseDMA::baseDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;

	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "상표: " << rs.label << std::endl;
	os << "등급: " << rs.rating << std::endl;
	return os;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r)
	:baseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
	:baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& rs)
{
	os << (const baseDMA&)rs;
	os << "색상: " << rs.color << std::endl;
	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r)
	: baseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
	: baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: baseDMA(hs) // 기초 클래스 복사 생성자를 호출한다.
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (this == &rs)
		return *this;
	// 파생 클래스의 명시적 대입 연산자는
	// 상속받은 baseDMA 기초 클래스 객체를 위한 대입을 처리할 수 있어야 한다.
	baseDMA::operator=(rs); // 기초 클래스 부분을 복사한다.
	delete[] style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
{
	// hasDMA 클래스의 프랜드이기 때문에 style 접근 ok
	// baseDMA 클래스에 대해서는 프랜드가 아니기 때문에 접근할 수 없으나
	// 강제 데이터형 변환을 사용해서 원형 일치로 프랜드 함수를 호출해서 접근할 수 있다.
	// operator<<(ostream&, const baseDMA&)
	os << (const baseDMA&)rs;
	os << "스타일: " << rs.style << std::endl;
	return os;
}