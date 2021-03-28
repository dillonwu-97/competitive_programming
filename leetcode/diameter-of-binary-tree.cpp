/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), 
     right(right) {}
 * };
 */
class Solution {
    int total = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        result = max_find(root);
        return total;
    }
        // val = max of left and right
    int max_find (TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            int ml = max_find(root->left);
            int mr = max_find(root->right);
            if (ml + mr > total) {
                total = ml + mr;
            }
            return max( ml, mr) + 1;
        }
    }
};