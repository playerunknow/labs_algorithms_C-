#pragma once


#include <iostream>
#include <stdexcept>

class CircularQueue {
private:
    int capacity;
    int* queue;
    int front;
    int rear;

public:
    CircularQueue(int cap) : capacity(cap), front(-1), rear(-1) {
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool is_empty() {
        return front == -1;
    }

    bool is_full() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item) {
        if (is_full()) {
            throw std::runtime_error("Queue is full");
        }
        if (is_empty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = item;
    }

    int dequeue() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;  // Queue is now empty
        }
        else {
            front = (front + 1) % capacity;
        }
        return item;
    }

    int find_min() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        int min_value = queue[front];
        int index = front;
        while (true) {
            if (queue[index] < min_value) {
                min_value = queue[index];
            }
            if (index == rear) {
                break;
            }
            index = (index + 1) % capacity;
        }
        return min_value;
    }

    int remove_min() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }

        int min_value = find_min();
        int index = front;
        int min_index = -1;

        // Find index of the minimum value
        while (true) {
            if (queue[index] == min_value) {
                min_index = index;
                break;
            }
            if (index == rear) {
                break;
            }
            index = (index + 1) % capacity;
        }

        // Remove the minimum value
        for (int i = min_index; i != (rear + 1) % capacity; i = (i + 1) % capacity) {
            int next_index = (i + 1) % capacity;
            if (next_index == front) {
                break;
            }
            queue[i] = queue[next_index];
        }

        rear = (rear - 1 + capacity) % capacity; // Adjust rear
        if (rear == -1) {
            front = -1;  // Queue is now empty
        }
        return min_value;
    }
};

void lab_2_task_2() 
{
    CircularQueue cq(5);
    cq.enqueue(5);
    cq.enqueue(1);
    cq.enqueue(3);
    cq.enqueue(4);

    std::cout << "Minimum element: " << cq.find_min() << std::endl;  // Output: Minimum element: 1
    std::cout << "Removed minimum element: " << cq.remove_min() << std::endl;  // Output: Removed minimum element: 1
    std::cout << "Minimum element after removal: " << cq.find_min() << std::endl;  // Output: Minimum element after removal: 3

}
