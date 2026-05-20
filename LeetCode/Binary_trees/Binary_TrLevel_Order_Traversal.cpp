
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

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        queue<TreeNode*> root_1;

        root_1.push(root);

        while(!(root_1.empty())){

            vector<int> num;
            int n = root_1.size();

            for(int i = 0; i < n; i++){
                TreeNode* current = root_1.front();
                root_1.pop();

                if(current){
                  num.push_back(current->val);
                  if(current->left) root_1.push(current->left);
                  if(current->right) root_1.push(current->right);
                }

            }
      
            if(!num.empty())
              result.push_back(num);

        }

        return result;
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
  vector<vector<int>> result;

  TreeNode* root_1 = sol.creat(value);
  result = sol.levelOrder(root_1);
  cout << endl;
  sol.printTree(result);
  return 0;
}