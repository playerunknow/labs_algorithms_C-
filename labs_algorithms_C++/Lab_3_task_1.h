#pragma once


#include <iostream>
#include <vector>
#include <queue>
#include <string>


using namespace std;


class ArrayTree 
{
private:
    vector<int> tree; // Дерево зберігається у вигляді вектора

public:
    void add(int value) 
    {
        // Додає новий елемент у дерево
        tree.push_back(value);
    }

    string find_left_to_right(int value) 
    {
        // Пошук зліва направо (обхід in-order для бінарного дерева)
        for (size_t i = 0; i < tree.size(); ++i) 
        {
            if (tree[i] == value) 
            {
                return "Елемент " + to_string(value) + " знайдено на позиції " + to_string(i) + ".";
            }
        }
        return "Елемент " + to_string(value) + " не знайдено.";
    }

    string find_top_to_bottom(int value) 
    {
        // Пошук зверху вниз (обхід рівнями, breadth-first search)
        queue<int> queue;
        queue.push(0); // Починаємо з кореня дерева

        while (!queue.empty()) 
        {
            int idx = queue.front();
            queue.pop();

            if (idx < tree.size()) 
            {
                if (tree[idx] == value) 
                {
                    return "Елемент " + to_string(value) + " знайдено на позиції " + to_string(idx) + ".";
                }
                // Додаємо лівого та правого нащадка до черги
                int left_child = 2 * idx + 1;
                int right_child = 2 * idx + 2;
                queue.push(left_child);
                queue.push(right_child);
            }
        }
        return "Елемент " + to_string(value) + " не знайдено.";
    }

    string find_bottom_to_top(int value) 
    {
        // Пошук знизу вгору (обхід пост-ордер для бінарного дерева)
        for (int i = tree.size() - 1; i >= 0; --i) 
        {
            if (tree[i] == value) 
            {
                return "Елемент " + to_string(value) + " знайдено на позиції " + to_string(i) + ".";
            }
        }
        return "Елемент " + to_string(value) + " не знайдено.";
    }
};

void lab_3_task_1()
{
    ArrayTree tree;
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(6);
    tree.add(7);

    cout << tree.find_left_to_right(5) << endl;  // Пошук зліва направо
    cout << tree.find_top_to_bottom(3) << endl;  // Пошук зверху вниз
    cout << tree.find_bottom_to_top(4) << endl;  // Пошук знизу вгору

}
