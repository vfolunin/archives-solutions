struct Counter {
    map<int, int> count;
    
    void add(int value, int delta) {
        count[value] += delta;
        if (!count[value])
            count.erase(value);
    }
    
    bool ok() {
        return count.empty() || prev(count.end())->first - count.begin()->first <= 2;
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int> &a) {
        long long res = 0;
        
        Counter counter;
        for (int l = 0, r = 0; r < a.size(); r++) {
            counter.add(a[r], 1);
            
            while (!counter.ok()) {
                counter.add(a[l], -1);
                l++;
            }

            res += r - l + 1;
        }
        
        return res;
    }
};