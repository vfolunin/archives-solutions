class Solution {
public:
    string findContestMatch(int n) {
        vector<string> round(n);
        for (int i = 0; i < n; i++)
            round[i] = to_string(i + 1);
        
        while (round.size() > 1) {
            vector<string> nextRound;
            for (int l = 0, r = round.size() - 1; l < r; l++, r--)
                nextRound.push_back("(" + round[l] + "," + round[r] + ")");
            round.swap(nextRound);
        }

        return round[0];
    }
};