
struct Node {
	char text;
	Node* left, * right;
};

bool hasNextLevel(const std::vector<const Node*>& level) {
	for (size_t i = 0; i < level.size(); i++) {
		if (!level[i]) {
			continue;
		}

		if (level[i]->left || level[i]->right) {
			return true;
		}
	}

	return false;
}

void printText(const Node* node) {
	std::queue<const Node*> q;
	q.push(node);

	while (!q.empty()) {
		std::vector<const Node*> currentRow;
		size_t levelSize = q.size();

		int lastIndex = -1;
		for (size_t i = 0; i < levelSize; i++) {
			const Node* curr = q.front();
			q.pop();
			currentRow.push_back(curr);
			if (curr) {
				lastIndex = i;
			}
			if (curr) {
				q.push(curr->left); q.push(curr->right);
			}
			else {
				q.push(nullptr); q.push(nullptr);
			}
		}

		bool hasNext = hasNextLevel(currentRow);

		for (size_t i = 0; i < hasNext ? levelSize : lastIndex + 1; i++) {
			std::cout << (currentRow[i] ? currentRow[i]->text : ' ');
		}
		if (!hasNext) {
			break;
		}

		std::cout << std::endl;
	}
}
