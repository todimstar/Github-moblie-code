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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> rs;

        while(!q.empty()){
            int len = q.size();
            int max_ = INT_MIN;//负无穷

            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();//及时弹出以便后续
                
                max_ =  max(max_,node->val);//比较
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
            }
            rs.push_back(max_);
        }
        return rs;
    }
};