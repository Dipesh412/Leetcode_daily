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
    int sumCal(TreeNode* root,int v){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            return v==0?root->val:0;
        }
        return sumCal(root->left,0)+sumCal(root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumCal(root,-1);
    }
};