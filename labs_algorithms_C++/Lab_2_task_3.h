#pragma once


#include <iostream>

class Node {
public:
    int data;       
    Node* next;     
    Node* prev;     

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;     
    Node* tail;     

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}


    void append(int data) 
    {
        Node* new_node = new Node(data);
        if (head == nullptr) 
        { 
            head = new_node;
            tail = new_node;
        }
        else 
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }


    void display() 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }


    int find_min() 
    {
        if (head == nullptr) 
        {  
            return -1;  
        }
        int min_value = head->data;
        Node* current = head->next;
        while (current) 
        {
            if (current->data < min_value) 
            {
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

    cout << "Список:" << endl;
    dll.display();

    int min_value = dll.find_min();
    cout << "Мінімальний елемент у списку: " << min_value << endl;
}
