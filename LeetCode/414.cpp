class Solution {
public:
    int thirdMax(vector<int> &a) {
        int m0 = *max_element(a.begin(), a.end());
        a.erase(remove(a.begin(), a.end(), m0), a.end());
        
        if (!a.empty()) {
            int m1 = *max_element(a.begin(), a.end());
            a.erase(remove(a.begin(), a.end(), m1), a.end());
        }
        
        if (!a.empty())
            return *max_element(a.begin(), a.end());
        
        return m0;
    }
};