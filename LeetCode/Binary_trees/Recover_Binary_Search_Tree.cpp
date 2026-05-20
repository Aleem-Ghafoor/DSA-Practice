#include<iostream>
#include<queue>

using namespace std;
 
   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

public:
    void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (prev && prev->val > root->val) {
        if (!first) first = prev;
        second = root;
    }
    cout << root->val;
    prev = root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    prev = first = second = nullptr; 
    inorder(root);

    if (first && second) {
        swap(first->val, second->val);
    }
}


    void creat(TreeNode* root){

        int n;

        cout << "\nEnter the root value: ";
        cin >> n;

        root->val = n;
        queue<TreeNode*> r;
        r.push(root);

        cout << "\nPress -1 to exsit!\n";
        cout << "For full termination press -2!\n";

        while(!r.empty()){

            TreeNode* current = r.front();
            r.pop();

            cout << "\nEnter the left child " << "of the " << current->val << ": ";
            cin >> n;

            if(n == -2) break;
            if(n == -1) current->left = NULL;
            else{
              TreeNode* Lroot = new TreeNode(n);
              current->left = Lroot;
              r.push(Lroot);
            }
            cout << "\nEnter the right child " << "of the " << current->val << ": ";
            cin >> n;

            if(n == -2) break;
            if(n == -1) current->right = NULL;
            else{
              TreeNode* Rroot = new TreeNode(n);
              current->right = Rroot;
              r.push(Rroot);
            }

        }

    }

    void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    // Inorder Traversal
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
};

int main(){

  TreeNode* root = new TreeNode();
  Solution sol;

  sol.creat(root);
  sol.recoverTree(root);
  sol.printTree(root);
  
  return 0;
}