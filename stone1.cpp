#include <iostream>
#include "stonewt1.h"

int main()
{
	using std::cout;
	Stonewt poppins(9, 2.8);
	double p_wt = poppins; // �Ͻ��� ��ȯ
	cout << "double������ ��ȯ�ϸ� -> ";
	cout << "poppins: " << p_wt << "�Ŀ��\n";
	cout << "int������ ��ȯ�ϸ� -> ";
	cout << "poppins: " << int(poppins) << "�Ŀ��\n";
	return 0;
}