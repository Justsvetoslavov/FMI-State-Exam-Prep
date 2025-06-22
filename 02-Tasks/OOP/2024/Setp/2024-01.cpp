#include <iostream>

class A {
public:
	A() { prn('c'); }
	~A() { prn('d'); }
	virtual void prn(char ch) const {
		std::cout << 'A' << ch << ';';
	}
};

class B : public A {
public:
	B() { prn('c'); }
	~B() { prn('d'); }
	virtual void prn(char ch) const {
		std::cout << 'B' << ch << ';';
	}
};

int main() {
	A* obj = new B;
	obj->prn('p');
	delete obj;
}