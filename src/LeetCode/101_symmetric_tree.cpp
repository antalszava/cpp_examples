#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

  // iterative method
  // bool isSymmetric(TreeNode* root) {
  //   if (root == NULL){
  // 	return true;
  //   }
      
  //   std::queue<TreeNode*> q;
  //   q.emplace(root->left);
  //   q.emplace(root->right);

  //   while(!q.empty()){
  // 	TreeNode* t1 = q.front();
  // 	q.pop();
  // 	TreeNode* t2 = q.front();
  // 	q.pop();
  // 	if (t1 == NULL && t2 == NULL) continue;
  // 	if (t1 == NULL || t2 == NULL) return false;
  // 	if (t1->val != t2->val) return false;
  // 	q.emplace(t1->left);
  // 	q.emplace(t2->right);
  // 	q.emplace(t1->right);
  // 	q.emplace(t2->left);
  //   }
  //   return true;
  // }


  //recursive method
  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    return isMirror(root->left, root->right);
  }

  bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val)
      && isMirror(t1->right, t2->left)
      && isMirror(t1->left, t2->right);
  }
  
};
