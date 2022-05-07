class Solution {
    struct Data {
        vector<int> modes;
        int modeCount = 0;
        int min, minCount = 0;
        int max, maxCount = 0;
    };
    
    Data rec(TreeNode *n) {
        if (!n)
            return {};
        
        Data l = rec(n->left);
        Data r = rec(n->right);
        
        int valCount = 1;
        if (l.maxCount && l.max == n->val)
            valCount += l.maxCount;
        if (r.minCount && r.min == n->val)
            valCount += r.minCount;
        
        Data res = l;
        if (res.modeCount < valCount) {
            res.modeCount = valCount;
            res.modes = { n->val };
        } else if (res.modeCount == valCount) {
            res.modes.push_back(n->val);
        }
        if (res.modeCount < r.modeCount) {
            res.modeCount = r.modeCount;
            res.modes = r.modes;
        } else if (res.modeCount == r.modeCount) {
            res.modes.insert(res.modes.end(), r.modes.begin(), r.modes.end());
        }
        
        if (l.minCount) {
            res.min = l.min;
            res.minCount = l.minCount + (l.min == n->val);
        } else {
            res.min = n->val;
            res.minCount = 1;
        }
        if (res.min == n->val && r.minCount && r.min == n->val)
            res.minCount += r.minCount;
        
        if (r.maxCount) {
            res.max = r.max;
            res.maxCount = r.maxCount + (r.max == n->val);
        } else {
            res.max = n->val;
            res.maxCount = 1;
        }
        if (res.max == n->val && l.maxCount && l.max == n->val)
            res.maxCount += l.maxCount;
        
        return res;
    }
    
public:
    vector<int> findMode(TreeNode *root) {
        return rec(root).modes;
    }
};