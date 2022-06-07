class Solution {
public:
    int dominantIndex(vector<int> &a) {
        int m = max_element(a.begin(), a.end()) - a.begin();
        
        for (int i = 0; i < a.size(); i++)
            if (i != m && a[i] * 2 > a[m])
                return -1;
        
        return m;
    }
};