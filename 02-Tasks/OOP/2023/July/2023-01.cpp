#include <iostream>
#include <vector>

template <typename T>
class Function {
public:
	virtual T value(T) const = 0;
	virtual ~Function() = default;
};

class Inc : public Function<double> {
public:
	double value(double x) const { return x + 1; }
};

class Square : public Function<double> { 
public:
	double value(double x) const { return x * x; }
};

template <typename T>
class Max : public Function<T> { 
private:
	std::vector<const Function<T>*> functions;
public:
	void addFunction(const Function<T>* f) {
		functions.push_back(f);
	}

	T value(T x) const {
		if (functions.empty())
			throw "Function list is empty!";

		const auto it = functions.begin();
		T result = (*it)->value(x); // First element
		++it; // Skip first
		while (it != functions.end()) {
			result = std::max(result, (*it)->value(x));
			++it;
		}

		// Alternative:
		// T result = functions[0]->value(x);
		// for (size_t i = 1; i < functions.size(); ++i)
		//	 result = std::max(result, functions[i]->value(x));

		return result;
	}
};

template <typename T>
class Sum : public Function<T> { 
private:
	std::vector<const Function<T>*> functions;
public:
	void addFunction(const Function<T>* f) {
		functions.push_back(f);
	}

	T value(T x) const {
		T sum = 0;
		for (const Function<T>* func : functions) {
			sum += func->value(x);
		}

		return sum;
	}
};

int main() {
	Inc i; Square sq; Sum<double> s;
	//(x+1)+(x*x)
	s.addFunction(&i); s.addFunction(&sq);
	Max<double> m;
	//{x+1, x*x, (x+1)+(x*x)}
	m.addFunction(&i); m.addFunction(&sq);
	m.addFunction(&s);
	double x; std::cin >> x;
	std::cout << m.value(x) << std::endl;
}