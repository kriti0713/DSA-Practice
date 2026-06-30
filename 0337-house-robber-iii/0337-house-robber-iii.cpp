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
    pair<int,int> dfs(TreeNode* root){
    if (!root)return {0, 0};
    
    auto [leftRob, leftSkip] = dfs(root->left);
    auto [rightRob, rightSkip] = dfs(root->right);

    int rob = root->val + leftSkip + rightSkip;
    int Skip = max(leftRob, leftSkip) + max(rightRob, rightSkip);

    return {rob, Skip};
}
public:
    int rob(TreeNode* root) {
        auto [rob, Skip] = dfs(root);
        return max(rob,Skip);
        
    
    }
};
