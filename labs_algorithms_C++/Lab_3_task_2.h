#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Вузол для бінарного дерева
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Клас бінарного дерева
class BinaryTree {
private:
    Node* root;

    void insertRecursive(Node*& node, int key) {
        if (!node) {
            node = new Node(key);
            return;
        }
        if (key < node->key) {
            insertRecursive(node->left, key);
        }
        else {
            insertRecursive(node->right, key);
        }
    }

    void inorderRecursive(Node* node, vector<int>& result) const {
        if (node) {
            inorderRecursive(node->left, result);
            result.push_back(node->key);
            inorderRecursive(node->right, result);
        }
    }

    Node* searchRecursive(Node* node, int key) const {
        if (!node || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return searchRecursive(node->left, key);
        }
        return searchRecursive(node->right, key);
    }

public:
    BinaryTree(int rootKey) : root(new Node(rootKey)) {}

    void insert(int key) {
        insertRecursive(root, key);
    }

    vector<int> inorder() const {
        vector<int> result;
        inorderRecursive(root, result);
        return result;
    }

    Node* search(int key) const {
        return searchRecursive(root, key);
    }
};

// Вузол для дерева Хаффмана
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Порівняння вузлів за частотою
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Побудова дерева Хаффмана
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    for (const auto& entry : frequencies) {
        minHeap.push(new HuffmanNode(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top();
}

// Генерація кодів Хаффмана
void generateHuffmanCodes(HuffmanNode* root, const string& currentCode, unordered_map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = currentCode;
    }

    generateHuffmanCodes(root->left, currentCode + "0", codes);
    generateHuffmanCodes(root->right, currentCode + "1", codes);
}

// Кодування Хаффмана
pair<string, HuffmanNode*> huffmanEncoding(const string& data) {
    unordered_map<char, int> frequencies;
    for (char c : data) {
        frequencies[c]++;
    }

    HuffmanNode* huffmanTree = buildHuffmanTree(frequencies);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(huffmanTree, "", huffmanCodes);

    string encodedData;
    for (char c : data) {
        encodedData += huffmanCodes[c];
    }

    return { encodedData, huffmanTree };
}

// Декодування Хаффмана
string huffmanDecoding(const string& encodedData, HuffmanNode* huffmanTree) {
    string decodedData;
    HuffmanNode* node = huffmanTree;

    for (char bit : encodedData) {
        node = (bit == '0') ? node->left : node->right;

        if (!node->left && !node->right) {
            decodedData += node->ch;
            node = huffmanTree;
        }
    }

    return decodedData;
}


void lab_3_task_2() 
{
    string data = "hello huffman";
    cout << "Original data: " << data << endl;

    // Виклик функції кодування
    pair<string, HuffmanNode*> result = huffmanEncoding(data);
    string encodedData = result.first;
    HuffmanNode* huffmanTree = result.second;

    cout << "Encoded data: " << encodedData << endl;

    // Декодування
    string decodedData = huffmanDecoding(encodedData, huffmanTree);
    cout << "Decoded data: " << decodedData << endl;

}
