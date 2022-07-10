class Solution {
public:
    int minStoneSum(vector<int> &a, int k) {
        priority_queue<int> q(a.begin(), a.end());
        
        for (int i = 0; i < k; i++) {
            int value = q.top();
            q.pop();
            value -= value / 2;
            if (value)
                q.push(value);
        }
        
        int res = 0;
        while (!q.empty()) {
            res += q.top();
            q.pop();
        }
        
        return res;
    }
};