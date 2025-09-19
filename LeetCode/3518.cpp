class Solution {
    const long long INF = 1.1e9;

    long long c(int n, int k) {
        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - k + i) / i;
            if (res >= INF)
                return INF;
        }
        return res;
    }


    long long anagramCount(vector<int> &count) {
        int totalCount = accumulate(count.begin(), count.end(), 0);
        long long res = 1;
        for (int count : count) {
            res *= c(totalCount, count);
            if (res >= INF)
                return INF;
            totalCount -= count;
        }
        return res;
    }

    string rec(vector<int> &count, int index, string &res) {
        if (!accumulate(count.begin(), count.end(), 0))
            return res;

        for (int i = 0; i < count.size(); i++) {
            if (!count[i])
                continue;
            
            count[i]--;
            long long aCount = anagramCount(count);
            if (index < aCount) {
                res += i + 'a';
                return rec(count, index, res);
            }
            index -= aCount;
            count[i]++;
        }

        return "#";
    }

public:
    string smallestPalindrome(string &s, int index) {
        vector<int> count(26);
        for (int i = 0; i * 2 + 1 < s.size(); i++)
            count[s[i] - 'a']++;

        string cur;
        string left = rec(count, index - 1, cur);

        if (left == "#")
            return "";
        
        string right(left.rbegin(), left.rend());
        if (s.size() % 2)
            left += s[s.size() / 2];
        return left + right;
    }
};