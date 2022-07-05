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
    vector<string> printVertically(string &s) {
        vector<string> words = split(s);
        
        int h = 0, w = words.size();
        for (string &word : words)
            h = max<int>(h, word.size());
        
        vector<string> res(h, string(w, ' '));
        for (int x = 0; x < w; x++)
            for (int y = 0; y < words[x].size(); y++)
                res[y][x] = words[x][y];
        
        for (string &row : res)
            while (row.back() == ' ')
                row.pop_back();
        
        return res;
    }
};