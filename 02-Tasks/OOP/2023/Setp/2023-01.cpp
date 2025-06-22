#include <vector>
#include <iostream>
#include <sstream>

struct SearchResult
{
	std::string fileName;
	unsigned line_number;
	std::string line;
};

class File
{
public:
	virtual std::vector<SearchResult> search(const std::string& str) const = 0;
	virtual ~File() = default;
};

class Document : public File
{
	std::string name;
	std::string contents;
public:
	Document(const std::string& _name, const std::string& _contents) : name(_name), contents(_contents) {};
	
	std::vector<SearchResult> search(const std::string& str) const
	{
		std::vector<SearchResult> result;
		std::stringstream ss(contents);
		std::string tempLine;
		unsigned int lineNumber = 0;
		while (std::getline(ss, tempLine)) {
			++lineNumber;
			if (tempLine.find(str) != std::string::npos) {
				result.push_back({ name, lineNumber, tempLine });
			}
		}

		return result;
	}
};

class Folder : public File
{
	std::vector<File*> files;
	std::string name;
public:
	Folder(const std::string& _name) : name(_name) {};
	
	void addFile(File* f)
	{
		files.push_back(f);
	}

	std::vector<SearchResult> search(const std::string& str) const
	{
		std::vector<SearchResult> result;
		for (const File* f : files) {
			std::vector<SearchResult> found = f->search(str);
			result.insert(result.end(), found.begin(), found.end());
		}
		return result;
	}
};
int main()
{
	Document d1("employees.txt", "John Smith\nMaryia Ivanova\n"),
		d2("inventory.txt", "Computers: 3\nPrinters: 1"),
		d3("employees.txt", "Ivan Petrov\nJane Smith"),
		d4("inventory.txt", "Computers: 5, 3D Printers: 1");

	Folder root("root"), acme("ACME Soft, Inc."), best("Best Soft, OOD");
	acme.addFile(&d1); acme.addFile(&d2);
	best.addFile(&d3); best.addFile(&d4);
	root.addFile(&acme); root.addFile(&best);
	
	std::vector<SearchResult> results = root.search("Smith");
	for (unsigned i = 0; i < results.size(); ++i)
	{
		std::cout << results[i].fileName
			<< ", line " << results[i].line_number << ": "
			<< results[i].line << std::endl;
	}
}