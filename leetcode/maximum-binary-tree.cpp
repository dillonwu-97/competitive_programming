/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(nums[0]);
        TreeNode* current;
        for (int i = 1; i < nums.size(); i++) {
            current = root;
            TreeNode * newnode = new TreeNode(nums[i]);
            if (nums[i] > root->val) {
                newnode->left = root;
                root = newnode;
            } else {
                // if nums[i] < root->val
                while (1) {
                    if (current->right == NULL) {
                        current->right = newnode;
                        break;
                    }
                    if (current->right->val > nums[i]) {
                        current = current->right;
                    } else {
                        newnode->left = current->right;
                        current->right = newnode;
                        break;
                    }
                                    }
            }
        }
        return root;
    }
};