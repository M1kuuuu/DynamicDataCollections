#pragma once
#include <iostream>
#include <cstring>

class Dictionary
{
public:
    struct Node
    {
        char Key[255];
        char Value[255];
        Node* Next;
    };

private:
    Node* BeginList;

public:
    Dictionary()
    {
        BeginList = nullptr;
    }
    
    ~Dictionary()
    {
        Clear();
    }
    
    void Add(const char* key, const char* value)
    {
        Node* newNode = new Node();
        strcpy(newNode->Key, key);
        strcpy(newNode->Value, value);
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
    
    const char* Get(const char* key)
    {
        Node* current = BeginList;
        while (current != nullptr)
        {
            if (strcmp(current->Key, key) == 0)
            {
                return current->Value;
            }
            current = current->Next;
        }
        return nullptr;
    }
    
    bool Remove(const char* key)
    {
        if (BeginList == nullptr)
            return false;
        
        if (strcmp(BeginList->Key, key) == 0)
        {
            Node* temp = BeginList;
            BeginList = BeginList->Next;
            delete temp;
            return true;
        }
        
        Node* current = BeginList;
        while (current->Next != nullptr)
        {
            if (strcmp(current->Next->Key, key) == 0)
            {
                Node* temp = current->Next;
                current->Next = current->Next->Next;
                delete temp;
                return true;
            }
            current = current->Next;
        }
        return false;
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
            std::cout << current->Key << " : " << current->Value << std::endl;
            current = current->Next;
        }
    }
};

