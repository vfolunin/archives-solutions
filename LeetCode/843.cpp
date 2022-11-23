class Solution {
    int getMatchCount(string &a, string &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] == b[i];
        return res;
    }
    
    int getMaxGroupSize(vector<string> &words, string &guess) {
        vector<int> groupSize(7);
        for (string &word : words)
            groupSize[getMatchCount(word, guess)]++;
        return *max_element(groupSize.begin(), groupSize.end());
    }
    
    string getGuess(vector<string> &words) {
        string guess = words[0];
        int guessScore = getMaxGroupSize(words, guess);
        
        for (int i = 1; i < words.size(); i++) {
            int score = getMaxGroupSize(words, words[i]);
            if (guessScore > score) {
                guessScore = score;
                guess = words[i];
            }
        }
        
        return guess;
    }
    
public:
    void findSecretWord(vector<string> &words, Master &master) {
        while (1) {
            string guess = getGuess(words);
            int matchCount = master.guess(guess);
            if (matchCount == 6)
                break;
            
            for (auto it = words.begin(); it != words.end(); ) {
                if (getMatchCount(*it, guess) == matchCount)
                    it++;
                else
                    it = words.erase(it);
            }
        }
    }
};