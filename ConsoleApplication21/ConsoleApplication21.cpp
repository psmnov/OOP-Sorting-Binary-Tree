#include "WorkWithNode.h"
#include "Node.h"

#include <iostream>

int main()
{
    Node* root = new Node(2);
    WorkWithNode tree(root);
    tree.addElement(root, 2);
    tree.addElement(root, 4);

    Node* root2 = new Node(3);
    WorkWithNode tree2 = WorkWithNode(root2);
    tree2.addElement(root2, 5);
    tree2.addElement(root2, 2);
    tree2.addElement(root2, 7);
    tree.inOrder(root);
    std::cout << "\n";
    tree2.inOrder(root2);
    tree2.delElement(2);
    tree2.delElement(5);
    std::cout << "\n";
    tree2.inOrder(root2);
    std::cout << "\n";
    Node* found = tree2.findElement(root2, 7);
    bool a = found->value == 7;
    std::cout << a;
    return 0;
}


