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
    int calsum(TreeNode* root,int sum){
        if(root==NULL){
            return 0;
        }
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            return sum;
        }
        return calsum(root->left,sum)+calsum(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        return calsum(root,0);
    }
};