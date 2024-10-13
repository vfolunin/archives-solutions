class Solution {
    pair<bool, int> rec(TreeNode *n, vector<int> &sizes) {
        if (!n)
            return { 1, 0 };
        
        auto [lGood, lSize] = rec(n->left, sizes);
        auto [rGood, rSize] = rec(n->right, sizes);

        bool good = lGood && lSize == rSize && rGood;
        int size = lSize + 1 + rSize;

        if (good)
            sizes.push_back(size);
        
        return { good, size };
    }

public:
    int kthLargestPerfectSubtree(TreeNode *root, int index) {
        vector<int> sizes;
        rec(root, sizes);
        sort(sizes.rbegin(), sizes.rend());
        return index <= sizes.size() ? sizes[index - 1] : -1;
    }
};