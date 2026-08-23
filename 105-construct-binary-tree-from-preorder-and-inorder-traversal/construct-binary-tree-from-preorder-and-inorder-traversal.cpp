/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Approach:
    // 1. Preorder gives us the root of the current subtree.
    // 2. Find this root in inorder.
    // 3. Elements before the root in inorder belong to the left subtree.
    // 4. Elements after the root in inorder belong to the right subtree.
    // 5. Recursively construct the left and right subtrees.
    // 6. Use a map to store the index of every element in inorder
    //    so that finding the root takes O(1).

    TreeNode* build(vector<int>& preorder, int& preIndex, int inStart,
                    int inEnd, unordered_map<int, int>& mp) {

        // No elements left for this subtree.
        if (inStart > inEnd)
            return NULL;

        // First element in the current preorder range is the root.
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root's position in inorder.
        int inIndex = mp[rootValue];

        // Construct left subtree.
        root->left = build(preorder, preIndex, inStart, inIndex - 1, mp);

        // Construct right subtree.
        root->right = build(preorder, preIndex, inIndex + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mp;

        // Store the index of every element in inorder.
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIndex = 0;

        return build(preorder, preIndex, 0, inorder.size() - 1, mp);
    }
};