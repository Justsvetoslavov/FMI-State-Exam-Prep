#include <string>
#include <iostream>
#include <vector>
struct Edge;
struct Node {};

struct Edge {
	Node* from;
	Node* to;
	unsigned val;
	char label;
};

#include <unordered_map>
struct Tree {
	Node* root;
	
	std::vector<Node*> nodes; // ??????
	std::unordered_map<Node*, std::vector<Edge>> nodeToEdges;
};

void dfs(
	Tree* T,
	Node* current,
	std::string labelToNow,
	size_t valueToNow,
	std::unordered_map<std::string, size_t>& result
) {
	if (!T->nodeToEdges.count(current)) {
		result[labelToNow] = valueToNow;
		return;
	}

	for (auto& adj : T->nodeToEdges[current]) {
		dfs(T, adj.to, labelToNow + adj.label, valueToNow + adj.val, result);
	}
}

std::unordered_map<std::string, size_t> getWordsAndValues(Tree* T, Node* u) {
	std::unordered_map<std::string, size_t> result;
	dfs(T, u, "", 0, result);
	return result;
}

void commonBranches(Tree* T, Node* u, Node* v, int k) {
	auto wordsU = getWordsAndValues(T, u);
	auto wordsV = getWordsAndValues(T, v);

	for (auto& kvp : wordsU) {
		auto result = wordsV.find(kvp.first);
		if (result != wordsV.end() && kvp.second + (*result).second == k) {
			std::cout << (*result).first << std::endl;
		}
	}
}

int main() {

}
