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

    // Approach:
    // 1. If root is NULL, return NULL.
    // 2. Recursively invert the left subtree.
    // 3. Recursively invert the right subtree.
    // 4. Swap the inverted left and right subtrees.
    // 5. Return the current root.
    //
    // The recursion continues until leaf nodes are reached.
    // Then, while returning from recursion, the left and right
    // children are swapped at every node.

    TreeNode* invertTree(TreeNode* root) {

        // Base case:
        // If the tree is empty, there is nothing to invert.
        if(root == NULL) 
            return NULL;

        // Leaf node:
        // A leaf has no children, so it is already inverted.
        if(root->left == NULL && root->right == NULL){
            return root;
        }

        // Recursively invert the left subtree.
        TreeNode* left = invertTree(root->left);

        // Recursively invert the right subtree.
        TreeNode* right = invertTree(root->right);

        // Swap the left and right subtrees.
        root->left = right;
        root->right = left;

        // Return the inverted tree.
        return root;
    }
};