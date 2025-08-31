class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> count(10);
        for (; n; n /= 10)
            count[n % 10]++;
        
        int res = -1;
        for (int i = 0; i < count.size(); i++)
            if (count[i] && (res == -1 || count[res] > count[i]))
                res = i;
        return res;
    }
};