#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	cout << "Priority queue using link list test" << endl << endl;

	const int SIZE = 7;
	PriorityQueue<int> que(SIZE);

	que.push(3, 100);
	que.push(2, 286);
	que.push(1, 362);
	que.push(3, 435);
	que.push(1, 186);
	que.push(2, 248);
	que.push(4, 569);

	// Display the priority queue
	cout << "Priority queue content (Size - " << que.GetSize() << ") : " << endl;

	while (que.isEmpty() == false)
	{
		cout << "  Priority: " << que.GetPriority();
		cout << "  Data: " << que.GetData();
		cout << endl;
		que.pop();
	}

	cout << endl;

	if (que.isEmpty() == true)
	{
		cout << "The container is empty." << endl;
	}
	else
	{
		cout << "The container is NOT empty." << endl;
	}

	return 0;
}