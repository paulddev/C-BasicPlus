#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	std::srand(std::time(0)); // rand() ������ �ʱ�ȭ

	cout << "��� ����: ���� ������ ATM\n";
	cout << "ť�� �ִ� ���̸� �Է��ϼ���: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "�ùķ��̼� �ð� ���� �Է��ϼ���: ";
	int hours;
	cin >> hours;
	// �ùķ��̼��� 1�п� 1�ֱ⸦ �����Ѵ�.
	long cyclelimit = MIN_PER_HR * hours;

	cout << "�ð��� ��� �� ���� �Է��ϼ���: ";
	double perhour;
	cin >> perhour;
	double min_per_cust; // ��� �� ���� ����(�� ����)
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;          // �� �� ������!
	long turnaways = 0; // ť�� �������� �߱��� ���� �� ��
	long customers = 0; // ť�� ���� �� �� ��
	long served = 0;    // �ùķ��̼ǿ��� �ŷ��� ó���� �� ��
	long sum_line = 0;  // ť�� ���� ����
	int wait_time = 0;  // ATM�� �� ������ ����ϴ� �ð�
	long line_wait = 0; // ������ ���� ���� ����� ���� �ð�

	// �ùķ��̼� ����
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);    // ������ �ð� ����
				line.enqueue(temp); // ť�� �� �� �߰�
			}

			// ó���� �غ� ����� üũ
			if (wait_time <= 0 && !line.isempty())
			{
				// ���� ���� �ޱ� ���� ó�� ����
				line.dequeue(temp);               
				wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}

			if (wait_time > 0)
				wait_time--;

			sum_line += line.queuecount();
		}

		if (customers > 0)
		{
			cout << "ť�� ���� �� �� ��: " << customers << endl;
			cout << "�ŷ��� ó���� �� ��: " << served << endl;
			cout << " �߱��� ���� �� ��: " << turnaways << endl;
			cout << "		��� ť�� ����: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout.setf(ios_base::showpoint);
			cout << (double)sum_line / cyclelimit << endl;
			cout << "		��� ��� �ð�: " << (double)line_wait / served << "��\n";
		}
		else
			cout << "���� �� �� �����ϴ�.\n";
		cout << "�Ϸ�!\n";
	}

	return 0;
}

// x�� �� ���� ��� �ð� ����(�� ����)
// �� �ð� ���� ���� �����ϸ� true
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}