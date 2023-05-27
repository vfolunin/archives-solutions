class Solution {
public:
    long long maxStrength(vector<int> &a) {
        vector<int> pos, neg, zero;
        for (int x : a) {
            if (x > 0)
                pos.push_back(x);
            else if (x < 0)
                neg.push_back(x);
            else
                zero.push_back(x);
        }
        
        if (pos.empty() && zero.empty() && neg.size() == 1)
            return neg[0];
        
        if (pos.empty() && !zero.empty() && neg.size() < 2)
            return 0;
        
        long long res = 1;

        for (int value : pos)
            res *= value;
        
        sort(neg.begin(), neg.end());
        if (neg.size() % 2)
            neg.pop_back();
        for (int value : neg)
            res *= value;
        
        return res;
    }
};