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
    int height(TreeNode* root){
        if(root == NULL) return 0;

        if(root->left == NULL && root->right == NULL) return 1;

        int left_height = height(root->left);
        int right_height = height(root->right);

        return max(left_height,right_height) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            return 0;
        }

        int root_height = height(root->left) + height(root->right);
        
        int left_height = diameterOfBinaryTree(root->left);
        int right_height = diameterOfBinaryTree(root->right);

        return (max(root_height,max(left_height,right_height)));
    }
};