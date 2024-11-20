#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class OrderedSet {
private:
    vector<int> elements;

public:
    // Додає елемент до множини, якщо його ще немає
    void add(int element) {
        if (!contains(element)) {
            elements.push_back(element);
            sort(elements.begin(), elements.end()); // підтримуємо впорядкованість
        }
    }

    // Видаляє елемент з множини
    void remove(int element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

    // Перевіряє, чи містить множина заданий елемент
    bool contains(int element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Повертає кількість елементів у множині
    size_t size() const {
        return elements.size();
    }

    // Повертає список елементів множини
    vector<int> to_list() const {
        return elements;
    }

    // Повертає строкове представлення множини
    string to_string() const {
        ostringstream oss;
        oss << "{";
        for (size_t i = 0; i < elements.size(); ++i) {
            oss << elements[i];
            if (i < elements.size() - 1) {
                oss << ", ";
            }
        }
        oss << "}";
        return oss.str();
    }
};

int main() {
    OrderedSet ordered_set;
    ordered_set.add(5);
    ordered_set.add(3);
    ordered_set.add(8);
    ordered_set.add(5); // Не буде додано, оскільки 5 вже є

    cout << ordered_set.to_string() << endl; // Виведе: {3, 5, 8}
    cout << boolalpha << ordered_set.contains(3) << endl; // Виведе: true
    cout << ordered_set.size() << endl; // Виведе: 3

    ordered_set.remove(3);
    cout << ordered_set.to_string() << endl; // Виведе: {5, 8}

    return 0;
}
