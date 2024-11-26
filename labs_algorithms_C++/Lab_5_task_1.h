#pragma once

#include <iostream>
#include <string>
using namespace std;

class Node_5_3 {
public:
    string value; // Значення слова
    int weight;   // Вага слова
    Node_5_3* left;   // Лівий підвузол
    Node_5_3* right;  // Правий підвузол

    Node_5_3(const string& val) : value(val), weight(0), left(nullptr), right(nullptr) {}
};

class WeightedTree {
private:
    Node_5_3* root;

    void insertRecursive(Node_5_3* node, const string& value, int weight) {
        if (value < node->value) {
            if (node->left == nullptr) {
                node->left = new Node_5_3(value);
                node->left->weight = weight;
            }
            else {
                insertRecursive(node->left, value, weight);
            }
        }
        else if (value > node->value) {
            if (node->right == nullptr) {
                node->right = new Node_5_3(value);
                node->right->weight = weight;
            }
            else {
                insertRecursive(node->right, value, weight);
            }
        }
        else {
            // Якщо значення вже існує, оновлюємо вагу
            node->weight = weight;
        }
    }

    string findNextRecursive(Node_5_3* node, const string& value) {
        if (node == nullptr) {
            return "";
        }

        if (value < node->value) {
            string leftResult = findNextRecursive(node->left, value);
            return !leftResult.empty() ? leftResult : node->value;
        }

        return findNextRecursive(node->right, value);
    }

public:
    WeightedTree() : root(nullptr) {}

    void insert(const string& value, int weight) {
        if (root == nullptr) {
            root = new Node_5_3(value);
            root->weight = weight;
        }
        else {
            insertRecursive(root, value, weight);
        }
    }

    string findNext(const string& value) {
        return findNextRecursive(root, value);
    }
};

void lab_5_task_1()
{
    WeightedTree tree;
    tree.insert("apple", 1);
    tree.insert("banana", 2);
    tree.insert("cherry", 3);

    string nextWord = tree.findNext("apple");
    cout << "next after 'apple': " << nextWord << endl;

    nextWord = tree.findNext("banana");
    cout << "next after 'banana': " << nextWord << endl;

    nextWord = tree.findNext("cherry");
    cout << "next after 'cherry': " << nextWord << endl;
}
