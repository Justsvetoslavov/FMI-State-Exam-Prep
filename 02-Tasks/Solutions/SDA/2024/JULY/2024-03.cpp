#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	std::vector<TreeNode*> children;
};

int findLevel(const TreeNode* root, const std::vector<int>& numbers) {
	std::queue<const TreeNode*> q;
	q.push(root);
	
	// return latest so that u reuse in the other task
	int lastFoundLevel = -1;
	size_t currentLevel = 0;
	while (!q.empty()) {
		std::vector<int> currentLevelValues;
		size_t levelSize = q.size();
		for (size_t i = 0; i < levelSize; i++) {
			const TreeNode* current = q.front();
			q.pop();
			currentLevelValues.push_back(current->val);
			for (const TreeNode* child : current->children) {
				q.push(child);
			}
		}

		if (currentLevelValues == numbers) {
			lastFoundLevel = currentLevel;
		}

		currentLevel++;
	}

	return lastFoundLevel;
}

void removeLevel(TreeNode* root, int level, int currentLevel) {
	if (!root || currentLevel >= level) {
		return;
	}

	if (currentLevel == level - 1) {
		// delete time
		
		std::vector<TreeNode*> currentChildren = std::move(root->children);
		root->children.clear();
		for (auto& child : currentChildren) {
			for (auto& grandChild : child->children) {
				root->children.push_back(grandChild);
			}

			delete child;
		}
	}
	else {
		for (auto& child : root->children) {
			removeLevel(child, level, currentLevel + 1);
		}
	}

}
 
void removeAllLevels(TreeNode* root, const std::vector<int>& numbers) {
	// tuka ako findLevel ne vrustha vinagi nay-dolnoto nivo 6te stane mazalo
	// naprimer ako vru6ta vinagi nay-gornoto moje da zamaje dolnit niva, koito sa bili za triene
	int level = findLevel(root, numbers);
	while (level != -1) {
		removeLevel(root, level, 0);
		level = findLevel(root, numbers);
	}
}

int main() {

}
