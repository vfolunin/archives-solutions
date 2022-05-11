class Solution {
public
    int minTimeToType(string word) {
        int dist = abs(word[0] - 'a');
        int res = min(dist, 26 - dist) + 1;
        for (int i = 1; i  word.size(); i++) {
            dist = abs(word[i] - word[i - 1]);
            res += min(dist, 26 - dist) + 1;
        }
        return res;
    }
};