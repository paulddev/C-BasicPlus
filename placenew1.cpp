#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;

public:
	JustTesting(const string& s = "Just Testing", int n = 0)
	{
		words = s;
		number = n;
		cout << words << " ����\n";
	}
	~JustTesting()
	{
		cout << words << " �ı�\n";
	}
	void Show() const
	{
		cout << words << ", " << number << endl;
	}
};

// ��ġ ���� new �������� ����
int main()
{
	char* buffer = new char[BUF]; // �޸� ����� ��´�.

	JustTesting *pc1, *pc2;
	
	pc1 = new (buffer) JustTesting;     // ��ü�� buffer�� ���´�.
	pc2 = new JustTesting("Heap1", 20); // ��ü�� heap�� ���´�.

	cout << "�޸� ��� �ּ�:\n" << "buffer: " << (void*)buffer << " heap: " << pc2 << endl;
	cout << "�޸� ����:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting* pc3, * pc4;

	// ������: 
	// �� ��° ��ü�� ������ ��, ��ġ ���� new�� ù ��° ��ü�� ����� �Ͱ� ������ ��ġ�� ���ο� ��ü�� �����ٴ� ��
	pc3 = new (buffer) JustTesting("Bad Idea", 6); 
	pc4 = new JustTesting("Heap2", 10);

	cout << "�޸� ����:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	// ������:
	// pc2, pc4�� delete�� ����ϴ� ����, pc2�� pc4�� �����ϴ� �� ��ü�� ���� �ı��ڸ� �ڵ����� ȣ���Ѵ�.
	// �׷��� buffer�� delete[]�� ����ϴ� ����, ��ġ ���� new�� ���� ������ ��ü���� ���� �ı��ڸ� ȣ������ �ʴ´�.
	delete pc2;
	delete pc4;
	delete[] buffer;
	cout << "����\n";
	return 0;
}