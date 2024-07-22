#ifndef STACK_H_
#define STACK_H_

// 스택을 어떤 특정형으로 정의하지 않고, 하나의 일반적인 Item형으로 스택을 서술하고 있다.
// 사용자가 double형의 스택이나 구조체형의 스택을 원한다면?
// typedef만 변경하고 클래스 선언과 메서드 정의는 변경하지 않아도 된다.
// 더 나아가 클래스 템플릿은 저장되는 데이터의 데이터형을 클래스 설계로부터 분리시키는 더 강력한 방법도 제공되고 있다.
typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10}; // 클래스 용어 상수
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push()는 스택이 가득차 있으면 false, 아니면 true
	bool push(const Item& item); // 스택에 항목을 추가한다.
	// pop()는 스택이 비어 있으면 false, 아니면 true
	bool pop(Item& item); // 꼭대기 항목을 꺼내 item에 넣는다.
};
#endif