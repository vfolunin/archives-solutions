class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        vector<string> digits(2);
        for (char d : s)
            digits[d % 2] += d;
        
        for (string &d : digits)
            sort(d.begin(), d.end());
        
        for (char &c : s) {
            auto &d = digits[c % 2];
            c = d.back();
            d.pop_back();
        }
        
        return stoi(s);
    }
};