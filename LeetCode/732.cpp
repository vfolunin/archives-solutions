class MyCalendarThree {
    map<int, int> delta;
    
public:    
    int book(int l, int r) {
        delta[l]++;
        delta[r]--;
        
        int cur = 0, res = 0;
        for (auto &[x, delta] : delta) {
            cur += delta;
            res = max(res, cur);
        }
        return res;
    }
};