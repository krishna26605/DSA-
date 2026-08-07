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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxipath(root, maxi);
        return maxi;
    }

    int maxipath(TreeNode* root , int&maxi){
        if(root==nullptr) return 0;

        int lft=max(0,maxipath(root->left, maxi));
        int rgt= max(0,maxipath(root->right, maxi));

        maxi= max(maxi , lft+rgt+root->val);

        return (max(lft,rgt)+root->val);
    }
};