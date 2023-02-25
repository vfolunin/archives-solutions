class Solution {
    pair<int, int> rec(vector<int> &tree, int index) {
        if (tree[index] == -1)
            return { 0, 0 };
        
        auto [lCount, lSum] = rec(tree, index * 2 + 1);
        auto [rCount, rSum] = rec(tree, index * 2 + 2);

        bool isLeaf = tree[index * 2 + 1] == -1 && tree[index * 2 + 2] == -1;
        int count = lCount + isLeaf + rCount;
        int sum = lSum + count * tree[index] + rSum;
        return { count, sum };
    }

public:
    int pathSum(vector<int> &a) {
        vector<int> tree(100, -1);
        for (int value : a) {
            int depth = value / 100;
            int index = (1 << (depth - 1)) + value / 10 % 10 - 2;
            tree[index] = value % 10;
        }
        return rec(tree, 0).second;
    }
};