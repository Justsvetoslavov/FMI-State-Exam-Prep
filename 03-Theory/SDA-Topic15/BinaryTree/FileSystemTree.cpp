#include <iostream>
#include "BinaryTree.hpp"

// File System Directory Tree using BinaryTree<std::string>
//
// Each node is a folder or file name.
// Every folder has at most 2 sub-entries (simplified model).
//
// Structure built in this demo:
//
//              "root"
//             /      \
//          "home"   "etc"
//          /    \      \
//       "docs" "pics" "nginx"
//       /
//    "cv.pdf"
//
// add()         -> create a new folder/file at the first free slot (BFS order)
// search()      -> check whether a file/folder exists anywhere in the tree
// printPreOrder -> parent folder printed before its contents  (like ls -R)
// printPostOrder-> leaves (files) processed before their parent folders
//                  useful for: calculating total size bottom-up
// printLevelOrder-> show contents depth by depth (root -> subdirs -> files)

int main() {
    BinaryTree<std::string> fs("root",
        new BinaryTree<std::string>("home",
            new BinaryTree<std::string>("docs",
                new BinaryTree<std::string>("cv.pdf"),
                nullptr),
            new BinaryTree<std::string>("pics")),
        new BinaryTree<std::string>("etc",
            nullptr,
            new BinaryTree<std::string>("nginx")));

    // --- search: does a path entry exist? ---
    std::cout << "Search 'docs':   " << (fs.search("docs")    ? "found" : "not found") << "\n";
    std::cout << "Search 'passwd': " << (fs.search("passwd")  ? "found" : "not found") << "\n\n";

    // --- add: create a new entry at the next free BFS slot ---
    fs.add("music");   // fills the empty left child of "etc"
    std::cout << "After adding 'music':\n";

    // --- printLevelOrder: show by depth (root -> subdirs -> files) ---
    std::cout << "\nLevel-order (by depth):\n";
    fs.printLevelOrder();
    std::cout << "\n";

    // --- printPreOrder: parent before its children (top-down, like ls -R) ---
    std::cout << "\nPre-order (ls -R style, parent before contents):\n";
    fs.printPreOrder();
    std::cout << "\n";

    // --- printPostOrder: children before parent (bottom-up, e.g. du -sh) ---
    std::cout << "\nPost-order (du -sh style, files before their folder):\n";
    fs.printPostOrder();
    std::cout << "\n";

    return 0;
}
