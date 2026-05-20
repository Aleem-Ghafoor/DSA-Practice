#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        cout << "Inserting new node: " << val << endl;
        return new Node(val);
    }

    cout << "Current root: " << root->data << " | inserting: " << val << endl;

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


// Inorder traversal gives sorted output for BST
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int val;

    cout << "\nPress -1 to stop!\n";

    while(true){

        cout << "Enter Binary search tree digits: ";
        cin >> val;

        if(val == -1) break;
        
        root = insert(root, val);

    }

    cout << "Inorder (Sorted) Traversal: ";
    inorder(root);

    return 0;
}
