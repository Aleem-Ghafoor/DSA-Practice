
#include<iostream>
#include<queue>
#include<algorithm>
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

  vector<int> find(TreeNode* root, int count, vector<int>& result){

        if(!root){
           result.push_back(count);
           return result;
        }

        count++;
        find(root->left, count, result);
        find(root->right, count, result);

        return result;

  }

  int maxDepth(TreeNode* root) {
        vector<int> result;   

        result = find(root, 0, result);

        int max = *max_element(result.begin(), result.end());

        return max;
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

    void printTree(vector<vector<int>> root) {

        for (const auto& row : root) {
          for (int val : row) {
            cout << val << " ";
          }
          cout << endl;
        }

    }
};

int main(){
  vector<int> value = {3, 9, 20, -1, -1, 15, 7, -2};
  Solution sol;
  int result;

  TreeNode* root_1 = sol.creat(value);
  result = sol.maxDepth(root_1);

  cout << endl << "Maximum Depth of Binary Tree: " << result << endl;
  return 0;
}