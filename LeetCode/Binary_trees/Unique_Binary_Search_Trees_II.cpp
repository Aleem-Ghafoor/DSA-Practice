#include<iostream>
#include<vector>
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
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*> root;
        TreeNode* root1 = NULL;
        int a = 1, b = n;
            vector<int> value;

          while(b != 0){
            value.push_back(a);
            a++;
            b--;
          }

        do{
          a = 0;
          TreeNode* root1 = NULL;
          while(a < n){
            root1 = creat(value, a, root1);
              a++;
          }
            root.push_back(root1);
  
        }while(next_permutation(value.begin(), value.end()));
            return root;
    }

    TreeNode* creat(vector<int> value, int a, TreeNode* root1){

        if(root1 == NULL){
          //  cout << "Inserting new node: " << value[a] << endl;
            return new TreeNode(value[a]);
        }

        //cout << "Current root: " << root1->val << " | inserting: " << value[a] << endl;

        if(value[a] < root1->val)
          root1->left = creat(value, a, root1->left);
        else
          root1->right = creat(value, a, root1->right);
        
          return root1;
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

  Solution sol;
  int n;

  cout << "\nEnter the n: ";
  cin >> n;

  vector<TreeNode*> root = sol.generateTrees(n);

  cout << "\nGenerated Trees (preorder traversal):\n\n";
  int treeNum = 1;
  for (TreeNode* roots : root) {
      cout << "Tree " << treeNum++ << ": ";
      sol.printTree(roots);
      cout << endl;
  }

  return 0;
}