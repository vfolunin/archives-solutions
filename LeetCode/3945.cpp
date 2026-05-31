class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> count(10);
        while (n) {
            count[n % 10]++;
            n /= 10;
        }

        int res = 0;
        for (int i = 0; i < count.size(); i++)
            res += i * count[i];
        return res;
    }
};