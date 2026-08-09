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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return nullptr;

        stack<TreeNode*>st;
        TreeNode* curr=root;

        TreeNode* visited=nullptr;

        while(!st.empty()||curr){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();

            if(curr->right&&curr->right!=visited){
                curr=curr->right;
                continue;
            }

            st.pop();

             if(!curr->left&&!curr->right&&curr->val==target){
                if(st.empty())return nullptr;

                TreeNode* parent=st.top();

                if(parent->left==curr){
                    parent->left=nullptr;
                }else if(parent->right==curr){
                    parent->right=nullptr;
                }
             }else{
                visited=curr;
             }
             curr=nullptr;
        }
        return root;
    }
};