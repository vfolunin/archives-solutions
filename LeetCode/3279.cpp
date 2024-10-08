class Solution {
public:
    long long maxArea(int limit, vector<int> &a, string &s) {
        int time = 0;
        long long cur = accumulate(a.begin(), a.end(), 0LL);
        long long res = cur;

        deque<int> up, down;
        for (int i = 0; i < a.size(); i++) {
            if (s[i] == 'U')
                up.push_back(limit - a[i]);
            else
                down.push_back(a[i]);
        }
        sort(up.begin(), up.end());
        sort(down.begin(), down.end());

        for (int i = 0; i < 2 * a.size(); i++) {
            if (down.empty() || !up.empty() && up[0] <= down[0]) {
                int deltaTime = up[0] - time;
                cur += deltaTime * (long long)(up.size() - down.size());
                res = max(res, cur);
                time = up[0];
                up.pop_front();
                down.push_back(time + limit);
            } else {
                int deltaTime = down[0] - time;
                cur += deltaTime * (long long)(up.size() - down.size());
                res = max(res, cur);
                time = down[0];
                down.pop_front();
                up.push_back(time + limit);
            }
        }

        return res;
    }
};