class Solution {
public:
    long long totalCost(vector<int> &a, int k, int width) {
        set<pair<int, int>> q;
        for (int i = 0; i < width; i++) {
            q.insert({ a[i], i });
            q.insert({ a[a.size() - 1 - i], a.size() - 1 - i });
        }
        
        int l = width - 1, r = a.size() - width;
        long long res = 0;
        
        for (int i = 0; i < k; i++) {
            auto [value, index] = *q.begin();
            q.erase(q.begin());
            
            res += value;
            a[index] = -1;
            
            if (index <= l) {
                do {
                    l++;
                } while (l < a.size() && a[l] == -1);
                if (l < a.size())
                    q.insert({ a[l], l });
            }
            if (index >= r) {
                do {
                    r--;
                } while (r >= 0 && a[r] == -1);
                if (r >= 0)
                    q.insert({ a[r], r });
            }
        }
        
        return res;
    }
};