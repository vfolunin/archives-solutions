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
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> files;
        
        for (string &path : paths) {
            vector<string> tokens = split(path);
            for (int i = 1; i < tokens.size(); i++) {
                int from = tokens[i].find('(');
                string content = tokens[i].substr(from);
                string file = tokens[0] + "/" + tokens[i].substr(0, from);
                files[content].push_back(file);
            }
        }
        
        vector<vector<string>> res;
        for (auto &[content, files] : files)
            if (files.size() > 1)
                res.push_back(files);
        return res;
    }
};