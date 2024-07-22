#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	// 1 라디안 내의 각도를 계산(1 라디안에 대한 degree 값을 계산)
	const double Rad_to_deg = 45.0 / atan(1.0);
	// 반드시 약 57.2957795130823 값이 되어야 함.

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	// 극 좌표를 사용하여 x를 설정한다.
	// 극 좌표계는 평면 위의 위치를 각도와 거리를 써서 나타내는 2차원 좌표계다.
	// 극 좌표: (r, 세타) => 직교 좌표: (rcos세타, rsin세타)
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	// form이 r이면 직각 좌표로부터 벡터를 구성
	// form이 p이면 극 좌표로부터 벡터를 구성
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
			cout << "그래서 벡터를 0으로 설정하였다.\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
			cout << "그래서 벡터를 0으로 설정하였다.\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	// 극 좌표 모드로 설정한다.
	void Vector::polar_mode()
	{
		mode = POL;
	}

	// 직각 좌표 모드로 설정한다.
	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	// 프렌드 메서드들
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
		{
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		}
		else
		{
			os << "Vector 객체의 모드 지정이 틀렸습니다.\n";
		}
		return os;
	}
}