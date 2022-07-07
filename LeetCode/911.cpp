class TopVotedCandidate {
    vector<pair<int, int>> winner;
    
public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) {
        vector<int> count(5001);
        int maxCount = 0;
        
        for (int i = 0; i < persons.size(); i++) {
            count[persons[i]]++;
            if (maxCount <= count[persons[i]]) {
                maxCount = count[persons[i]];
                winner.push_back({ times[i], persons[i] });
            }
        }
    }
    
    int q(int t) {
        return prev(upper_bound(winner.begin(), winner.end(), make_pair(t + 1, -1)))->second;
    }
};