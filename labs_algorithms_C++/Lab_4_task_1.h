#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

class BitSet {
private:
    int max_size; // Максимальний розмір множини
    unsigned int set; // Бітовий вектор

public:
    // Конструктор
    BitSet(int maxSize) : max_size(maxSize), set(0) {}

    // Додавання елемента
    void add(int element) {
        if (element >= 0 && element < max_size) {
            set |= (1 << element);
        }
        else {
            throw invalid_argument("Element " + to_string(element) + " is out of bounds.");
        }
    }

    // Видалення елемента
    void remove(int element) {
        if (element >= 0 && element < max_size) {
            set &= ~(1 << element);
        }
        else {
            throw invalid_argument("Element " + to_string(element) + " is out of bounds.");
        }
    }

    // Перевірка наявності елемента
    bool contains(int element) const {
        if (element >= 0 && element < max_size) {
            return (set & (1 << element)) != 0;
        }
        else {
            throw invalid_argument("Element " + to_string(element) + " is out of bounds.");
        }
    }

    // Об'єднання множин
    BitSet unionSet(const BitSet& other) const {
        if (max_size != other.max_size) {
            throw invalid_argument("Sets must have the same max size.");
        }
        BitSet result(max_size);
        result.set = set | other.set;
        return result;
    }

    // Перетин множин
    BitSet intersection(const BitSet& other) const {
        if (max_size != other.max_size) {
            throw invalid_argument("Sets must have the same max size.");
        }
        BitSet result(max_size);
        result.set = set & other.set;
        return result;
    }

    // Різниця множин
    BitSet difference(const BitSet& other) const {
        if (max_size != other.max_size) {
            throw invalid_argument("Sets must have the same max size.");
        }
        BitSet result(max_size);
        result.set = set & ~other.set;
        return result;
    }

    // Перетворення в строку
    string toString() const {
        stringstream ss;
        ss << "{";
        bool first = true;
        for (int i = 0; i < max_size; ++i) {
            if (contains(i)) {
                if (!first) {
                    ss << ", ";
                }
                ss << i;
                first = false;
            }
        }
        ss << "}";
        return ss.str();
    }
};

int main() {
    BitSet bitSet1(10);
    BitSet bitSet2(10);

    bitSet1.add(1);
    bitSet1.add(3);
    bitSet1.add(5);

    bitSet2.add(3);
    bitSet2.add(4);
    bitSet2.add(5);

    cout << "Множина 1: " << bitSet1.toString() << endl;
    cout << "Множина 2: " << bitSet2.toString() << endl;

    BitSet unionSet = bitSet1.unionSet(bitSet2);
    cout << "Об'єднання: " << unionSet.toString() << endl;

    BitSet intersectionSet = bitSet1.intersection(bitSet2);
    cout << "Перетин: " << intersectionSet.toString() << endl;

    BitSet differenceSet = bitSet1.difference(bitSet2);
    cout << "Різниця: " << differenceSet.toString() << endl;

    return 0;
}
