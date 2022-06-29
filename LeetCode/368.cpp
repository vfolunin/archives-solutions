class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<int> size(a.size(), 1), from(a.size(), -1);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] % a[j] == 0 && size[i] < size[j] + 1) {
                    size[i] = size[j] + 1;
                    from[i] = j;
                }
            }
        }
        
        vector<int> res;
        for (int i = max_element(size.begin(), size.end()) - size.begin(); i != -1; i = from[i])
            res.push_back(a[i]);
        
        return res;
    }
};