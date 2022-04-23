class Solution {
public:
    char findTheDifference(string a, string b) {
        vector<int> count(26);
        for (char c : b)
            count[c - 'a']++;
        for (char c : a)
            count[c - 'a']--;
        return find(count.begin(), count.end(), 1) - count.begin() + 'a';
    }
};