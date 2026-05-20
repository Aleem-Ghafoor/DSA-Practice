#include<iostream>
#include<queue>
#include<vector>
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
        
  bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val)
        && isMirror(t1->left, t2->right)
        && isMirror(t1->right, t2->left);
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

    TreeNode* creat(vector<int> value){

        int n = 0;

        TreeNode* root = new TreeNode(value[n]);
        queue<TreeNode*> r;
        r.push(root);

        while(!r.empty()){

            n++;
            TreeNode* current = r.front();
            r.pop();

            if(value[n] == -2) break;
            if(value[n] == -1) current->left = NULL;
            else{
              TreeNode* Lroot = new TreeNode(value[n]);
              current->left = Lroot;
              r.push(Lroot);
            }

            n++;
            if(value[n] == -2) break;
            if(value[n] == -1) current->right = NULL;
            else{
              TreeNode* Rroot = new TreeNode(value[n]);
              current->right = Rroot;
              r.push(Rroot);
            }

        }

        return root;
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
  vector<int> value = {1, 2, 2, 3, 4, 4, 3, -2};
  Solution sol;

  TreeNode* root_1 = sol.creat(value);
  
  if(sol.isSymmetric(root_1)) cout << "\nThe Tree is symmetrical.\n";
  else cout << "\nThe Tree is not symmetrical.\n";
  
  //sol.printTree(root_1);
  return 0;
}