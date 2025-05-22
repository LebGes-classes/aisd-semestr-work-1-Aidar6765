#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    int index;
    int value;
    Node* parent;

    Node(); 
    Node(int index, int value);
    std::string toString();
};

#endif