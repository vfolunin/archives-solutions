class Solution {
    vector<string> split(string &line) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }
    
public:
    vector<int> topStudents(vector<string> &positive, vector<string> &negative, vector<string> &report, vector<int> &id, int k) {
        unordered_set<string> positiveSet = { positive.begin(), positive.end() };
        unordered_set<string> negativeSet = { negative.begin(), negative.end() };

        vector<pair<int, int>> score(report.size());
        for (int i = 0; i < score.size(); i++) {
            for (string &word : split(report[i])) {
                if (positiveSet.count(word))
                    score[i].first += 3;
                if (negativeSet.count(word))
                    score[i].first--;
                score[i].second = id[i];
            }
        }

        partial_sort(score.begin(), score.begin() + k, score.end(), [](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        vector<int> res(k);
        for (int i = 0; i < k; i++)
            res[i] = score[i].second;
        return res;
    }
};