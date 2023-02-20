class Solution {
public:
    string rearrangeString(string &s, int k) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        vector<int> last(26, -1e9);
        string res;

        for (int i = 0; i < s.size(); i++) {
            int bestC = -1;
            for (int c = 0; c < count.size(); c++)
                if (count[c] && last[c] + k <= i && (bestC == -1 || count[bestC] < count[c]))
                    bestC = c;
            
            if (bestC == -1)
                return "";
            
            count[bestC]--;
            last[bestC] = i;
            res += bestC + 'a';
        }

        return res;
    }
};