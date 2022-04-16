class Solution {
public:
    bool isAnagram(string a, string b) {
        vector<int> balance(26);
        for (char c : a)
            balance[c - 'a']++;
        for (char c : b)
            balance[c - 'a']--;
        return count(balance.begin(), balance.end(), 0) == balance.size();
    }
};