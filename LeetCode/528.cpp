class Solution {
    vector<int> p;
    
public:
    Solution(vector<int> &w) : p(w) {
        partial_sum(p.begin(), p.end(), p.begin());
    }
    
    int pickIndex() {
        static minstd_rand gen;
        int x = uniform_int_distribution<int>(0, p.back() - 1)(gen);
        return upper_bound(p.begin(), p.end(), x) - p.begin();
    }
};