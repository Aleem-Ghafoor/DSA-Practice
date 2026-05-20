#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = generate(start, i - 1);
            vector<TreeNode*> rightSubtrees = generate(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }

    void printTree(TreeNode* root) {
        if (root == nullptr) {
            cout << "null ";
            return;
        }
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<TreeNode*> trees = sol.generateTrees(n);
    cout << "\nAll Unique BSTs (Preorder Traversal):\n";
    for (int i = 0; i < trees.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        sol.printTree(trees[i]);
        cout << endl;
    }

    return 0;
}