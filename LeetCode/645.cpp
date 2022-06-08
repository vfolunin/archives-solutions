class Solution {
public:
    vector<int> findErrorNums(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<int> res(2);
        for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] == a[i + 1])
                res[0] = a[i];
            if (a[i] + 1 < a[i + 1])
                res[1] = a[i] + 1;
        }
        
        if (!res[1])
            res[1] = a[0] == 1 ? (int)a.size() : 1;
        
        return res;
    }
};