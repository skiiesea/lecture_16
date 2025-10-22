#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
template <typename T>
struct Node
{
    T val;
    Node *parent;
    Node *left;
    Node *right;
    Node(T val) : parent(nullptr), left(nullptr), right(nullptr){} 
};

Node<int>* treeFromFile(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open())
        throw std::invalid_argument("File is not available!");
    
    int n;
    file >> n;
    file.ignore();

    int* parents = new int[n];
    int* lefts = new int[n];
    int* rights = new int[n];

    for (int i = 0; i < n; ++i)
        parents[i] = -1, lefts[i] = -1, rights[i] = -1;
    for (int i = 0; i < n; ++i){
        std::string line;
        std::getline(file, line);
        std::stringstream stream(line);
        int parent, left, right;
        stream >> parent >> left >> right;
        parents[left] = parent; // p l r добавление в него детей
        parents[right] = parent;
        lefts[parent] = left;
        rights[parent] = right;
    }
    int root_i = -1;
    while(parents[root_i++] != -1); // Нахождение индекса корня
    Node<int> *root = new Node<int>(root_i);
    Node<int> **nodes_p = new Node<int>*[n];
    for (int i = 0; i < n; ++i)
        if(parents[i] != -1) nodes_p[i] = new Node<int>(i);
        else nodes_p[i] = root;
    for (int i = 0; i < n; ++i){
        if(parents[i] != -1) nodes_p[i]->parent = nodes_p[parents[i]];
        if(lefts[i] != -1) nodes_p[i]->left = nodes_p[lefts[i]];
        if(rights[i] != -1) nodes_p[i]->right = nodes_p[rights[i]];
    }

    return root;
}

void print(Node<int>* root){
    if(!root->left && !root->right) {std::cout << root->val; return;}
    if(root->left) print(root->left);
    if(root->right) print(root->right);
    std::cout << root->val;
    return;
}
int main () {
    auto root = treeFromFile("test_1.txt");
    print(root);
}