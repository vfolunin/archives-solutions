class Solution {
public:
    string maximumXor(string &a, string &b) {
        vector<int> count(2);
        for (char c : b)
            count[c - '0']++;
        
        for (char &c : a) {
            if (count[(c - '0') ^ 1]) {
                count[(c - '0') ^ 1]--;
                c = '1';
            } else {
                count[c - '0']--;
                c = '0';
            }
        }

        return a;
    }
};