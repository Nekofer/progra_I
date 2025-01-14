#pragma once
#include "Position.h"

class Stack
{
private:
	Positio* base;
	int top;
	int size;
	int length;

public:
	Stack(int capacity)
	{
		base = new Positio[capacity];
		size = capacity;
		top = -1;
		length = 0;
	}

	~Stack()
	{
		delete[]base;
		top = -1;
		size = 0;
		length = 0;
	}

	int Push(Positio elem)
	{
		if (top == size - 1) return 1;   //Full stack. Unsuccessful with return value 1
		else
		{
			top++;
			base[top] = elem;
			length++;
			return 0;   //Successful with return value 0
		}
	}

	Positio Pop()
	{
		Positio error;
		error.x = -1;
		error.y = -1;

		Positio correct;

		if (top == -1) return error;   //Empty stack. Return a non-existent position
		else
		{
			correct = base[top];
			top--;
			length--;
			return correct;   //Successful with a correct position
		}
	}

	int GetLength()
	{
		return length;
	}
};

