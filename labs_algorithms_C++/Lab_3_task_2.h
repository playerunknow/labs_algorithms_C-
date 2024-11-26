#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Вузол для бінарного дерева
struct Node_3_2
{
    int key;
    Node_3_2* left;
    Node_3_2* right;

    Node_3_2(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Клас бінарного дерева
class BinaryTree
{
private:
    Node_3_2* root;

    void insertRecursive(Node_3_2*& node, int key)
    {
        if (!node)
        {
            node = new Node_3_2(key);
            return;
        }
        if (key < node->key)
        {
            insertRecursive(node->left, key);
        }
        else
        {
            insertRecursive(node->right, key);
        }
    }

    void inorderRecursive(Node_3_2* node, vector<int>& result) const
    {
        if (node)
        {
            inorderRecursive(node->left, result);
            result.push_back(node->key);
            inorderRecursive(node->right, result);
        }
    }

    Node_3_2* searchRecursive(Node_3_2* node, int key) const
    {
        if (!node || node->key == key)
        {
            return node;
        }
        if (key < node->key)
        {
            return searchRecursive(node->left, key);
        }
        return searchRecursive(node->right, key);
    }

public:
    BinaryTree(int rootKey) : root(new Node_3_2(rootKey)) {}

    void insert(int key)
    {
        insertRecursive(root, key);
    }

    vector<int> inorder() const
    {
        vector<int> result;
        inorderRecursive(root, result);
        return result;
    }

    Node_3_2* search(int key) const
    {
        return searchRecursive(root, key);
    }
};

// Вузол для дерева Хаффмана
struct HuffmanNode_3_2
{
    char ch;
    int freq;
    HuffmanNode_3_2* left;
    HuffmanNode_3_2* right;

    HuffmanNode_3_2(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Порівняння вузлів за частотою
struct Compare {
    bool operator()(HuffmanNode_3_2* a, HuffmanNode_3_2* b)
    {
        return a->freq > b->freq;
    }
};

// Побудова дерева Хаффмана
HuffmanNode_3_2* buildHuffmanTree(const unordered_map<char, int>& frequencies)
{
    priority_queue<HuffmanNode_3_2*, vector<HuffmanNode_3_2*>, Compare> minHeap;

    for (const auto& entry : frequencies)
    {
        minHeap.push(new HuffmanNode_3_2(entry.first, entry.second));
    }

    while (minHeap.size() > 1)
    {
        HuffmanNode_3_2* left = minHeap.top(); minHeap.pop();
        HuffmanNode_3_2* right = minHeap.top(); minHeap.pop();

        HuffmanNode_3_2* merged = new HuffmanNode_3_2('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top();
}

// Генерація кодів Хаффмана
void generateHuffmanCodes(HuffmanNode_3_2* root, const string& currentCode, unordered_map<char, string>& codes)
{
    if (!root) return;

    if (!root->left && !root->right)
    {
        codes[root->ch] = currentCode;
    }

    generateHuffmanCodes(root->left, currentCode + "0", codes);
    generateHuffmanCodes(root->right, currentCode + "1", codes);
}

// Кодування Хаффмана
pair<string, HuffmanNode_3_2*> huffmanEncoding(const string& data)
{
    unordered_map<char, int> frequencies;
    for (char c : data)
    {
        frequencies[c]++;
    }

    HuffmanNode_3_2* huffmanTree = buildHuffmanTree(frequencies);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(huffmanTree, "", huffmanCodes);

    string encodedData;
    for (char c : data)
    {
        encodedData += huffmanCodes[c];
    }

    return { encodedData, huffmanTree };
}

// Декодування Хаффмана
string huffmanDecoding(const string& encodedData, HuffmanNode_3_2* huffmanTree)
{
    string decodedData;
    HuffmanNode_3_2* node = huffmanTree;

    for (char bit : encodedData) {
        node = (bit == '0') ? node->left : node->right;

        if (!node->left && !node->right)
        {
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
    pair<string, HuffmanNode_3_2*> result = huffmanEncoding(data);
    string encodedData = result.first;
    HuffmanNode_3_2* huffmanTree = result.second;

    cout << "Encoded data: " << encodedData << endl;

    // Декодування
    string decodedData = huffmanDecoding(encodedData, huffmanTree);
    cout << "Decoded data: " << decodedData << endl;
}
