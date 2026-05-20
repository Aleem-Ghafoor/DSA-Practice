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
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
          if(!p && !q) return true;
          if(p == NULL && q != NULL || p != NULL && q == NULL) return false;

          if(p->val != q->val) return false;

          return isSameTree(p->left, q->left) &&
          isSameTree(p->right, q->right);

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
  vector<int> value = {1, 2, 1, -2};
  vector<int> value2 = {1, 1, 2, -2};
  Solution sol;

  TreeNode* root_1 = sol.creat(value);
  TreeNode* root_2 = sol.creat(value2);
  
  if(sol.isSameTree(root_1, root_2)) cout << "\nBoth trees are same.\n";
  else cout << "\nBoth trees are different.\n";
  
  return 0;
}