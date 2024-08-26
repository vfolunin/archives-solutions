class Solution {
    bool areAlmostEqual(int a, int b) {
        if (a == b)
            return 1;
        
        if (a > b)
            swap(a, b);
        string s = to_string(b);

        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                swap(s[i], s[j]);

                if (a == stoi(s))
                    return 1;
                    
                swap(s[i], s[j]);
            }
        }

        return 0;
    }

public:
    int countPairs(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += areAlmostEqual(a[i], a[j]);
        return res;
    }
};