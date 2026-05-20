#include<iostream>
#include<queue>
using namespace std;

class Tree{
  public:

    int n;
    Tree* left;
    Tree* right;

    Tree(int n){

        this->n = n;
        left = right = NULL;

    }
    
};

static int record = -1;

    Tree* insertdata() {

    int val;
    cout << "\nEnter the root of binary tree: ";
    cin >> val;

    Tree* root = new Tree(val);
    
    queue<Tree*> s;

    s.push(root);

    cout << "\nPress -1 to stop.";

    while(!s.empty()){
  
        Tree* current = s.front();
        s.pop();

        cout << "\nEnter Left child of " << current->n << ": ";
        cin >> val;

        if(val == -1)
          break;

        Tree* Lroot = new Tree(val);

        current->left = Lroot;
        s.push(Lroot);

        cout << "\nEnter Right child of " << current->n << ": ";
        cin >> val;

        Tree* Rroot = new Tree(val);

        current->right = Rroot;
        s.push(Rroot);

    }
    
    return root;
}



void describeTree(Tree* root) {
    if (root == NULL) return;

    // check left child
    if (root->left != NULL) {
        cout << "\nThis is the left of " << root->n << ": " << root->left->n << endl;
    }

    // check right child
    if (root->right != NULL) {
        cout << "\nThis is the right of " << root->n << ": " << root->right->n << endl;
    }
    
    describeTree(root->left);
    describeTree(root->right);
}

int main(){

  int n = 0, a = -1;
  Tree* root = NULL;

    root = insertdata();

    cout << "\nInorder traversal: ";
    describeTree(root);
  return 0;
}