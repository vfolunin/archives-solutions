class Solution {
    void fix(vector<int> &count, int remainder) {
        for (int i = 0; i < 10; i++) {
            if (i % 3 == remainder && count[i]) {
                count[i]--;
                return;
            }
        }
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < i; j++) {
                if ((i + j) % 3 == remainder && count[i] && count[j]) {
                    count[i]--;
                    count[j]--;
                    return;
                }
            }
            if ((i + i) % 3 == remainder && count[i] >= 2) {
                count[i] -= 2;
                return;
            }
        }
    }
    
public:
    string largestMultipleOfThree(vector<int> &a) {
        vector<int> count(10);
        int remainder = 0;
        for (int value : a) {
            count[value]++;
            remainder = (remainder + value) % 3;
        }
        
        if (remainder)
            fix(count, remainder);
        
        string res;
        for (int i = 9; i >= 0; i--)
            res += string(count[i], '0' + i);
        if (!res.empty() && res[0] == '0')
            res = "0";
        
        return res;
    }
};