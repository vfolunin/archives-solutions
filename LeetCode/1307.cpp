class Solution {
        bool rec(vector<string> &words, int y, int x, int colSum, vector<int> &code, vector<int> &used) {
        if (x == words[0].size())
            return !colSum;

        if (y == words.size())
            return colSum % 10 ? 0 : rec(words, 0, x + 1, colSum / 10, code, used);

        if (words[y][x] == ' ')
            return rec(words, y + 1, x, colSum, code, used);

        if (code[words[y][x] - 'A'] != -1) {
            if (!code[words[y][x] - 'A'] && x && (x + 1 == words[0].size() || words[y][x + 1] == ' '))
                return 0;

            int value = code[words[y][x] - 'A'] * (y + 1 < words.size() ? 1 : -1);
            return rec(words, y + 1, x, colSum + value, code, used);
        }

        for (int digit = 0; digit < 10; digit++) {
            if (used[digit] || !digit && x && (x + 1 == words[0].size() || words[y][x + 1] == ' '))
                continue;

            code[words[y][x] - 'A'] = digit;
            used[digit] = 1;

            int value = digit * (y + 1 < words.size() ? 1 : -1);
            if (rec(words, y + 1, x, colSum + value, code, used))
                return 1;

            code[words[y][x] - 'A'] = -1;
            used[digit] = 0;
        }

        return 0;
    }
    
public:
    bool isSolvable(vector<string> &words, string &result) {
        words.push_back(result);
        int maxWidth = result.size();
        
        for (string &word : words) {
            reverse(word.begin(), word.end());
            maxWidth = max<int>(maxWidth, word.size());
        }
        
        for (string &word : words)
            word.resize(maxWidth, ' ');
        
        vector<int> code(26, -1);
        vector<int> used(10);
        return rec(words, 0, 0, 0, code, used);
    }
};