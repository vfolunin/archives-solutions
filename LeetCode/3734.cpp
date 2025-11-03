class Solution {
    bool rec(string &s, int i, vector<int> &count, string &res) {
        if (i == s.size() / 2)
            return 1;

        if (count[s[i] - 'a']) {
            res.push_back(s[i]);
            count[s[i] - 'a']--;
            if (rec(s, i + 1, count, res))
                return 1;
            res.pop_back();
            count[s[i] - 'a']++;
        }

        for (char c = s[i] + 1; c <= 'z'; c++) {
            if (count[c - 'a']) {
                res.push_back(c);
                count[c - 'a']--;
                for (c = 'a'; c <= 'z'; c++)
                    res += string(count[c - 'a'], c);
                return 1;
            }
        }

        return 0;
    }

    string getWhole(string &half, int oddIndex) {
        string res = half;
        if (oddIndex != -1)
            res += oddIndex + 'a';
        res += string(half.rbegin(), half.rend());
        return res;
    }

public:
    string lexPalindromicPermutation(string &letters, string &threshold) {
        vector<int> count(26);
        for (char c : letters)
            count[c - 'a']++;

        int oddIndex = -1;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] % 2) {
                if (oddIndex == -1)
                    oddIndex = i;
                else
                    return "";
            }
        }
        
        for (int &value : count)
            value /= 2;
        
        string half;
        if (!rec(threshold, 0, count, half))
            return "";
        
        for (int i = 0; i < 2; i++) {
            string candidate = getWhole(half, oddIndex);
            if (threshold < candidate)
                return candidate;
            next_permutation(half.begin(), half.end());
        }
        
        return "";
    }
};