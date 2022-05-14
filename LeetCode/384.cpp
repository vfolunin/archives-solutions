class Solution {
    inline static minstd_rand generator;
    vector<int> a;
    
public:
    Solution(vector<int> &a) : a(a) {}
    
    vector<int> reset() {
        return a;
    }
    
    vector<int> shuffle() {
        vector<int> res = a;
        for (int i = 0; i < a.size(); i++)
            swap(res[i], res[uniform_int_distribution<int>(0, i)(generator)]);
        return res;
    }
};