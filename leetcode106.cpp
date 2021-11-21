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
    map<int,int> index;
    TreeNode* bt(vector<int>& in, vector<int>&post, int in_l, int in_r, int post_l, int post_r){
        if(in_l > in_r || post_l > post_r)
            return NULL;
        
        //TreeNode* node = new TreeNode();
        int cur_val = post[post_r]; //postorder的最後一個元素是root
        TreeNode* node = new TreeNode(cur_val);
        int index_root = index[cur_val];
        //cout << index_root;
        int left_nums = index_root - in_l;
        node->left = bt(in,post,in_l,index_root-1,post_l,post_l+left_nums-1);
        node->right = bt(in,post,index_root+1,in_r,post_l+left_nums,post_r-1);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode();
        for(int i=0;i<inorder.size();i++)
            index[inorder[i]] = i;
        
        root = bt(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        
        return root;
    }
};
