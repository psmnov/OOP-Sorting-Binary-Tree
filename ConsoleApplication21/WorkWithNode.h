#pragma once
#include <queue>
#include "Node.h" 

class WorkWithNode {
public:
    WorkWithNode() : root(NULL) {}
    WorkWithNode(Node* w_root) : root(w_root) {};
    Node* addElement(Node* currentElem, int value);
    Node* findElement(Node* currentElem, int value);
    int findMinElement(Node* currentElem);
    void delElement(int value);

    // Обход в глубину (поперечный)
    void inOrder(Node* currentElem);

    // Обход в ширину
    void width();

private:
    Node* delNode(Node* currentElem, int itemValue);
    Node* root;
};

