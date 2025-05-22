#include "Node.h"
#include <string>

int index;
int value;
Node parent;
Node::Node(){
    this->index = 0;
    this->value = 0;
    this->parent = nullptr;
}
Node::Node(int index, int value) {
    this->index = index;
    this->value = value;
    this->parent = nullptr;

}

std::string Node::toString(){
    
    std::string parentStr;
    if (parent != nullptr) {
        parentStr = std::to_string(parent->index);
    }
    else {
        parentStr = "null";
    }

    return "Node{index=" + std::to_string(index) +
        ", value=" + std::to_string(value) +
        ", parent=" + parentStr + "}";
}