class Solution {
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        vector<int> haveLetters(26);
        for (char c : letters)
            haveLetters[c - 'a']++;
        
        int res = 0;
        
        for (int mask = 0; mask < (1 << words.size()); mask++) {
            vector<int> needLetters(26);
            int totalScore = 0;
            
            for (int bit = 0; bit < words.size(); bit++) {
                if (mask & (1 << bit)) {
                    for (char c : words[bit]) {
                        needLetters[c - 'a']++;
                        totalScore += score[c - 'a'];
                    }
                }
            }
            
            bool ok = 1;
            for (int i = 0; i < 26 && ok; i++)
                ok &= needLetters[i] <= haveLetters[i];
            
            if (ok)
                res = max(res, totalScore);                
        }
        
        return res;
    }
};