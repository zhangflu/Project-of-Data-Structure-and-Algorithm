#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <vector>
using namespace std;
const int maxqueue = 10000;
enum Error_code { success, underflow, overflow };

template <class Queue_entry>
class Extended_queue {
public:
	Extended_queue();
	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry &item);
	Error_code retrieve(Queue_entry &item) const;
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);
	
	vector<Queue_entry*> whole();
	void erease(int x);
private:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};

template <class Queue_entry>
Extended_queue<Queue_entry> ::Extended_queue()
/* Post: The Queue is initialized to be empty. */
{
	count = 0;
	rear = maxqueue - 1;
	front = 0;
}
template <class Queue_entry>
bool Extended_queue<Queue_entry> ::empty() const
/* Post: Return true if the Queue is empty, otherwise return false. */
{
	return count == 0;
}
template <class Queue_entry>
Error_code Extended_queue<Queue_entry> ::append(const Queue_entry &item)
/* Post: item is added to the rear of the Queue. If the Queue is full return an
Error_code of overflow and leave the Queue unchanged. */
{
	if (count >= maxqueue) return overflow;
	count++;
	rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}
template <class Queue_entry>
Error_code Extended_queue<Queue_entry> ::serve()
/* Post: The front of the Queue is removed. If the Queue is empty return an
Error_code of underflow. */
{
	if (count <= 0) return underflow;
	count--;
	front = ((front + 1) == maxqueue) ? 0 : (front + 1);
	return success;
}
template <class Queue_entry>
Error_code Extended_queue<Queue_entry> ::retrieve(Queue_entry &item) const
/* Post: The front of the Queue retrieved to the output parameter item. If the
Queue is empty return an Error_code of underflow. */
{
	if (count <= 0) return underflow;
	item = entry[front];
	return success;
}

template <class Queue_entry>
int Extended_queue<Queue_entry> ::size() const
/* Post: Return the number of entries in the Extended_queue. */
{
	return count;
}
template <class Queue_entry>
bool Extended_queue<Queue_entry>::full() const
{
	return count == maxqueue;
}
template <class Queue_entry>
void Extended_queue<Queue_entry>::clear()
{
	count = 0;
	rear = maxqueue - 1;
	front = 0;
}
template <class Queue_entry>
Error_code Extended_queue<Queue_entry>::serve_and_retrieve(Queue_entry &item)
{
	if (count == 0) {
		return overflow;
	}
	else {
		item = entry[front];
		count--;
		front = ((front + 1) == maxqueue) ? 0 : (front + 1);
		return success;
	}
}

template <class Queue_entry>
vector<Queue_entry*> Extended_queue<Queue_entry>::whole() {
	vector<Queue_entry*> result;
	for (int i = front;;) {
		result.push_back(&entry[i]);
		if (i == rear)
			break;
		i = (i + 1 == maxqueue) ? 0 : (i + 1);
	}
	return result;
}

template <class Queue_entry>
void Extended_queue<Queue_entry>::erease(int x) {
	x = (x + front) % maxqueue;
	--count;
	if (x == front)
		front = (front + 1 == maxqueue) ? 0 : (front + 1);
	else {
		for (int i = x;;) {
			if (i == rear)
				break;
			entry[i] = entry[(i + 1 == maxqueue) ? 0 : (i + 1)];
			i = (i + 1 == maxqueue) ? 0 : (i + 1);
		}
		rear = (rear - 1 == -1) ? (maxqueue - 1) : (rear - 1);
	}
}
#endif