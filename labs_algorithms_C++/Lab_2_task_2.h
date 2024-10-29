#pragma once


#include <iostream>
#include <stdexcept>
#include <stack>


#include <iostream>
#include <vector>
#include <limits>

class Stack {
private:
    vector<int> stack;

public:
    void push(int item) 
    {
        stack.push_back(item);
    }

    int pop()
    {
        if (!is_empty()) 
        {
            int item = stack.back();
            stack.pop_back();
            return item;
        }
        else {
            return -1;
        }
    }

    int peek() 
    {
        return is_empty() ? -1 : stack.back();
    }

    bool is_empty()
    {
        return stack.empty();
    }

    int size() 
    {
        return stack.size();
    }

    const vector<int>& get_stack() const 
    {
        return stack;
    }
};

class LinkedListWithStacks 
{
private:
    Stack left_stack;
    Stack right_stack;

public:
    void add_left(int value)
    {
        left_stack.push(value);
    }

    void add_right(int value) 
    {
        right_stack.push(value);
    }

    void move_left() 
    {
        if (!right_stack.is_empty())
        {
            left_stack.push(right_stack.pop());
        }
    }

    void move_right() 
    {
        if (!left_stack.is_empty())
        {
            right_stack.push(left_stack.pop());
        }
    }

    int get_left() 
    {
        return left_stack.peek();
    }

    int get_right() 
    {
        return right_stack.peek();
    }

    bool is_empty() 
    {
        return left_stack.is_empty() && right_stack.is_empty();
    }

    int size()
    {
        return left_stack.size() + right_stack.size();
    }

    int find_min()
    {
        int min_value = numeric_limits<int>::max();

        for (int value : left_stack.get_stack()) 
        {
            if (value < min_value) 
            {
                min_value = value;
            }
        }

        for (int value : right_stack.get_stack())
        {
            if (value < min_value)
            {
                min_value = value;
            }
        }

        return min_value == numeric_limits<int>::max() ? -1 : min_value;
    }
};

void lab_2_task_2() {

    LinkedListWithStacks ll;
    ll.add_left(10);
    ll.add_left(5);
    ll.add_right(15);
    ll.add_right(3);

    cout << "Мінімальний елемент: " << ll.find_min() << endl; // Выведет: Мінімальний елемент: 3
}
