class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26);
        for (char c : magazine)
            count[c - 'a']++;
        for (char c : ransomNote)
            count[c - 'a']--;
        return *min_element(count.begin(), count.end()) >= 0;
    }
};