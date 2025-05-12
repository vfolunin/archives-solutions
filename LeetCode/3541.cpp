class Solution {
public:
    int maxFreqSum(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        string vowels = "aeiou";
        vector<int> maxCount(2);
        for (int i = 0; i < count.size(); i++) {
            int type = vowels.find('a' + i) != -1;
            maxCount[type] = max(maxCount[type], count[i]);
        }
        return maxCount[0] + maxCount[1];
    }
};