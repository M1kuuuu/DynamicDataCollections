#pragma once
#include <iostream>

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T Value;
		Node* Next;
		Node* Prev;
	};
private:
	Node* beginList;
	Node* endList;
public:
	LinkedList()
	{
		beginList = nullptr;
		endList = nullptr;
	}

	~LinkedList()
	{
		Clear();
	}

	void Append(const T& value)
	{
		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = nullptr;
		newNode->Prev = nullptr;

		if (beginList == nullptr)
		{
			beginList = newNode;
			endList = newNode;
			return;
		}

		endList->Next = newNode;
		newNode->Prev = endList;
		endList = newNode;
	}

	void Clear()
	{
		if (beginList == nullptr)
			return;

		Node* current = beginList;
		Node* next = nullptr;

		while (current != nullptr)
		{
			next = current->Next;
			delete current;
			current = next;
		}
		beginList = nullptr;
		endList = nullptr;
	}

	void PrintToConsole()
	{
		if (beginList == nullptr)
		{
			std::cout << "list is empty" << std::endl;
			return;
		}

		Node* current = beginList;

		std::cout << "list print (forward):\n";
		while (current != nullptr)
		{
			std::cout << current->Value << "\t";
			current = current->Next;
		}
		std::cout << std::endl;

		std::cout << "list print (backward):\n";
		current = endList;
		while (current != nullptr)
		{
			std::cout << current->Value << "\t";
			current = current->Prev;
		}
		std::cout << std::endl;
	}

	void AddToBegin(const T& value)
	{
		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = beginList;
		newNode->Prev = nullptr;

		if (beginList == nullptr)
		{
			beginList = newNode;
			endList = newNode;
			return;
		}

		beginList->Prev = newNode;
		beginList = newNode;
	}

	void RemoveFromBegin()
	{
		if (beginList == nullptr)
			return;

		Node* current = beginList;
		beginList = beginList->Next;

		if (beginList != nullptr)
			beginList->Prev = nullptr;
		else
			endList = nullptr;

		delete current;
	}

	void RemoveFromEnd()
	{
		if (beginList == nullptr)
			return;

		Node* current = endList;
		endList = endList->Prev;

		if (endList != nullptr)
			endList->Next = nullptr;
		else
			beginList = nullptr;

		delete current;
	}

	void Insert(int position, const T& value)
	{
		if (position < 0)
			return;

		if (position == 0)
		{
			AddToBegin(value);
			return;
		}

		Node* current = beginList;
		int index = 0;

		while (current != nullptr && index < position)
		{
			current = current->Next;
			index++;
		}

		if (current == nullptr)
		{
			Append(value);
			return;
		}

		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = current;
		newNode->Prev = current->Prev;

		if (current->Prev != nullptr)
			current->Prev->Next = newNode;

		current->Prev = newNode;
	}

	void Remove(const T& value)
	{
		if (beginList == nullptr)
			return;

		Node* current = beginList;

		while (current != nullptr)
		{
			if (current->Value == value)
			{
				if (current->Prev != nullptr)
					current->Prev->Next = current->Next;
				else
					beginList = current->Next;

				if (current->Next != nullptr)
					current->Next->Prev = current->Prev;
				else
					endList = current->Prev;

				delete current;
				return;
			}
			current = current->Next;
		}
	}

	bool IsContain(const T& value)
	{
		if (beginList == nullptr)
			return false;

		Node* current = beginList;
		while (current != nullptr)
		{
			if (current->Value == value)
				return true;
			current = current->Next;
		}
		return false;
	}
};
