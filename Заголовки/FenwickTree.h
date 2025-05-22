#ifndef FENWICKTREE_H
#define FENWICKTREE_H

#include <vector>
#include "Node.h"

class FenwickTree {
private:
    int size;
    std::vector<Node*> nodes;

public:
    FenwickTree(std::vector<int>& values);

    void buildTree(std::vector<int>& values);
    int sumFromZero(int index);
    int sumForRange(int left, int right);
    int getValue(int index);
    void setValue(int index, int value);
    void update(int index, int value);
    void printTree();
};

#endif