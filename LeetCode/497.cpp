class Solution {
    vector<vector<int>> rects;
    vector<long long> p;
    
public:
    Solution(vector<vector<int>> &rects) : rects(rects) {
        for (vector<int> &rect : rects) {
            long long dx = rect[2] - rect[0] + 1;
            long long dy = rect[3] - rect[1] + 1;
            p.push_back(dx * dy + (p.empty() ? 0 : p.back()));
        }
    };
    
    vector<int> pick() {
        static minstd_rand gen;

        int r = uniform_int_distribution<int>(0, p.back() - 1)(gen);
        int i = upper_bound(p.begin(), p.end(), r) - p.begin();
        
        int x = uniform_int_distribution<int>(rects[i][0], rects[i][2])(gen);
        int y = uniform_int_distribution<int>(rects[i][1], rects[i][3])(gen);
        
        return { x, y };
    }
};