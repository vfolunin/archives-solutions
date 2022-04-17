class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &a) {
        vector<int> res(a.size());
        iota(res.begin(), res.end(), 1);
        
        for (int value : a)
            res[value - 1] = 0;
        res.erase(remove(res.begin(), res.end(), 0), res.end());
        
        return res;
    }
};