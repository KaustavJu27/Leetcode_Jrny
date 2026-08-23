/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Approach:
    // 1. If root is NULL, return NULL.
    // 2. If root is either p or q, return root.
    // 3. Recursively search for p and q in the left and right subtrees.
    // 4. If both left and right return a node, p and q are in different
    //    subtrees, so the current root is their LCA.
    // 5. If only one side returns a node, return that node.
    // 6. If neither side returns a node, return NULL.

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case: tree is empty
        if (root == NULL)
            return NULL;

        // If current node is p or q,
        // current node can be the LCA
        if (root == p || root == q)
            return root;

        // Search for p and q in the left subtree
        TreeNode* left_LCA = lowestCommonAncestor(root->left, p, q);

        // Search for p and q in the right subtree
        TreeNode* right_LCA = lowestCommonAncestor(root->right, p, q);

        // One node found in left subtree and the other
        // found in right subtree
        if (left_LCA != NULL && right_LCA != NULL)
            return root;

        // Both nodes are present in the left subtree
        if (left_LCA != NULL)
            return left_LCA;

        // Both nodes are present in the right subtree,
        // or neither node was found
        else
            return right_LCA;
    }
};