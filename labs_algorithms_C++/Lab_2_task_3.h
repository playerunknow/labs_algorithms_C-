#pragma once


#include <iostream>

class Node {
public:
    int data;       // Data held by the node
    Node* next;     // Pointer to the next element
    Node* prev;     // Pointer to the previous element

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;     // Start of the list
    Node* tail;     // End of the list

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add an element to the end of the list
    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {  // If the list is empty
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    // Display the list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Find the minimum element
    int find_min() {
        if (head == nullptr) {  // If the list is empty
            return -1;  // Or you could throw an exception or return some indicator
        }
        int min_value = head->data;
        Node* current = head->next;
        while (current) {
            if (current->data < min_value) {
                min_value = current->data;
            }
            current = current->next;
        }
        return min_value;
    }
};

// Example usage
void lab_2_task_3() 
{
    DoublyLinkedList dll;
    dll.append(10);
    dll.append(3);
    dll.append(15);
    dll.append(7);

    std::cout << "Список:" << std::endl;
    dll.display();

    int min_value = dll.find_min();
    std::cout << "Мінімальний елемент у списку: " << min_value << std::endl;
}
