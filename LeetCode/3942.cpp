class Solution {
public:
    int minOperations(vector<int> &a) {
        vector<vector<int>> dist(a.size(), vector<int>(2, 1e9));
        queue<pair<int, int>> q;

        int zeroIndex = find(a.begin(), a.end(), 0) - a.begin();

        bool isSorted = 1;
        for (int i = 0; i < a.size(); i++)
            isSorted &= (a[i] + 1) % a.size() == a[(i + 1) % a.size()];
        
        if (isSorted) {
            dist[zeroIndex][0] = 0;
            q.push({ zeroIndex, 0 });
        }

        isSorted = 1;
        for (int i = 0; i < a.size(); i++)
            isSorted &= (a[i] + a.size() - 1) % a.size() == a[(i + 1) % a.size()];
        
        if (isSorted) {
            dist[zeroIndex][1] = 0;
            q.push({ zeroIndex, 1 });
        }

        while (!q.empty()) {
            auto [zeroIndex, reversed] = q.front();
            q.pop();

            if (!zeroIndex && !reversed)
                return dist[0][0];

            vector<pair<int, int>> to = {
                { (zeroIndex + a.size() - 1) % a.size(), reversed },
                { a.size() - 1 - zeroIndex, !reversed }
            };

            for (auto &[toZeroIndex, toReversed] : to) {
                if (dist[toZeroIndex][toReversed] > dist[zeroIndex][reversed] + 1) {
                    dist[toZeroIndex][toReversed] = dist[zeroIndex][reversed] + 1;
                    q.push({ toZeroIndex, toReversed });
                }
            }
        }

        return -1;
    }
};