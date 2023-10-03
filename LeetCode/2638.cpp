class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int> &a, int diff) {
        sort(a.begin(), a.end());

        map<int, int> groupSize;
        for (int value : a) {
            if (groupSize.count(value - diff)) {
                groupSize[value] = groupSize[value - diff] + 1;
                groupSize.erase(value - diff);
            } else {
                groupSize[value] = 1;
            }
        }

        vector<long long> fib = { 1, 2 };
        for (int i = 2; i <= a.size(); i++)
            fib.push_back(fib[i - 1] + fib[i - 2]);

        long long res = 1;
        for (auto &[_, size] : groupSize)
            res *= fib[size];
        return res;
    }
};