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
    int closestValue(TreeNode* root, double target) {
		auto closest = root->val;
		auto cur = root;
		while(cur != nullptr) {
			if(abs(cur->val - target) < abs(closest - target)) {
				closest = cur->val;
			}
			if(target == cur->val ) {
				break;
			} else if(target < cur-> val) {
				cur = cur->left;
			} else {
				cur = cur->right;
			}
		}
		return closest;
    }

	double abs(double x) {
		if(x < 0) {
			return -1 * x;
		} 
		return x;
	}
};