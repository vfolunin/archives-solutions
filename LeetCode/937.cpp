class Solution {
    static bool compare(const string &a, const string &b) {
        if (isalpha(a.back()) && isdigit(b.back()))
            return 1;
        if (isalpha(a.back()) && isalpha(b.back())) {
            string aContents = a.substr(a.find(' '));
            string bContents = b.substr(b.find(' '));
            return aContents < bContents || aContents == bContents && a < b;            
        }
        return 0;
    }
    
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }
};