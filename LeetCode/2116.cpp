class Solution {
public:
    bool canBeValid(string &s, string &locked) {
        if (s.size() % 2)
            return 0;
        
        vector<int> openPos, questionPos;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                questionPos.push_back(i);
            } else if (s[i] == '(') {
                openPos.push_back(i);
            } else {
                if (!openPos.empty())
                    openPos.pop_back();
                else if (!questionPos.empty())
                    questionPos.pop_back();
                else
                    return 0;
            }
        }
        
        while (!openPos.empty()) {
            if (questionPos.empty() || questionPos.back() < openPos.back())
                return 0;
            openPos.pop_back();
            questionPos.pop_back();
        }
        
        return 1;
    }
};