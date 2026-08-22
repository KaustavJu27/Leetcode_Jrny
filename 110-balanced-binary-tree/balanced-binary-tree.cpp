/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int left_Height = height(root->left);
        int right_Height = height(root->right);

        return max(left_Height, right_Height) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return 1;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);

        bool r_balance = 0;


        if(abs(left_height - right_height) <= 1){
            r_balance = 1;
        }


        return (r_balance && isBalanced(root->left) && isBalanced(root->right));
    }
};