class Solution {
public:
    int countPoints(string rings) {
        vector<set<char>> colors(10);
        for (int i = 0; i < rings.size(); i += 2)
            colors[rings[i + 1] - '0'].insert(rings[i]);
        
        int res = 0;
        for (set<char> &c : colors)
            res += c.size() == 3;
        return res;
    }
};