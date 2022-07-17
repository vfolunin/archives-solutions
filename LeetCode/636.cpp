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
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> res, stack;
        int prevTime;
        
        for (string &log : logs) {
            vector<string> tokens = split(log, ":");
            
            int id = stoi(tokens[0]), time = stoi(tokens[2]) + (tokens[1] == "end");
            if (res.size() <= id)
                res.resize(id + 1);
            
            if (!stack.empty())
                res[stack.back()] += time - prevTime;
            
            if (tokens[1] == "start")
                stack.push_back(id);
            else
                stack.pop_back();
            
            prevTime = time;
        }
        
        return res;
    }
};