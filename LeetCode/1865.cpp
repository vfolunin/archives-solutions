class FindSumPairs {
    vector<int> a, b;
    unordered_map<int, int> bCount;
    
public:
    FindSumPairs(vector<int> &a, vector<int> &b) : a(a), b(b) {
        for (int value : b)
            bCount[value]++;
    }
    
    void add(int i, int delta) {
        bCount[b[i]]--;
        b[i] += delta;
        bCount[b[i]]++;
    }
    
    int count(int sum) {
        int res = 0;
        for (int value : a)
            res += bCount[sum - value];
        return res;
    }
};