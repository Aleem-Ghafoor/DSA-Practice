#include<iostream>
#include<queue>
#include<climits>
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
public:
    bool helper(TreeNode* node, long minVal, long maxVal) {
    if (node == NULL) return true;

    if (node->val <= minVal || node->val >= maxVal)
        return false;
    return helper(node->left, minVal, node->val) &&
           helper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
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
};

int main(){

  TreeNode* root = new TreeNode();
  Solution sol;

  sol.creat(root);
  
  bool root1 = sol.isValidBST(root);

    if(root1)
        cout << "\nThis is a valid BST.\n";
    else
        cout << "\nThis is NOT a valid BST.\n";
  return 0;
}