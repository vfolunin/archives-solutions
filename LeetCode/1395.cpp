struct BIT {
    vector<int> f;

    BIT(int size) : f(size) {}

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    int sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }
};

class Solution {
public:
    int numTeams(vector<int> &a) {
        const int SIZE = 1e5 + 1;
        
        BIT l(SIZE), r(SIZE);
        for (int value : a)
            r.add(value, 1);
        
        int res = 0;
        for (int value : a) {
            r.add(value, -1);
            
            res += l.sum(0, value - 1) * r.sum(value + 1, SIZE - 1);
            res += l.sum(value + 1, SIZE - 1) * r.sum(0, value - 1);
            
            l.add(value, 1);
        }
        
        return res;
    }
};