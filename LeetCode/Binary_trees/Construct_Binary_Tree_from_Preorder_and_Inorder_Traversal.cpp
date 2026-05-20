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
  
  TreeNode* find(vector<int>& p, vector<int>& i, int& a, int& b, int value){
     if(b >= i.size() || i[b] == value){  
       return NULL;
     }

     TreeNode* root = new TreeNode(p[a++]);
     root->left = find(p, i, a, b, root->val);
     b++;
     cout << b << endl;
     root->right = find(p, i, a, b, value);
     return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        
        int a = 0, b = 0;
        int value = INT_MIN;

        return find(preorder, inorder, a, b, value);;
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
  vector<int> value = {3,2,1,0,-1,-2};
  vector<int> value2 = {3,2,1,0,-1,-2};
  Solution sol;

  TreeNode* root_1 = sol.buildTree(value, value2);
  cout << endl;
  sol.printTree(root_1);
  cout << endl;
  return 0;
}