class Solution {
    bool isPalindrome(string &s, int l, int r) {
        for (; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
    void rec(string &s, int l, vector<string> &partition, vector<vector<string>> &partitions) {
        if (l == s.size()) {
            partitions.push_back(partition);
            return;
        }
        
        for (int r = l; r < s.size(); r++) {
            if (isPalindrome(s, l, r)) {
                partition.push_back(s.substr(l, r - l + 1));
                rec(s, r + 1, partition, partitions);
                partition.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> partitions;
        rec(s, 0, partition, partitions);
        return partitions;
    }
};