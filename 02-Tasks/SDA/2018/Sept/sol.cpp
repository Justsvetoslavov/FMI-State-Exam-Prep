#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct Node {
	int value;
	Node* next;
	Node* skip;
};

Node* readList(const char* fileName) {
	// chislata sa razdeleni s intervali
	std::ifstream is(fileName);
	
	int numbers[1000] = {};
	int n = 0;
	while (is) {
		is >> numbers[n++];
	}

	is.close();

	if (n == 0) {
		return nullptr;
	}

	double k1 = sqrt(n);
	int k = std::ceil(k1);

	Node* head = new Node{numbers[0], nullptr, nullptr};
	Node* prev = head;
	Node* prevSkip = head;

	for (size_t i = 1; i < n; i++) {
		Node* newNode = new Node{ numbers[i], nullptr, nullptr };
		prev->next = newNode;
		prev = newNode;
		if (i % k == 0) {
			prevSkip->skip = newNode;
			prevSkip = newNode;
		}
	}
}

bool member(const Node* list, int value) {
	const Node* iter = list;
	while (iter) {
		if (iter->value == value) {
			return true;
		}
		if (iter->value > value) {
			return false;
		}

		// iter->value < value
		if (iter->skip && iter->skip->value <= value) {
			iter = iter->skip;
		}
		else {
			iter = iter->next;
		}
	}

	return false;
}


int main() {

}
