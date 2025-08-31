#pragma once

#include <iostream>
#include <queue>

// Not sure about this class
template<typename T>
class BinaryTree {
private:
	T data;
	BinaryTree<T>* left;
	BinaryTree<T>* right;

	void _printInOrder(BinaryTree<T>* node);
	void _printPreOrder(BinaryTree<T>* node);
	void _printPostOrder(BinaryTree<T>* node);

	bool _search(const BinaryTree<T>* node, const T& val) const;

public:

	BinaryTree(const T& value, BinaryTree<T>* left = nullptr, BinaryTree<T>* right = nullptr)
		: data(value), left(left), right(right) { }

	bool search(const T& val) const;
	// add - idea - add to the first empty spot on a level


	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void printLevelOrder();
};

template<typename T>
bool BinaryTree<T>::_search(const BinaryTree<T>* node, const T& val) const {
	if (!node) {
		return false;
	}

	if (node->data == val) {
		return true;
	}

	return _search(node->left, val) || _search(node->right, val);
}

template<typename T>
bool BinaryTree<T>::search(const T& val) const {
	return _search(this->root, val);
}

template<typename T>
void BinaryTree<T>::_printInOrder(BinaryTree<T>* node) {
	if (node == nullptr) {
		return;
	}
	_printInOrder(node->left);
	std::cout << node->data << " ";
	_printInOrder(node->right);
}

template<typename T>
void BinaryTree<T>::_printPreOrder(BinaryTree<T>* node) {
	if (node == nullptr) {
		return;
	}
	std::cout << node->data << " ";
	_printPreOrder(node->left);
	_printPreOrder(node->right);
}

template<typename T>
void BinaryTree<T>::_printPostOrder(BinaryTree<T>* node) {
	if (node == nullptr) {
		return;
	}
	_printPostOrder(node->left);
	_printPostOrder(node->right);
	std::cout << node->data << " ";
}

template<typename T>
void BinaryTree<T>::printInOrder() {
	_printInOrder(this);
}

template<typename T>
void BinaryTree<T>::printPreOrder() {
	_printPreOrder(this);
}

template<typename T>
void BinaryTree<T>::printPostOrder() {
	_printPostOrder(this);
}

template<typename T>
void BinaryTree<T>::printLevelOrder() {
	std::queue<BinaryTree<T>*> level;
	level.push(this);
	while (!level.empty()) {
		size_t levelSize = level.size();
		for (size_t i = 0; i < levelSize; ++i) {
			BinaryTree<T>* current = level.front();
			level.pop();
			std::cout << current->data << " ";
			if (current->left) {
				level.push(current->left);
			}
			if (current->right) {
				level.push(current->right);
			}
		}
	}
}

//int main() {
//	BinaryTree<int> bt(3, new BinaryTree<int>(4), new BinaryTree<int>(5));
//
//	bt.printInOrder();
//	std::cout << std::endl;
//	bt.printPreOrder();
//	std::cout << std::endl;
//	bt.printPostOrder();
//	std::cout << std::endl;
//	bt.printLevelOrder();
//	return 0;
//}
