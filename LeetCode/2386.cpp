class Solution {
public:
    long long kSum(vector<int> &a, int k) {
        long long sum = 0;
        for (int &value : a) {
            if (value > 0)
                sum += value;
            else
                value = -value;
        }
        
        if (k == 1)
            return sum;
        k--;

        sort(a.begin(), a.end());
        priority_queue<pair<long long, int>> q;
        q.push({ sum - a[0], 0 });

        for (int i = 0; i < k - 1; i++) {
            auto [sum, index] = q.top();
            q.pop();

            if (index + 1 < a.size()) {
                q.push({ sum - a[index + 1], index + 1 });
                q.push({ sum + a[index] - a[index + 1], index + 1 });
            }
        }

        return q.top().first;
    }
};