
struct Node {
	char value;
	Node* left = nullptr, * middle = nullptr, * right = nullptr;
    Node(char v) : value(v) {}
};

void bfs(const Node* root) {
	std::queue<const Node*> q;
	q.push(root);
	std::vector<char> row;
	while (!q.empty()) {
		row.clear();
		size_t levelSize = q.size();
		for (size_t i = 0; i < levelSize; i++) {
			auto current = q.front();
			q.pop();
			row.push_back(current->value);
			if (current->left) {
				q.push(current->left);
			}
			if (current->middle) {
				q.push(current->middle);
			}
			if (current->right) {
				q.push(current->right);
			}
		}
	}

	for (auto ch : row) {
		std::cout << ch;
	}
}

void dfs(const Node* root, std::ofstream& out) {
    if (!root) {
        std::cout << "*";
        return;
    }

    std::cout << "(" << root->value;
    std::cout << " ";
    dfs(root->left, out);
    std::cout << " ";
    dfs(root->middle, out);
    std::cout << " ";
    dfs(root->right, out);
    std::cout << ")";
}
