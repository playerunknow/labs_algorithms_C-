#include <iostream>
#include <stack>

using namespace std;

class LinkedListWithStacks {
private:
    stack<int> left_stack;   // Ліва частина списку
    stack<int> right_stack;  // Права частина списку

public:
    void add_left(int value) {
        left_stack.push(value);
    }

    void add_right(int value) {
        right_stack.push(value);
    }

    void move_left() {
        if (!right_stack.empty()) {
            left_stack.push(right_stack.top());
            right_stack.pop();
        }
    }

    void move_right() {
        if (!left_stack.empty()) {
            right_stack.push(left_stack.top());
            left_stack.pop();
        }
    }

    int get_left() {
        return left_stack.empty() ? -1 : left_stack.top();
    }

    int get_right() {
        return right_stack.empty() ? -1 : right_stack.top();
    }

    bool is_empty() {
        return left_stack.empty() && right_stack.empty();
    }

    size_t size() {
        return left_stack.size() + right_stack.size();
    }

    int find_min() {
        int min_value = 2147483647;  // Максимальное значение для типа int

        // Проверяем все элементы в левом стеке
        stack<int> temp_left = left_stack;
        while (!temp_left.empty()) {
            if (temp_left.top() < min_value) {
                min_value = temp_left.top();
            }
            temp_left.pop();
        }

        // Проверяем все элементы в правом стеке
        stack<int> temp_right = right_stack;
        while (!temp_right.empty()) {
            if (temp_right.top() < min_value) {
                min_value = temp_right.top();
            }
            temp_right.pop();
        }

        return min_value == 2147483647 ? -1 : min_value;  // Если min_value не изменилось, возвращаем -1
    }
};


void lab_2_task_2()
{
    LinkedListWithStacks ll;
    ll.add_left(10);
    ll.add_left(5);
    ll.add_right(15);
    ll.add_right(3);

    cout << "Minimum element: " << ll.find_min() << endl;  // Виведе: Мінімальний елемент: 3

}
