class Solution {
public:
    int sortArray(vector<int> &a, vector<int> &moves) {
        map<vector<int>, int> dist;
        queue<vector<int>> q;

        dist[a] = 0;
        q.push(a);

        while (!q.empty()) {
            vector<int> a = q.front();
            q.pop();

            if (is_sorted(a.begin(), a.end()))
                return dist[a];
            
            for (int move : moves) {
                vector<int> b = a;
                reverse(b.begin(), b.begin() + move);
                if (!dist.contains(b)) {
                    dist[b] = dist[a] + 1;
                    q.push(b);
                }
            }
        }

        return -1;
    }
};