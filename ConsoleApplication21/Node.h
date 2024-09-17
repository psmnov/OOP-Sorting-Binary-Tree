#pragma once
#include <iostream>
class Node {
public:
    int value;
    Node* right;
    Node* left;

    Node(int val = 0, Node* r = NULL, Node* l = NULL) : value(val), right(r), left(l) {}
};

