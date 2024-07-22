#include "queue.h"
#include <cstdlib> // rand()

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL; // or nullptr
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;

	Node* add = new Node;
	// 실패하면, new는 std::bad_alloc exception 발생
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL) // 큐가 비어있다면 머리에 넣고
		front = add;
	else
		rear->next = add; // 꼬리에 넣는다.

	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (isempty())
		return false;

	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
