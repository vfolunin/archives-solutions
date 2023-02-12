class Solution {
public:
    long long findTheArrayConcVal(vector<int> &a) {
        long long res = 0;

        for (int l = 0, r = a.size() - 1; l < r; l++, r--)
            res += stoi(to_string(a[l]) + to_string(a[r]));

        if (a.size() % 2)
            res += a[a.size() / 2];
        
        return res;
    }
};