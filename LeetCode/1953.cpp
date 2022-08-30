class Solution {
public:
    long long numberOfWeeks(vector<int> &count) {
        sort(count.begin(), count.end());
        long long sum = accumulate(count.begin(), count.end() - 1, 0LL);
        sum += min<long long>(sum + 1, count.back());
        return sum;
    }
};