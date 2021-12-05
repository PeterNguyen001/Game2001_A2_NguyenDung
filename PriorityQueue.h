#pragma once

#include "LinkedList.h"

template<class T>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	// Priority Queue Functions
	void push(int p, T val)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push_Back(p, val);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Front();
				
			while (it.isValid())
			{
				if (it.GetPriority() > p)
				{
					
					break;
				}
				it++;
			}
			if (it.isValid())
			{
				m_elements.Insert_Before(p, it, val);
			}
				if (!it.isValid())
			{
				m_elements.Push_Back(p, val);
			}
		}
	}

	void pop()
	{
		m_elements.Pop_Front();
	}

	T& front()
	{
		return m_elements.Front();

	}
	T& back()
	{
		return m_elements.Last();
	}

	// Helper functions
	int GetSize()
	{
		return m_elements.GetSize();
	}

	int GetMaxSize()
	{
		return m_size;
	}

	int GetPriority()
	{
		LinkIterator<T> it;
		it = m_elements.Front();
		return it.GetPriority();
	}

	int GetData()
	{
		LinkIterator<T> it;
		it = m_elements.Front();
		return it.GetData();
	}

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}

private:
	LinkedList<T> m_elements; // Priority Queue Linked List
	int m_size;
};