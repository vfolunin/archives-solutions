class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiou";

        unordered_map<char, int> count, firstPos;
        string sortedVowels;
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != -1) {
                count[s[i]]++;
                if (!firstPos.count(s[i]))
                    firstPos[s[i]] = i;
                sortedVowels += s[i];
            }
        }

        sort(sortedVowels.begin(), sortedVowels.end(), [&](char l, char r) {
            if (count[l] != count[r])
                return count[l] > count[r];
            return firstPos[l] < firstPos[r];
        });

        for (int i = 0, j = 0; i < s.size(); i++)
            if (vowels.find(s[i]) != -1)
                s[i] = sortedVowels[j++];
        return s;
    }
};