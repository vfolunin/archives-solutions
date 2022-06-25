class Solution {
public:
    vector<int> findDuplicates(vector<int> &a) {
        for (int &value : a)
            value--;
        
        for (int i = 0; i < a.size(); i++)
            while (a[i] != a[a[i]])
                swap(a[i], a[a[i]]);
        
        vector<int> res;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != i)
                res.push_back(a[i] + 1);
        return res;
    }
};