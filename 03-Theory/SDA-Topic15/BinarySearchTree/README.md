# BST interface

Стандартен интерфейс:

```c++
class BinarySearchTree {
public:
	bool contains(const T&) const;
	void insert(const T&);
	void remove(const T&);

// ???
	void dfs() const;
	void bfs() const;
};
```
