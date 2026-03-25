#pragma once
#include <iostream>

class List
{
public:
    struct Node
    {
        int Value;
        Node* Next;
    };

private:
    Node* BeginList;

public:
    List()
    {
        BeginList = nullptr;
    }
    
    ~List()
    {
        Clear();
    }
    
    void Add(int value)
    {
        Node* newNode = new Node();
        newNode->Value = value;
        newNode->Next = nullptr;
        
        if (BeginList == nullptr)
        {
            BeginList = newNode;
            return;
        }
        
        Node* current = BeginList;
        while (current->Next != nullptr)
        {
            current = current->Next;
        }
        current->Next = newNode;
    }
    
    void Remove(int value)
    {
        if (BeginList == nullptr)
            return;
        
        if (BeginList->Value == value)
        {
            Node* temp = BeginList;
            BeginList = BeginList->Next;
            delete temp;
            return;
        }
        
        Node* current = BeginList;
        while (current->Next != nullptr)
        {
            if (current->Next->Value == value)
            {
                Node* temp = current->Next;
                current->Next = current->Next->Next;
                delete temp;
                return;
            }
            current = current->Next;
        }
    }
    
    void RemoveAt(int index)
    {
        if (BeginList == nullptr || index < 0)
            return;
        
        if (index == 0)
        {
            Node* temp = BeginList;
            BeginList = BeginList->Next;
            delete temp;
            return;
        }
        
        Node* current = BeginList;
        int i = 0;
        while (current->Next != nullptr && i < index - 1)
        {
            current = current->Next;
            i++;
        }
        
        if (current->Next != nullptr)
        {
            Node* temp = current->Next;
            current->Next = current->Next->Next;
            delete temp;
        }
    }
    
    int Get(int index)
    {
        Node* current = BeginList;
        int i = 0;
        while (current != nullptr)
        {
            if (i == index)
                return current->Value;
            current = current->Next;
            i++;
        }
        return -1;
    }
    
    bool Contains(int value)
    {
        Node* current = BeginList;
        while (current != nullptr)
        {
            if (current->Value == value)
                return true;
            current = current->Next;
        }
        return false;
    }
    
    int Size()
    {
        int count = 0;
        Node* current = BeginList;
        while (current != nullptr)
        {
            count++;
            current = current->Next;
        }
        return count;
    }
    
    void Clear()
    {
        Node* current = BeginList;
        while (current != nullptr)
        {
            Node* next = current->Next;
            delete current;
            current = next;
        }
        BeginList = nullptr;
    }
    
    void Print()
    {
        Node* current = BeginList;
        while (current != nullptr)
        {
            std::cout << current->Value << " ";
            current = current->Next;
        }
        std::cout << std::endl;
    }
};

