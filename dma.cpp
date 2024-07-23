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
	os << "��ǥ: " << rs.label << std::endl;
	os << "���: " << rs.rating << std::endl;
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
	os << "����: " << rs.color << std::endl;
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
	: baseDMA(hs) // ���� Ŭ���� ���� �����ڸ� ȣ���Ѵ�.
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
	// �Ļ� Ŭ������ ����� ���� �����ڴ�
	// ��ӹ��� baseDMA ���� Ŭ���� ��ü�� ���� ������ ó���� �� �־�� �Ѵ�.
	baseDMA::operator=(rs); // ���� Ŭ���� �κ��� �����Ѵ�.
	delete[] style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& rs)
{
	// hasDMA Ŭ������ �������̱� ������ style ���� ok
	// baseDMA Ŭ������ ���ؼ��� �����尡 �ƴϱ� ������ ������ �� ������
	// ���� �������� ��ȯ�� ����ؼ� ���� ��ġ�� ������ �Լ��� ȣ���ؼ� ������ �� �ִ�.
	// operator<<(ostream&, const baseDMA&)
	os << (const baseDMA&)rs;
	os << "��Ÿ��: " << rs.style << std::endl;
	return os;
}