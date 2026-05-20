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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        if(root == NULL) return result;

        vector<int> left = inorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());

        cout << "\nThe end: " << result.back();
        return result;
    }

     void creat(TreeNode* root){

        int n;

        cout << "\nEnter the root value: ";
        cin >> n;
      if(n != -2){
         root->val = n;

        queue<TreeNode*> dummy;

        dummy.push(root);

        cout << "\npress -1 to stop left and right child!\n";
        cout << "\nFor full termination press -2!\n";


        while(!dummy.empty()){

            TreeNode* current = dummy.front();
            dummy.pop();

            cout << "\nEnter the left child value: ";
            cin >> n;
          if(n == -2) break;
          if(n == -1)
              current->left = NULL;
          else{
            TreeNode* Lroot = new TreeNode(n);
            current->left = Lroot;
            dummy.push(Lroot);
          }

            cout << "\nEnter the right child value: ";
            cin >> n;
          if(n == -2) break;
          if(n == -1)
              current->right = NULL;
          else{
            TreeNode* Rroot = new TreeNode(n);
            current->right = Rroot;
            dummy.push(Rroot);
          }

        }
      }
      else root = NULL;

     }
};
     
int main(){
    TreeNode* root = new TreeNode;
    Solution sol;
    vector<int> value;
    sol.creat(root);
    value = sol.inorderTraversal(root);

    for(auto l : value)
      cout << l << " ";
    
              
  return 0;
}