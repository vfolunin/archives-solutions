class Solution {
public:
    int longestBalanced(string &s) {
        int count0 = count(s.begin(), s.end(), '0');
        int count1 = s.size() - count0;

        unordered_map<int, vector<int>> seen;
        int balance = 0;
        seen[balance].push_back(-1);

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            balance += (s[i] == '1' ? 1 : -1);

            if (auto it = seen.find(balance); it != seen.end())
                res = max(res, i - it->second[0]);
            
            if (auto it = seen.find(balance - 2); it != seen.end())
                for (int j : it->second)
                    if ((i - j) / 2 <= count0)
                        res = max(res, i - j);

            if (auto it = seen.find(balance + 2); it != seen.end())
                for (int j : it->second)
                    if ((i - j) / 2 <= count1)
                        res = max(res, i - j);
            
            seen[balance].push_back(i);
        }
        return res;
    }
};