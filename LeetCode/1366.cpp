class Solution {
public:
    string rankTeams(vector<string> &votes) {
        vector<vector<int>> score(26, vector<int>(votes[0].size()));
        for (string &vote : votes)
            for (int i = 0; i < vote.size(); i++)
                score[vote[i] - 'A'][i]++;
        
        string res = votes[0];
        sort(res.begin(), res.end(), [&](char a, char b) {
            if (score[a - 'A'] != score[b - 'A'])
                return score[a - 'A'] > score[b - 'A'];
            return a < b;
        });
        return res;
    }
};