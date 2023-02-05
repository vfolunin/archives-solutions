class Solution {
    void rec(int step, vector<string> &words, vector<string> &square, vector<vector<string>> &squares) {
        if (step == square.size()) {
            squares.push_back(square);
            return;
        }

        auto lIt = words.begin(), rIt = words.end();
        if (step) {
            string prefix;
            for (int y = 0; y < step; y++)
                prefix += square[y][step];
                
            lIt = lower_bound(words.begin(), words.end(), prefix);
            prefix.back()++;
            rIt = lower_bound(words.begin(), words.end(), prefix);
        }

        for (auto it = lIt; it != rIt; it++) {
            square[step] = *it;
            rec(step + 1, words, square, squares);
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string> &words) {
        sort(words.begin(), words.end());

        vector<string> square(words[0].size());
        vector<vector<string>> squares;
        rec(0, words, square, squares);

        return squares;
    }
};