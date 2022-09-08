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

    string join(vector<string> &words) {
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? " " : "");
        return line;
    }
    
    double parsePrice(string &s) {
        if (s.size() <= 1 || s[0] != '$')
            return -1;
        
        double res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (!isdigit(s[i]))
                return -1;
            res = res * 10 + s[i] - '0';
        }
        return res;
    }
    
public:
    string discountPrices(string &line, int discount) {
        vector<string> words = split(line);
        for (string &word : words) {
            if (double price = parsePrice(word); price != -1) {
                stringstream ss;
                ss.precision(2);
                ss << "$" << fixed << price * (100 - discount) / 100;
                word = ss.str();
            }
        }
        return join(words);
    }
};