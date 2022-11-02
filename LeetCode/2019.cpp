class Solution {
    int eval(string &s, int l, int r) {
        int p1 = -1, p2 = -1;
        for (int i = l; i <= r; i++) {
            if (s[i] == '+')
                p1 = i;
            if (s[i] == '*')
                p2 = i;
        }
        
        if (p1 != -1) {
            int a = eval(s, l, p1 - 1), b = eval(s, p1 + 1, r);
            return min(a + b, 1001);
        }
        
        if (p2 != -1) {
            int a = eval(s, l, p2 - 1), b = eval(s, p2 + 1, r);
            return min(a * b, 1001);
        }
        
        return s[l] - '0';
    }
    
public:
    int scoreOfStudents(string &s, vector<int> &queries) {
        int correct = eval(s, 0, s.size() - 1);
        
        vector<vector<unordered_set<int>>> nums(s.size(), vector<unordered_set<int>>(s.size()));
        
        for (int i = 0; i < s.size(); i++)
            if (isdigit(s[i]))
                nums[i][i] = { s[i] - '0' };
        
        for (int len = 3; len <= s.size(); len += 2) {
            for (int l = 0, r = len - 1; r < s.size(); l += 2, r += 2) {
                for (int m = l + 1; m < r; m += 2) {
                    for (int a : nums[l][m - 1]) {
                        for (int b : nums[m + 1][r]) {
                            int n = s[m] == '+' ? a + b : a * b;
                            if (n <= 1000)
                                nums[l][r].insert(n);
                        }
                    }
                }
            }
        }
        
        int score = 0;
        for (int query : queries) {
            if (query == correct)
                score += 5;
            else if (nums[0][s.size() - 1].count(query))
                score += 2;
        }
        return score;
    }
};