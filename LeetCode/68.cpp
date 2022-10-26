class Solution {
    string left(vector<string> &words, int width) {
        string res;
        for (int i = 0; i < words.size(); i++) {
            res += words[i];
            if (i + 1 < words.size())
                res += " ";
        }
        return res + string(width - res.size(), ' ');
    }
    
    string justify(vector<string> &words, int width) {
        if (words.size() == 1)
            return left(words, width);
        
        for (string &word : words)
            width -= word.size();
        
        vector<int> gaps(words.size() - 1, width / (words.size() - 1));
        for (int i = 0; i < width % (words.size() - 1); i++)
            gaps[i]++;
        
        string res;
        for (int i = 0; i < words.size(); i++) {
            res += words[i];
            if (i < gaps.size())
                res += string(gaps[i], ' ');
        }
        return res;
    }

public:
    vector<string> fullJustify(vector<string> &words, int width) {
        vector<string> lineWords, res;
        int lineWidth = 0;
        
        for (string &word : words) {
            if (lineWidth + (lineWidth > 0) + word.size() <= width) {
                lineWords.push_back(word);
                lineWidth += (lineWidth > 0) + word.size();
            } else {
                res.push_back(justify(lineWords, width));
                lineWords = { word };
                lineWidth = word.size();
            }
        }
        res.push_back(left(lineWords, width));
        
        return res;
    }
};