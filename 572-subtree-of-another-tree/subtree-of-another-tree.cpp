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
    // 1. match() checks whether root and subRoot are identical trees.
    // 2. If both nodes are NULL, they match.
    // 3. If only one node is NULL, they do not match.
    // 4. If their values are different, they do not match.
    // 5. Otherwise, recursively compare their left and right subtrees.
    //
    // 6. isSubtree() checks every node of root as a possible starting
    //    point of subRoot.
    // 7. If the current root matches subRoot, return true.
    // 8. Otherwise, search in the left and right subtrees.

    bool match(TreeNode* root, TreeNode* subRoot) {

        // Both trees have ended at the same time.
        if(root == NULL && subRoot == NULL)
            return true;

        // One tree ended but the other didn't.
        if(root == NULL || subRoot == NULL)
            return false;

        // Values must be equal.
        if(root->val != subRoot->val)
            return false;

        // Both left and right subtrees must match.
        return match(root->left, subRoot->left) &&
               match(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Empty subRoot is considered a subtree.
        if(subRoot == NULL)
            return true;

        // root is empty but subRoot is not.
        if(root == NULL)
            return false;

        // Check if subRoot starts at the current node.
        if(match(root, subRoot))
            return true;

        // Otherwise, search in left and right subtrees.
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};