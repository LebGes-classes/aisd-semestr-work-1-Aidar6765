#include "FenwickTree.h"
#include <iostream>

FenwickTree::FenwickTree(std::vector<int>& values) {
    this->size = values.size() + 1;
    this->nodes.resize(size);
    buildTree(values);
}



void FenwickTree::buildTree(std::vector<int>& values) {
    nodes[0] = nullptr;
    for (int i = 0; i < size - 1; i++) {
        int leftIndex = i & (i + 1);
        int value = 0;
        for (int j = leftIndex; j <= i; j++) {
            value += values[j];
        }
        nodes[i + 1] = new Node(i + 1, value);
    }

    for (int i = 1; i < size; i++) {
        int parentId = i - (i & -i);
        if (parentId < size) {
            nodes[i]->parent = nodes[parentId];
        }
    }
}

int FenwickTree::sumFromZero(int index) {
    int sum = 0;
    Node* node = nodes[index];

    while (node != nullptr) {
        sum += node->value;
        node = node->parent;
    }

    return sum;
}

int FenwickTree::sumForRange(int left, int right) {
    return sumFromZero(right) - sumFromZero(left - 1);
}

int FenwickTree::getValue(int index) {
    return nodes[index]->value;
}

void FenwickTree::setValue(int index, int value) {
    nodes[index]->value = value;
}

void FenwickTree::update(int index, int value) {
    int difference = value - getValue(index);
    while (index < size) {
        setValue(index, getValue(index) + difference);
        index = index - 1;
        index = (index | (index + 1)) + 1;
    }
}

void FenwickTree::printTree() {
    for (int i = 1; i < size; i++) {
        Node* node = nodes[i];
        std::cout << "Node " << node->index << ": value=" << node->value << ", parent=";

        if (node->parent != nullptr) {
            std::cout << node->parent->index;  
        }
        else {
            std::cout << "null";
        }

        std::cout << std::endl;
    }
}