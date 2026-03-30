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
    
    bool isSorted(vector<int> res){
        for(int i = 0; i < res.size()-1; i++){
            if(res[i] >= res[i+1])
                return false;
        }

        return true;
    }

    void inOrder(TreeNode* node, vector<int>& res) {
        if (node == nullptr)
            return;
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);

        return isSorted(res);            
    }
};
