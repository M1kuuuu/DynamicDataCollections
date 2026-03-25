#pragma once
class DynArray
{
#include <iostream>

class DynArray
{
private:
    int* data;
    int size;
    int capacity;

public:
    DynArray()
    {
        capacity = 10;
        size = 0;
        data = new int[capacity];
    }
    
    DynArray(int initialCapacity)
    {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
    }
    
    ~DynArray()
    {
        delete[] data;
    }
    
    void Add(int value)
    {
        if (size >= capacity)
        {
            capacity = capacity * 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        
        data[size] = value;
        size++;
    }
    
    void Insert(int index, int value)
    {
        if (index < 0 || index > size)
            return;
        
        if (size >= capacity)
        {
            capacity = capacity * 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        
        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        
        data[index] = value;
        size++;
    }
    
    void RemoveAt(int index)
    {
        if (index < 0 || index >= size)
            return;
        
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        
        size--;
    }
    
    int Get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        
        return data[index];
    }
    
    void Set(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
    }
    
    bool Contains(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
                return true;
        }
        return false;
    }
    
    int Find(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
                return i;
        }
        return -1;
    }
    
    int Size()
    {
        return size;
    }
    
    int Capacity()
    {
        return capacity;
    }
    
    void Clear()
    {
        size = 0;
    }
    
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
};

