#pragma once
#include <exception>
#include <iostream>

// NEVER WRITE THIS ON THE STATE EXAM
// Just for demonstration purposes - this is how you can implement a doubly linked list

// reviewed
template<typename T>
class DoublyLinkedList {
private:
	struct Node {
		T value;
		Node* prev, * next;

		Node(const T& value, Node* prev = nullptr, Node* next = nullptr)
			: value(value), prev(prev), next(next) { }
	};

	Node* head = nullptr, * tail = nullptr;
	size_t size = 0;
public:
	// missing move semantics
	DoublyLinkedList() = default;
	DoublyLinkedList(const DoublyLinkedList<T>&);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
	~DoublyLinkedList();

    void push_front(const T&);
    void push_back(const T&);
    // insertAt is probably an overkill for the state exam
    void pop_front();
    void pop_back();
    const T& front() const;
    const T& back() const;

    void remove(const T&);
    void clear(); // might be overkill for the state exam
    bool contains(const T&) const;
    bool isEmpty() const;
    size_t getSize() const;

private:
	void copyFrom(const DoublyLinkedList<T>&);
	void free();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) {
	copyFrom(other);
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	free();
}

template<typename T>
void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other) {
	Node* iter = other.head;
	while (iter) {
		push_back(iter->value);
		iter = iter->next;
	}
}

template<typename T>
void DoublyLinkedList<T>::free() {
	Node* iter = head;

	while (iter) {
		Node* next = iter->next;
		delete iter;
		iter = next;
	}

	size = 0;
	head = tail = nullptr;
}


template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
	if (!head) {
		head = tail = new Node(value);
		size = 1;
		return;
	}

	Node* newNode = new Node(value, nullptr, head);
	head->prev = newNode;
	head = newNode;
	size++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	if (!tail) {
		head = tail = new Node(value);
		size = 1;
		return;
	}

	Node* newNode = new Node(value, tail);
	tail->next = newNode;
	tail = newNode;
	size++;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* toDelete = head;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = nullptr;
	}

	delete toDelete;
	size--;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	Node* toDelete = tail;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete toDelete;
	size--;
}

template<typename T>
bool DoublyLinkedList<T>::contains(const T& value) const {
	Node* iter = head;

	while (iter) {
		if (iter->value == value) {
			return true;
		}

		iter = iter->next;
	}

	return false;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
	if (!head) {
		throw std::length_error("List is empty");
	}

	return head->value;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	return tail->value;
}

template<typename T>
size_t DoublyLinkedList<T>::getSize() const {
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
	free();
}

// claude generated
template<typename T>
void DoublyLinkedList<T>::remove(const T& element) {
	Node* iter = head;

	while (iter) {
		if (iter->value == element) {
			if (iter == head) {
				pop_front();
			} else if (iter == tail) {
				pop_back();
			} else {
				iter->prev->next = iter->next;
				iter->next->prev = iter->prev;
				delete iter;
				size--;
			}
			return;
		}
		iter = iter->next;
	}
}
