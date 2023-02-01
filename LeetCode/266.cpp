class Solution {
public:
    bool canPermutePalindrome(string &s) {
        vector<int> oddCount(26);
        for (char c : s)
            oddCount[c - 'a'] ^= 1;

        return count(oddCount.begin(), oddCount.end(), 1) <= 1;
    }
};