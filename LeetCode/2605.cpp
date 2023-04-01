class Solution {
public:
    int minNumber(vector<int> &a, vector<int> &b) {
        for (int i = 1; i < 10; i++)
            if (find(a.begin(), a.end(), i) != a.end() &&
                find(b.begin(), b.end(), i) != b.end())
                return i;
        
        int ma = *min_element(a.begin(), a.end());
        int mb = *min_element(b.begin(), b.end());
        if (ma > mb)
            swap(ma, mb);
        return ma * 10 + mb;
    }
};