class Solution {
    vector<string> split(string &line, const string &separators) {
        vector<string> words;
        string word;
        for (char c : line) {
            if (separators.find(c) == -1) {
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
    int lengthLongestPath(string &input) {
        vector<string> parts = split(input, "\n");
        vector<int> stack;
        int sum = -1, res = 0;
        
        for (string &part : parts) {
            int level = count(part.begin(), part.end(), '\t');
            int size = part.size() - level;
            
            while (stack.size() > level) {
                sum -= stack.back();
                stack.pop_back();
            }
            stack.push_back(size + 1);
            sum += stack.back();
            
            if (part.find('.') != -1)
                res = max(res, sum);
        }
        
        return res;
    }
};