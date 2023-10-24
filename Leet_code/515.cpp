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
        queue<pair<TreeNode*, int>> fila;
        int maxValue = INT_MIN;
        int level = 0;
        vector<int> resp;

        fila.push(make_pair(root, 0));

        if (root == nullptr) {
            return resp;
        }

        while (!fila.empty()) {
            pair<TreeNode*, int> no = fila.front();
            TreeNode* raiz = no.first;
            int nodeLevel = no.second;

            if (nodeLevel > level) {
                level = nodeLevel;
                resp.push_back(maxValue);
                maxValue = INT_MIN;
            }

            fila.pop();
            maxValue = max(maxValue, raiz->val);

            if (raiz->right != nullptr) {
                fila.push(make_pair(raiz->right, nodeLevel + 1));
            }

            if (raiz->left != nullptr) {
                fila.push(make_pair(raiz->left, nodeLevel + 1));
            }
        }

        resp.push_back(maxValue);

        return resp;
    }
};