#include <queue>
#include "WorkWithNode.h"

Node* WorkWithNode::addElement(Node* currentElem, int value) {
	if (currentElem == nullptr) return new Node(value);
	else if ((currentElem->value) < value) currentElem->right = addElement(currentElem->right, value);
	else currentElem->left = addElement(currentElem->left, value);
	return currentElem;
}
void WorkWithNode::delElement(int value) {
	if (root == nullptr) return;
	root = delNode(root, value);
}
int WorkWithNode::findMinElement(Node* currentElem) {
	if (currentElem->left == nullptr) return currentElem->value;
	return findMinElement(currentElem->left);	
}
Node* WorkWithNode::delNode(Node* currentNode, int value) {
	if (root == nullptr) return nullptr;
	if (currentNode->value == value) {
		if (currentNode->right == nullptr && currentNode->left == nullptr) {
			return nullptr;
		}
		if (currentNode->left == nullptr) return currentNode->right;
		if (currentNode->right == nullptr) return currentNode->left;

		int minElementInRightSubtree = findMinElement(currentNode->right);

		currentNode->value = minElementInRightSubtree;
		currentNode->right = delNode(currentNode->right, minElementInRightSubtree);

		return currentNode;
	}
	if (value < currentNode->value) {
		if (currentNode->left == nullptr) return currentNode;

		currentNode->left = delNode(currentNode->left, value);
		return currentNode;
	}
	if (value > currentNode->value) {
		if (currentNode->right == nullptr) return currentNode;

		currentNode->right = delNode(currentNode->right, value);
		return currentNode;
	}
}
Node* WorkWithNode::findElement(Node* currentElem, int value) {
	if (currentElem == nullptr) return nullptr;
	if (currentElem->value == value) return currentElem;
	if (value > currentElem->value) return findElement(currentElem->right, value);
	if (value < currentElem->value) return findElement(currentElem->left, value);

}
//Обход в глубину
//поперечный
void WorkWithNode::inOrder(Node* currentElem) {
	if (currentElem == nullptr) return;
	std::cout << currentElem->value << " ";
	inOrder(currentElem->left);
	inOrder(currentElem->right);
}
//Обход в ширину
void WorkWithNode::width() {
	if (root == nullptr) return;
	std::queue<Node*> queue;
	queue.push(root);

	while (!queue.empty()) {
		Node* temp = (Node*)queue.front();
		queue.pop();
		std::cout << temp->value<<" ";
		if (temp->left) queue.push(temp->left);
		if (temp->right) queue.push(temp->right);
	}
	std::cout<<"\n";
}
