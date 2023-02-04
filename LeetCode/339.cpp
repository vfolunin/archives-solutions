class Solution {
public:
    int depthSum(vector<NestedInteger> &nestedList, int depth = 1) {
        int res = 0;
        for (NestedInteger &value : nestedList) {
            if (value.isInteger())
                res += depth * value.getInteger();
            else
                res += depthSum(value.getList(), depth + 1);
        }
        return res;
    }
};