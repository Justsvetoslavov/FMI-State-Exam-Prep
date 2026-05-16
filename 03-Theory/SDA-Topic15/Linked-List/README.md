# LinkedList interface

Стандартен интерфейс

```c++
template<typename T>
class LinkedList {
public:
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
};

```
