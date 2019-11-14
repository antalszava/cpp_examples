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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        std::queue<pair<TreeNode*,int>> bfs_queue;
        bfs_queue.push(make_pair(root,1));
        while (!bfs_queue.empty()){
            TreeNode* node = bfs_queue.front().first;
            int depth = bfs_queue.front().second;
            if (node->left == NULL && node->right == NULL){
                return depth;
            }
            if (node->left != NULL)
                bfs_queue.push(make_pair(node->left,depth+1));
            if (node->right != NULL)
                bfs_queue.push(make_pair(node->right,depth+1));
            bfs_queue.pop();
        }
        return 0;
    }
};
