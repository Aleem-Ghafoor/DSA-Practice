#include<iostream>
#include<vector>
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

    // vector<int> find(TreeNode* root, vector<int>& r){
    //     if(root == NULL)
    //       return r;

    //       r.push_back(root->val);

    //       find(root->left, r);
    //       find(root->right, r);

    //       return r;
    // }

    vector<int> preorderTraversal(TreeNode* root, vector<int>& r) {
        if(root == NULL)
          return r;

          r.push_back(root->val);

          preorderTraversal(root->left, r);
          preorderTraversal(root->right, r);

          return r;
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

  vector<int> value = {1,-1,2,3,-2};
  vector<int> result;
  Solution sol;

  TreeNode* root_1 = sol.creat(value);
  result = sol.preorderTraversal(root_1, result);
  cout << endl;
  for(auto r : result)
    cout << r << " ";
  cout << endl;

  return 0;
}