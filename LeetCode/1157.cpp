class MajorityChecker {
    inline static minstd_rand gen;
    vector<int> a;
    unordered_map<int, vector<int>> pos;
    
public:
    MajorityChecker(vector<int> &a) : a(a) {
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
    }
    
    int query(int l, int r, int threshold) {
        uniform_int_distribution<int> distr(l, r);
        for (int i = 0; i < 10; i++) {
            int value = a[distr(gen)];
            auto lIt = lower_bound(pos[value].begin(), pos[value].end(), l);
            auto rIt = upper_bound(pos[value].begin(), pos[value].end(), r);
            if (rIt - lIt >= threshold)
                return value;
        }
        return -1;
    }
};