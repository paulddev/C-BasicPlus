#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class baseDMA
{
private:
	char* label;
	int rating;

public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

// 파생 클래스가 new를 사용하지 않는 케이스
// 파괴자가 필요없고,
// 암시적 복사 생성자 사용
// 암시적 대입 연산자 사용
class lacksDMA : public baseDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

// 파생 클래스가 new를 사용하는 케이스
// 명시적 파괴자 정의해야함.
// 명시적 복사 생성자 정의해야함.
// 명시적 대입 연산자 정의해야함.
class hasDMA : public baseDMA
{
private:
	char* style;

public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};
#endif