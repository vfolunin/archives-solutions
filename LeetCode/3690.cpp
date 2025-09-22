class Solution {
public:
    int minSplitMerge(vector<int> &a, vector<int> &b) {
        map<vector<int>, int> dist;
        queue<vector<int>> q;

        dist[a] = 0;
        q.push(a);

        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();

            if (v == b)
                return dist[v];
            
            for (int l = 0; l < v.size(); l++) {
                for (int r = l; r < v.size(); r++) {
                    vector<int> extracted(v.begin() + l, v.begin() + r + 1);
                    vector<int> remaining(v.begin(), v.begin() + l);
                    remaining.insert(remaining.end(), v.begin() + r + 1, v.end());

                    for (int start = 0; start <= remaining.size(); start++) {
                        vector<int> to = remaining;
                        to.insert(to.begin() + start, extracted.begin(), extracted.end());

                        if (!dist.count(to)) {
                            dist[to] = dist[v] + 1;
                            q.push(to);
                        }
                    }
                }
            }
        }

        return -1;
    }
};