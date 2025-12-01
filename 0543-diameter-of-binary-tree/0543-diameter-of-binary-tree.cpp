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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int& diameter){
        if(root == nullptr)
            return 0;
        
        int l = height(root->left, diameter);
        int r = height(root->right, diameter);
        
        int temp = 1+max(l,r);
        int ans = l+r;
        diameter = max(diameter, ans);
        return temp;
    }
};