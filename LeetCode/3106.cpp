class Solution {
    int getDist(char a, char b) {
        int dist = abs(a - b);
        return min(dist, 26 - dist);
    }

public:
    string getSmallestString(string &s, int limit) {
        string res = s;
        for (int i = 0; i < res.size(); i++) {
            for (res[i] = 'a'; res[i] <= s[i]; res[i]++) {
                int dist = getDist(res[i], s[i]);
                if (limit >= dist) {
                    limit -= dist;
                    break;
                }
            }
        }
        return res;
    }
};