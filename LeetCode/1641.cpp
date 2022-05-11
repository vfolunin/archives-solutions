class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> count(5, 1);
        for (int i = 1; i < n; i++)
            for (int last = 4; last >= 0; last--)
                for (int prev = last - 1; prev >= 0; prev--)
                    count[last] += count[prev];
        
        int res = 0;
        for (int value : count)
            res += value;
        return res;
    }
};