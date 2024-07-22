#include <iostream>
#include "stringbad.h"
using std::cout;

void callme1(StringBad&);// reference�� ����
void callme2(StringBad); // value�� ����

// ��� ��ü�� �� �� �����ǰ�, �� �� �ı��ȴ�.
// ������ ȣ�� Ƚ���� �ı��� ȣ�� Ƚ���� ���ƾ� �Ѵ�.
// StringBad Ŭ������ ����Ű�� ���������� �ڵ����� ���ǵ� Ư�� ��� �Լ� ������ �Ͼ��.
/*
* �����ڸ� ���� �������� �ʾҴٸ� ����Ʈ ������
* ����Ʈ �ı��ڸ� �������� �ʾҴٸ� ����Ʈ �ı���
* ���� �����ڸ� �������� �ʾҴٸ� ���� ������
* ���� �����ڸ� �������� �ʾҴٸ� ���� ������
* �ּ� �����ڸ� �������� �ʾҴٸ� �ּ� ������
* 
* ���⼭�� �Ͻ��� ���� �����ڿ� �Ͻ��� ���� �����ڰ� ����
* �Ͻ��� �ּ� �����ڴ� ȣ���� ��ü(this ������ ��)�� �ּҸ� �����Ѵ�.
*/
int main()
{
	using std::endl;
	{
		cout << "���� ����� ����\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		callme1(headline1); // ���� ������ ���
		cout << "headline1: " << headline1 << endl;
		callme2(headline2); // ���� ������ ���
		cout << "headline2: " << headline2 << endl;

		// ������
		// ���α׷����� �ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ�ϸ�?
		// �����Ϸ��� ���� �����ڶ�� �θ��� �����ڸ� �ڵ����� �����Ѵ�.
		// ���� �����ڴ� ��ü�� �纻�� ����µ�
		// �ڵ����� �߻��ϴ� ���� �����ڴ�, static ������ �����ϴ� �Ϳ� ���ؼ��� ���� ���Ѵ�.
		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ:\n";
		StringBad sailor = sports; // StringBad sailor = StringBad(sports);
		cout << "sailor: " << sailor << endl;

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;

		cout << "����� ����������\n";
	}
	cout << "main() ��\n";

	// �ڵ� ��� ������ ����Ǵ� ��ü���� (�����̹Ƿ�),
	// ������ ������ �ݴ� ������ �ı��ȴ�.
	// knot, sailor, sports ��
	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "������ ���޵� StringBad:\n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "������ ���޵� StringBad:\n";
	cout << "	\"" << sb << "\"\n";
}