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

    bool Check(TreeNode*root, long long minValue, long long maxValue){
        if(root==nullptr){
            return true;
        }

        if(root->val>=maxValue || root->val<=minValue){
            return false;
        }

        bool left = Check(root->left, minValue ,root->val);
        bool right= Check(root->right, root->val, maxValue);

        return left && right;
    }




    bool isValidBST(TreeNode* root) {
        return Check(root, LLONG_MIN, LLONG_MAX);
    }
};