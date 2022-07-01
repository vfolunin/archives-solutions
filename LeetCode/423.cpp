class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        vector<vector<string>> data = {
            { "z", "zero", "0" },    
            { "w", "two", "2" },
            { "u", "four", "4" },
            { "x", "six", "6" },
            { "g", "eight", "8" },
            { "o", "one", "1" },
            { "t", "three", "3" },
            { "f", "five", "5" },
            { "s", "seven", "7" },
            { "e", "nine", "9" },
        };
        
        string res;
        
        for (vector<string> &data : data) {
            int digitCount = count[data[0][0] - 'a'];
            res += string(digitCount, data[2][0]);
            for (char c : data[1])
                count[c - 'a'] -= digitCount;            
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};