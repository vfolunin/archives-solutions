class Solution {
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights) {
        string res;
        for (string &word : words) {
            int sum = 0;
            for (char c : word)
                sum += weights[c - 'a'];
            res += 25 - sum % 26 + 'a';
        }
        return res;
    }
};