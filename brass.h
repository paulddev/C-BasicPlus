#ifndef BRASS_H_
#define BRASS_H_
#include <string>
class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;

public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const; // 가상 함수(가상 메서드)
	virtual ~Brass() {}
};

// Brass::ViewAcct()
// BrassPlus::ViewAcct()
// 호출한 객체가 어떤 클래스형이냐에 따라 어느 버전을 사용할 것인지를 결정
// Withdraw도 동일

// Deposit(), Balance()
// 두 클래스에 대해 똑같이 행동하는 메서드들은 기초 클래스에 단 한 번만 선언된다.

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;

public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double m1 = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double m1 = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif