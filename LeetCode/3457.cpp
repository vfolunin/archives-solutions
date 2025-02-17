class Solution {
public:
    long long maxWeight(vector<int> &a) {
        sort(a.rbegin(), a.rend());

        int even = a.size() / 4 / 2, odd = a.size() / 4 - even;
        long long res = 0;

        for (int i = 0; i < odd; i++)
            res += a[i];
        for (int i = 0; i < even; i++)
            res += a[odd + i * 2 + 1];

        return res;
    }
};