#pragma once
#include <iostream>

class String
{
public:
    struct Node
    {
        char Value;
        Node* Next;
    };

private:
    Node* BeginList;

public:
    String()
    {
        BeginList = nullptr;
    }
    
    String(const char* str)
    {
        BeginList = nullptr;
        for (int i = 0; str[i] != '\0'; i++)
        {
            Add(str[i]);
        }
    }
    
    ~String()
    {
        Clear();
    }
    
    void Add(char ch)
    {
        Node* newNode = new Node();
        newNode->Value = ch;
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
    
    void Insert(int index, char ch)
    {
        if (index < 0)
            return;
        
        Node* newNode = new Node();
        newNode->Value = ch;
        
        if (index == 0)
        {
            newNode->Next = BeginList;
            BeginList = newNode;
            return;
        }
        
        Node* current = BeginList;
        int i = 0;
        while (current != nullptr && i < index - 1)
        {
            current = current->Next;
            i++;
        }
        
        if (current != nullptr)
        {
            newNode->Next = current->Next;
            current->Next = newNode;
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
    
    char Get(int index)
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
        return '\0';
    }
    
    int Length()
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
            std::cout << current->Value;
            current = current->Next;
        }
        std::cout << std::endl;
    }
};
