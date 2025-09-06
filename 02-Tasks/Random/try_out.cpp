//#include <iostream>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <string>
//#include <unordered_map>
//
//int global = 0;
//
//bool returnTrue() {
//	std::cout << global++ << std::endl;
//	std::cout << "hello from true" << std::endl;
//	return true;
//}
//bool returnFalse() {
//	std::cout << global++ << std::endl;
//	std::cout << "hello from false" << std::endl;
//	return false;
//}
//
//
//int main() {
//	int a = 5;
//	// prefix ++ iska lvalue
//	(++a)++;
//
//
//	// (a++)++;
//
//	(++(++a));
//
//	// Both prefix ++ and postfix ++ require lvalue
//	// prefix ++ returns lvalue
//	// postfix ++ returns rvalue
//
//	// post fix ++ priority 2 left to right
//	// prefix ++ priority 3 right to left
//	// *deref priority 3 right to left
//
//	int* p = new int[3] {0,1,2};
//	std::cout << *++++p;
//	// int0, int1, int2
//	// otmestva p kum int1
//	// no ti vrustha pointer kum int0
//	std::cout << *p++ << " ";
//	// p sochi kum int1
//	// ++p -> int2
//	std::cout << *++p << " ";
//	std::cout << std::endl;
//	int* ptr = new int[3] {0, 1, 2};
//	std::cout << *++++ptr;
//	// std::cout << *(++(++ptr));
//
//	// int* test = nullptr;
//	// std::cout << *test;
//
//	// std::cout << (returnFalse() || returnTrue() && returnFalse());
//
//
//	int* ptr2 = new int[5];
//	int arr[50];
//
//	// ptr2[2] <=> [2]ptr2
//	// ptr2 + 2 <=> 2 + ptr2
//	// 
//	// arr[2] <=> 2[arr];
//	// arr + 2 <=> 2 + arr
//
//	std::cout << std::endl;
//
//	int octa = 010; // 1 * 8^1 + 0 * 8^0
//	int bin = 0b101;// 1 * 2^2 + 0 * 2^1 + 1 * 2^0 
//	int hex = 0xf3;// 15 * 16^1 + 3 *16^0 => 240 + 3
//	std::cout << octa << " " << bin << " " << hex << std::endl;
//
//
//	std::cout << std::hex << 243 << " " << 243 << std::endl;
//
//
//	char* c1; // abcde\0
//	char* c2; // fe\0
//
//	strcat(c1, c2);
//
//	// 'A' = > 65
//	// 	'a' = > 97;
//
//	char a = 25 + 'A';
//	'5';
//	char b = 5 + '0';
//}
#include <iostream>
#pragma warning(disable:4996)
//void print(char*& p) {
//	if (*(p++)) print(++p);
//	std::cout << *(--p);
//}
//void main() {
//
//	// *ptr == ptr[0];
//	// ptr[0][0];
//	const size_t size = 3;
//	int matrix[size][size] = {
//		1, 2, 3,
//		4, 5, 6,
//		7, 8, 9
//	};
//
//	std::cout << *(matrix[1] + 5) << std::endl;
//}


//
//class A {
//public:
//	A() { prn('c'); }
//	~A() { prn('d'); }
//	virtual void prn(char ch) const {
//		std::cout << 'A' << ch << '; ';
//	}
//};
//
//class B : public A {
//public:
//	B() { prn('c'); }
//	~B() { prn('d'); }
//	virtual void prn(char ch) const {
//		std::cout << 'B' << ch << '; ';
//	}
//};
//// A(), B()
//
//class Base {
//	int a;
//public:
//	Base(int a) {}
//	//Base(int a) {}
//	// Base(const Base& b) {}
//	// Base& operator=(const Base& b) {}
//	virtual ~Base() {}
//};
//
//class Der : public Base {
//	int* test;
//public:
//	Der(): Base(5) {}
//
//	Der(const Der& b): Base(b) {
//		// .... base is already created
//	}
//
//	Der& operator=(const Der& b) {
//		if (this != &b) {
//			// free my data
//			Base::operator=(b);
//			// copy my data
//		}
//		return *this;
//	}
//	virtual ~Der() {}
//};
//
//int a;
//int& f() {
//	return a;
//}
//
//int main() {
//	f() = 6;
//
//	int a = 6;
//}

//
//#include <vector>
//#include <iostream>
//struct SearchResult {
//	std::string fileName;
//	unsigned line_number;
//	std::string line;
//};
//class File {
//public:
//	virtual std::vector<SearchResult> search(const std::string& str) const = 0;
//	virtual ~File() {}
//};
//
//#include <sstream>
//class Document : public File {
//	std::string name;
//	std::string contents;
//public:
//	Document(const std::string& _name, const std::string& _contents) : name(_name), contents(_contents) 
//	{ }
//
//
//	std::vector<SearchResult> search(const std::string& str) const
//	{
//		std::vector<SearchResult> result;
//
//		std::stringstream ss(contents);
//		std::string tempLine;
//		unsigned int lineNumber = 0;
//		while (std::getline(ss, tempLine)) {
//			++lineNumber;
//			if (tempLine.find(str) != std::string::npos) {
//				result.push_back({ name, lineNumber, tempLine });
//			}
//		}
//
//		return result;
//	}
//};
//class Folder : public File {
//	std::vector<File&> files;
//	std::string name;
//public:
//	Folder(const std::string& _name) : name(_name) {}
//
//	void addFile(File& f) {
//		files.push_back(f);
//	}
//
//	std::vector<SearchResult> search(const std::string& str) const
//	{
//		std::vector<SearchResult> result;
//
//		for (size_t i = 0; i < files.size(); i++) {
//			std::vector<SearchResult> innerResult = files[i].search(str);
//			
//			for (size_t i = 0; i < innerResult.size(); i++) {
//				result.push_back(innerResult[i]);
//			}
//		}
//		return result;
//	}
//};
//int main()
//{
//	Document d1("employees.txt", "John Smith\nMaryia Ivanova\n"),
//		d2("inventory.txt", "Computers: 3\nPrinters: 1"),
//		d3("employees.txt", "Ivan Petrov\nJane Smith"),
//		d4("inventory.txt", "Computers: 5, 3D Printers: 1");
//	Folder root("root"), acme("ACME Soft, Inc."), best("Best Soft, OOD");
//	acme.addFile(&d1); acme.addFile(&d2);
//	best.addFile(&d3); best.addFile(&d4);
//	root.addFile(&acme); root.addFile(&best);
//	std::vector<SearchResult> results = root.search("Smith");
//	for (unsigned i = 0; i < results.size(); ++i)
//	{
//		std::cout << results[i].fileName
//			<< ", line " << results[i].line_number << ": "
//			<< results[i].line << std::endl;
//	}
//}


struct Base {
	// rule of 4
	Base() {}
	Base(int a) {}
};

int main() {
	Base b; // constructor;

	Base c; // constructor

	b = c; // operator=

	Base d = c; // Base d(c); // Copy constructor

	Base e = 5; // Base(int a)
}

