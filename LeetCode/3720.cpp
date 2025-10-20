class Solution {
    string rec(vector<int> &count, string &b, int i) {
        if (i == b.size())
            return "";
        
        if (count[b[i] - 'a']) {
            count[b[i] - 'a']--;
            string res = rec(count, b, i + 1);
            if (res != "")
                return res;
            count[b[i] - 'a']++;
        }

        for (char c = b[i] + 1; c <= 'z'; c++) {
            if (count[c - 'a']) {
                count[c - 'a']--;

                string res = b.substr(0, i) + c;
                for (char c = 'a'; c <= 'z'; c++)
                    res += string(count[c - 'a'], c);
                return res;
            }
        }

        return "";
    }

public:
    string lexGreaterPermutation(string &a, string &b) {
        vector<int> count(26);
        for (char c : a)
            count[c - 'a']++;
        
        return rec(count, b, 0);
    }
};