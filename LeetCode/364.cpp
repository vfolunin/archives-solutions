class Solution {
    int maxDepth(vector<NestedInteger> &nestedList, int depth) {
        int res = 0;
        for (NestedInteger &value : nestedList) {
            res = max(res, depth);
            if (!value.isInteger())
                res = max(res, maxDepth(value.getList(), depth + 1));
        }
        return res;
    }

    int sumDepth(vector<NestedInteger> &nestedList, int maxDepth, int depth) {
        int res = 0;
        for (NestedInteger &value : nestedList) {
            if (value.isInteger())
                res += (maxDepth - depth + 1) * value.getInteger();
            else
                res += sumDepth(value.getList(), maxDepth, depth + 1);
        }
        return res;
    }

public:
    int depthSumInverse(vector<NestedInteger> &nestedList) {
        return sumDepth(nestedList, maxDepth(nestedList, 1), 1);
    }
};