class Item {
2 std::string m_label;
3 public:
4 Item(std::string t) : m_label(t) {}
5
6 ___________ ~Item() {}
7
8 const std::string& label() const {
9 return m_label;
10 }
11 };
12
13 ________________ <typename T>
14 class Box : public Item{
15 ______ m_contents;
16 public:
17 Box(std::string label, const T& contents)
18 : Item(_____________)
19 {
20 m_contents = new T(_________________);
21 }
22
23 Box(const Box&) = delete;
24 Box& operator=(const Box&) = delete;
25 ___________ ~Box() { delete m_contents; }
26 T& contents() { return _______________; }
27 };
28
29 Box<int>* createRandomIntBox() {
30 int randomValue = rand() % 100 + 1;
31 return ______________________________("
random box", randomValue);
32 }
33
34 Box<int>* toIntBox(Item* p) {
35 return dynamic_cast<Box<int>*>(p);
36 }
37
38 int main() {
39 Item* p = createRandomIntBox();
40 toIntBox(p)->contents() = 42;
41 std::cout << "Box {"
42 << "\n Label: " << p->label()
43 << "\n Contents: "
44 << toIntBox(p)->contents()
45 << "\n}\n";
46 delete p;
47 }
