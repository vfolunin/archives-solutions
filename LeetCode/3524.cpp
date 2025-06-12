class Solution {
public:
    vector<long long> resultArray(vector<int> &a, int divisor) {
        for (int &value : a)
            value %= divisor;

        vector<vector<long long>> count(a.size(), vector<long long>(divisor));
        for (int i = 0; i < a.size(); i++) {
            count[i][a[i]]++;
            if (i)
                for (int prevMod = 0; prevMod < divisor; prevMod++)
                    count[i][prevMod * a[i] % divisor] += count[i - 1][prevMod];
        }

        vector<long long> res(divisor);
        for (int i = 0; i < a.size(); i++)
            for (int mod = 0; mod < divisor; mod++)
                res[mod] += count[i][mod];
        return res;
    }
};