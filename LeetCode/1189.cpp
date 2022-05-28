class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26);
        for (char c : text)
            count[c - 'a']++;
        
        return min({
            count['a' - 'a'],
            count['b' - 'a'],
            count['l' - 'a'] / 2,
            count['n' - 'a'],
            count['o' - 'a'] / 2 }
        );
    }
};