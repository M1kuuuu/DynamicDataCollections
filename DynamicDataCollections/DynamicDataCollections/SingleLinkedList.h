#pragma once
#include <iostream>

template <typename T>
class SingleLinkedList
{
public:
	struct Node
	{
		T Value;
		Node* Next;
	};
private:
	Node* beginList;
public:
	SingleLinkedList()
	{
		beginList = nullptr;
	}

	~SingleLinkedList()
	{
		Clear();
	}

	void Append(const T& value)
	{
		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = nullptr;

		if (beginList == nullptr)
		{
			beginList = newNode;
			return;
		}

		Node* current = beginList;
		while (current->Next != nullptr)
		{
			current = current->Next;
		}
		current->Next = newNode;
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
	}

	void PrintToConsole()
	{
		if (beginList == nullptr)
		{
			std::cout << "list is empty" << std::endl;
			return;
		}

		Node* current = beginList;

		std::cout << "list print\n";
		while (current != nullptr)
		{
			std::cout << current->Value << "\t";
			current = current->Next;
		}
		std::cout << std::endl;
	}

	void AddToBegin(const T& value)
	{
		Node* newNode = new Node();

		newNode->Value = value;
		newNode->Next = beginList;
		beginList = newNode;
	}

	void RemoveFromBegin()
	{
		if (beginList == nullptr)
			return;

		Node* current = beginList;
		beginList = beginList->Next;
		delete current;
	}

	void RemoveFromEnd()
	{
		if (beginList == nullptr)
			return;

		if (beginList->Next == nullptr)
		{
			delete beginList;
			beginList = nullptr;
			return;
		}

		Node* current = beginList;
		while (current->Next->Next != nullptr)
		{
			current = current->Next;
		}

		delete current;
		current->Next = nullptr;
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
		}
		return false;
	}
private:
};

