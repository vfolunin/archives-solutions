class Solution {
public:
    int minOperations(vector<int> &a) {
        vector<vector<int>> ops(a.size(), vector<int>(101, 1e9));
        ops[0][a[0]] = 0;

        for (int i = 1; i < a.size(); i++)
            for (int value = a[i]; value <= 100; value++)
                for (int prevValue = 1; prevValue <= value; prevValue++)
                    if (value % prevValue == 0)
                        ops[i][value] = min(ops[i][value], ops[i - 1][prevValue] + value - a[i]);
        
        return *min_element(ops.back().begin(), ops.back().end());
    }
};