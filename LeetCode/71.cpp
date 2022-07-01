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

    string join(vector<string> &words, const string &separator) {
        string line;
        for (int i = 0; i < words.size(); i++)
            line += words[i] + (i + 1 < words.size() ? separator : "");
        return line;
    }
    
public:
    string simplifyPath(string path) {
        vector<string> stack;
        for (const string &part : split(path, "/")) {
            if (part == "..") {
                if (!stack.empty())
                    stack.pop_back();
            } else if (part != "" && part != ".") {
                stack.push_back(part);
            }
        }
        
        return "/" + join(stack, "/");
    }
};