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
    // 1. Find the path from root to node p and store it in path1.
    // 2. Find the path from root to node q and store it in path2.
    // 3. Both paths start from the root.
    // 4. Compare path1 and path2 from the beginning.
    // 5. The last common node is the Lowest Common Ancestor.
    
    bool findPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* target) {
        
        // If root is NULL, target cannot be found.
        if(root == NULL) 
            return false;

        // Add current node to the path.
        path.push_back(root);

        // If current node is the target, path is complete.
        if(root == target) 
            return true;

        // Search in left and right subtree.
        // If target is found in either subtree, keep the path.
        if(findPath(root->left, path, target) || 
           findPath(root->right, path, target)) {
            return true;
        }

        // Target was not found through this node,
        // so remove it while backtracking.
        path.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1, path2;

        // Find root -> p path and root -> q path.
        // If either node doesn't exist, return NULL.
        if (!findPath(root, path1, p) || 
            !findPath(root, path2, q)) {
            return NULL;
        }

        TreeNode* ans = NULL;

        // Compare both paths from the root.
        // The last node having the same address in both paths
        // is the Lowest Common Ancestor.
        for (int i = 0; 
             i < path1.size() && i < path2.size(); 
             i++) {

            if (path1[i] == path2[i]) {
                ans = path1[i];
            }
        }

        return ans;
    }
};