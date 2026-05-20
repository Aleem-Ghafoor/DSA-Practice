
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

 void getLeaf(TreeNode* root, vector<int>& leaf) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            leaf.push_back(root->val);
            return;
        }
        getLeaf(root->left, leaf);
        getLeaf(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        return leaf1 == leaf2;
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
};

int main(){
  vector<int> value = {3,5,1,6,2,9,8,-1,-1,-1,4,-2};
  vector<int> value2 = {3,5,1,6,7,4,2,-1,-1,-1,-1,-1,-1,9,8,-2};
  Solution sol;

  TreeNode* root_1 = sol.creat(value);
  TreeNode* root_2 = sol.creat(value2);

  if(sol.leafSimilar(root_1, root_2)) cout << "\nThe Tree leaf's are similar.\n";
  else cout << "\nThe Tree leaf's are not similar.\n";

  return 0;
}