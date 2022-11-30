class Solution {
    TreeNode *construct(int value, unordered_map<int, TreeNode *> &nodeByValue, int l, int r) {
        if (value < l || value > r)
            return 0;

        TreeNode *n = nodeByValue[value];
        nodeByValue.erase(value);
        
        if (n->left) {
            if (nodeByValue.count(n->left->val)) {
                n->left = construct(n->left->val, nodeByValue, l, value - 1);
                if (!n->left)
                    return 0;
            } else if (n->left->val < l) {
                return 0;
            }                
        }
        if (n->right) {
            if (nodeByValue.count(n->right->val)) {
                n->right = construct(n->right->val, nodeByValue, value + 1, r);
                if (!n->right)
                    return 0;
            } else if (r < n->right->val) {
                return 0;
            }                
        }
        
        return n;
    }

public:
    TreeNode *canMerge(vector<TreeNode *> &trees) {
        unordered_map<int, TreeNode *> nodeByValue;
        unordered_map<int, int> inDegree;

        for (TreeNode *n : trees) {
            nodeByValue[n->val] = n;
            inDegree[n->val];
            if (n->left)
                inDegree[n->left->val]++;
            if (n->right)
                inDegree[n->right->val]++;
        }

        for (auto [value, degree] : inDegree) {
            if (!degree) {
                TreeNode *n = construct(value, nodeByValue, -1e9, 1e9);
                return n && nodeByValue.empty() ? n : 0;
            }
        }
        
        return 0;
    }
};