class Solution {
public:
    int minOperations(vector<int> &a, int targetSum) {
        vector<vector<int>> minOps(2, vector<int>(targetSum + 1, 1e9));
        minOps[1][0] = 0;

        for (int size = 1; size <= a.size(); size++) {
            int value = a[size - 1];
            minOps[0] = minOps[1];

            for (int mulOps = 0, changedValue = value; changedValue <= targetSum; mulOps++, changedValue *= 2)
                for (int sum = changedValue; sum < minOps[0].size(); sum++)
                    minOps[1][sum] = min(minOps[1][sum], minOps[0][sum - changedValue] + mulOps);

            for (int divOps = 0, changedValue = value; changedValue; divOps++, changedValue /= 2)
                for (int sum = changedValue; sum < minOps[0].size(); sum++)
                    minOps[1][sum] = min(minOps[1][sum], minOps[0][sum - changedValue] + divOps);
        }

        return minOps[1][targetSum] != 1e9 ? minOps[1][targetSum] : -1;
    }
};