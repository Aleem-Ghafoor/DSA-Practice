#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int n;
    Tree* left;
    Tree* right;

    Tree(int n) {
        this->n = n;
        left = right = NULL;
    }
};

// Function to insert data recursively in preorder form
Tree* insertdata(vector<int>& n, int& a) {
    a++; // move to next element
    if (a >= n.size() || n[a] == -1)
        return NULL;

    Tree* root = new Tree(n[a]);
    root->left = insertdata(n, a);
    root->right = insertdata(n, a);

    return root;
}

// Function to count total nodes
int count_node(Tree* root, int& count) {
    if (root == NULL)
        return count;
    count_node(root->left, count);
    count++;
    count_node(root->right, count);
    return count;
}

// Display function
void display(Tree* root) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        cout << "This is the left of " << root->n << ": " << root->left->n << endl;

    if (root->right != NULL)
        cout << "This is the right of " << root->n << ": " << root->right->n << endl;

    display(root->left);
    display(root->right);
}

int main() {
    vector<int> n = {1, 2, 3, -1, -1, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1};
    int a = -1, b = 0;

    Tree* root = insertdata(n, a);

    cout << "Tree structure:\n";
    display(root);

    int count = count_node(root, b);
    cout << "\nTotal nodes in tree: " << count << endl;

    return 0;
}
