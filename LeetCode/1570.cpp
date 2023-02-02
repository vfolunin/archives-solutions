class SparseVector {
    unordered_map<int, int> values;

public:    
    SparseVector(vector<int> &a) {
        for (int i = 0; i < a.size(); i++)
            if (a[i])
                values[i] = a[i];
    }

    int dotProduct(SparseVector &that) {
        int res = 0;
        for (auto &[i, value] : values)
            if (auto it = that.values.find(i); it != that.values.end())
                res += value * it->second;
        return res;
    }
};