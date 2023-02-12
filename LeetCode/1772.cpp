class Solution {
    unordered_set<string> split(string &line) {
        unordered_set<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.insert(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.insert(word);
        return words;
    }
    
public:
    vector<string> sortFeatures(vector<string> &features, vector<string> &responses) {
        unordered_map<string, int> votes;
        for (string &response : responses)
            for (const string &feature : split(response))
                votes[feature]++;
        
        stable_sort(features.begin(), features.end(), [&](const string &a, const string &b) {
            return votes[a] > votes[b];
        });
        return features;
    }
};