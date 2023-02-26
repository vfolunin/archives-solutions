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
    int minimumCost(string &line, int width) {
        vector<int> sizes;
        for (string &word : split(line))
            sizes.push_back(word.size());

        vector<int> cost(sizes.size() + 1, 1e9);
        cost[0] = 0;

        for (int i = 1; i <= sizes.size(); i++) {
            int rowSize = 0;
            for (int j = i; j; j--) {
                if (rowSize + (rowSize > 0) + sizes[j - 1] <= width) {
                    rowSize += (rowSize > 0) + sizes[j - 1];
                    cost[i] = min(cost[i], cost[j - 1] + (i < sizes.size() ? (width - rowSize) * (width - rowSize) : 0));
                } else {
                    break;
                }
            }
        }

        return cost.back();
    }
};