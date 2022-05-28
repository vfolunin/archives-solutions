class Solution {
    string digitSum(string &s) {
        int res = 0;
        for (char c : s)
            res += c - '0';
        return to_string(res);
    }
    
public:
    int getLucky(string s, int k) {
        string res;
        for (char c : s)
            res += to_string(c - 'a' + 1);
        
        for (int i = 0; i < k; i++)
            res = digitSum(res);
        
        return stoi(res);
    }
};