class Solution {
public:
    int longestPalindrome(vector<string> &words) {
        unordered_map<string, int> count;
        for (string &word : words)
            count[word]++;
        
        int res = 0;
        
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = a + 1; b <= 'z'; b++) {
                string ab = string(1, a) + b;
                string ba = string(1, b) + a;
                res += 4 * min(count[ab], count[ba]);
            }
        }
        
        int odd = 0;
        
        for (char a = 'a'; a <= 'z'; a++) {
            string aa(2, a);
            res += count[aa] / 2 * 4;
            odd |= count[aa] % 2;
        }
        
        return res + odd * 2;
    }
};