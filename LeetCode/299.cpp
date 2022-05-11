class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        
        vector<int> kSecret(10), kGuess(10);
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                kSecret[secret[i] - '0']++;
                kGuess[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < kSecret.size(); i++)
            cows += min(kSecret[i], kGuess[i]);
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};