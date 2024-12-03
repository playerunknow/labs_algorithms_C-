#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

class BinaryVectorSet 
{
private:
    vector<int> vector;
    size_t universe_size;

public:
    // Конструктор
    BinaryVectorSet(size_t universe_size) : universe_size(universe_size), vector(universe_size, 0) {}

    // Додавання елемента
    void add(size_t element) 
    {
        if (element < universe_size) 
        {
            vector[element] = 1;
        }
        else 
        {
            throw out_of_range("The element goes beyond the universal set.");
        }
    }

    // Видалення елемента
    void remove(size_t element) 
    {
        if (element < universe_size) 
        {
            vector[element] = 0;
        }
        else 
        {
            throw out_of_range("The element goes beyond the universal set.");
        }
    }

    // Перевірка на наявність елемента
    bool contains(size_t element) const 
    {
        if (element < universe_size) 
        {
            return vector[element] == 1;
        }
        else 
        {
            throw out_of_range("The element goes beyond the universal set.");
        }
    }

    // Об'єднання множин
    BinaryVectorSet union_set(const BinaryVectorSet& other) const 
    {
        if (universe_size != other.universe_size) 
        {
            throw invalid_argument("The sizes of universal sets must be the same.");
        }
        BinaryVectorSet result(universe_size);
        for (size_t i = 0; i < universe_size; ++i) 
        {
            result.vector[i] = vector[i] | other.vector[i];
        }
        return result;
    }

    // Перетин множин
    BinaryVectorSet intersection(const BinaryVectorSet& other) const 
    {
        if (universe_size != other.universe_size) 
        {
            throw invalid_argument("The sizes of universal sets must be the same.");
        }
        BinaryVectorSet result(universe_size);
        for (size_t i = 0; i < universe_size; ++i) 
        {
            result.vector[i] = vector[i] & other.vector[i];
        }
        return result;
    }

    // Різниця множин
    BinaryVectorSet difference(const BinaryVectorSet& other) const 
    {
        if (universe_size != other.universe_size) 
        {
            throw invalid_argument("The sizes of universal sets must be the same.");
        }
        BinaryVectorSet result(universe_size);
        for (size_t i = 0; i < universe_size; ++i) 
        {
            result.vector[i] = vector[i] & ~other.vector[i];
        }
        return result;
    }

    // Рядкове представлення множини
    string to_string() const
    {
        ostringstream oss;
        oss << "{";
        bool first = true;
        for (size_t i = 0; i < universe_size; ++i) 
        {
            if (vector[i] == 1) 
            {
                if (!first) 
                {
                    oss << ", ";
                }
                oss << i;
                first = false;
            }
        }
        oss << "}";
        return oss.str();
    }
};

void lab_4_task_1() 
{
    size_t universe_size = 10; // Розмір універсальної множини
    BinaryVectorSet set1(universe_size);
    BinaryVectorSet set2(universe_size);

    set1.add(1);
    set1.add(3);
    set1.add(5);

    set2.add(3);
    set2.add(4);
    set2.add(5);

    cout << "Set 1: " << set1.to_string() << endl;
    cout << "Set 2: " << set2.to_string() << endl;

    BinaryVectorSet union_set = set1.union_set(set2);
    cout << "association: " << union_set.to_string() << endl;

    BinaryVectorSet intersection_set = set1.intersection(set2);
    cout << "intersection : " << intersection_set.to_string() << endl;

    BinaryVectorSet difference_set = set1.difference(set2);
    cout << "difference: " << difference_set.to_string() << endl;
}
