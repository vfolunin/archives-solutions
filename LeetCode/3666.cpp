class Solution {
public:
    int minOperations(string &s, int delta) {
        int ones = count(s.begin(), s.end(), '1');

        vector<int> dist(s.size() + 1, 1e9);
        queue<int> q;
        vector<set<int>> unprocessed(2);
        for (int i = 0; i <= s.size(); i++)
            unprocessed[i % 2].insert(i);

        dist[ones] = 0;
        q.push(ones);
        unprocessed[ones % 2].erase(ones);

        while (!q.empty()) {
            int ones = q.front();
            q.pop();

            if (ones == s.size())
                return dist[ones];
                
            int lToOnes = ones + delta - 2 * min(ones, delta);
            int rToOnes = ones + delta - 2 * max(0, delta - ((int)s.size() - ones));

            set<int> &curUnprocessed = unprocessed[(ones + delta) % 2];
            auto lIt = curUnprocessed.lower_bound(lToOnes);
            auto rIt = curUnprocessed.upper_bound(rToOnes);

            for (auto it = lIt; it != rIt; it = curUnprocessed.erase(it)) {
                int toOnes = *it;
                dist[toOnes] = dist[ones] + 1;
                q.push(toOnes);
            }
        }

        return -1;
    }
};