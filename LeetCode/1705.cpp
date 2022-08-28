class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        map<int, int> q;
        int res = 0;
        
        for (int i = 0; i < apples.size(); i++) {
            q[i + days[i]] += apples[i];
            
            while (!q.empty() && q.begin()->first <= i)
                q.erase(q.begin());
            
            if (!q.empty()) {
                if (!--q.begin()->second)
                    q.erase(q.begin());
                res++;
            }
        }
        
        for (int i = apples.size(); !q.empty(); ) {
            auto [deadline, count] = *q.begin();
            q.erase(q.begin());
            
            int delta = min(deadline - i, count);
            res += delta;
            i += delta;
        }
        
        return res;
    }
};