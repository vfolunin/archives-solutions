class Solution {
    vector<TreeNode *> rec(int size, int minValue, int maxValue) {
        if (!size)
            return { 0 };
        
        vector<TreeNode *> res;
        
        for (int lSize = 0, rSize = size - 1; lSize < size; lSize++, rSize--) {
            vector<TreeNode *> lTrees = rec(lSize, minValue, minValue + lSize - 1);
            vector<TreeNode *> rTrees = rec(rSize, maxValue - rSize + 1, maxValue);
            
            for (TreeNode *l : lTrees)
                for (TreeNode *r : rTrees)
                    res.push_back(new TreeNode(minValue + lSize, l, r));
        }
        
        return res;
    }
    
public:
    vector<TreeNode *> generateTrees(int n) {
        return rec(n, 1, n);
    }
};