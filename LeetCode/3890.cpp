class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> count;
        for (int a = 1; a * a * a * 2 <= n; a++)
            for (int b = a; a * a * a + b * b * b <= n; b++)
                count[a * a * a + b * b * b]++;
        
        vector<int> res;
        for (auto &[value, count] : count)
            if (count > 1)
                res.push_back(value);
        return res;
    }
};