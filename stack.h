#ifndef STACK_H_
#define STACK_H_

// ������ � Ư�������� �������� �ʰ�, �ϳ��� �Ϲ����� Item������ ������ �����ϰ� �ִ�.
// ����ڰ� double���� �����̳� ����ü���� ������ ���Ѵٸ�?
// typedef�� �����ϰ� Ŭ���� ����� �޼��� ���Ǵ� �������� �ʾƵ� �ȴ�.
// �� ���ư� Ŭ���� ���ø��� ����Ǵ� �������� ���������� Ŭ���� ����κ��� �и���Ű�� �� ������ ����� �����ǰ� �ִ�.
typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10}; // Ŭ���� ��� ���
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push()�� ������ ������ ������ false, �ƴϸ� true
	bool push(const Item& item); // ���ÿ� �׸��� �߰��Ѵ�.
	// pop()�� ������ ��� ������ false, �ƴϸ� true
	bool pop(Item& item); // ����� �׸��� ���� item�� �ִ´�.
};
#endif