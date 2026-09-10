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
 void dfs(TreeNode* root, int& count, int&sum){
    if(!root->left && !root->right){
        count++;
        sum += root->val;
        return;
    }
    sum += root->val;
    count++;
    if(root->left) dfs(root->left,count,sum);
    if(root->right) dfs(root->right,count,sum);
 }
 void dfs2(TreeNode*root , int&answer){
    if(!root) return;
    int sum = 0;
    int count = 0;
    dfs(root,count,sum);
    if(count == 0) return;
    if(root->val == sum/count) answer++;
    if(root->left) dfs2(root->left, answer);
    if(root->right) dfs2(root->right,answer);
 }
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int answer = 0;
        dfs2(root,answer);
        return answer;
    }
};