class Solution {
public:
    int lastStoneWeight(vector<int> &a) {
        priority_queue<int> q(a.begin(), a.end());
        
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b)
                q.push(a - b);
        }
        
        return q.empty() ? 0 : q.top();
    }
};