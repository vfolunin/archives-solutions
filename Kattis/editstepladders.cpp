#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<string, int> dist;
    int res = 0;

    for (string s; cin >> s; ) {
        dist[s] = 1;

        for (int i = 0; i < s.size(); i++) {
            string candidate = s;
            candidate.erase(i, 1);
            if (auto it = dist.find(candidate); it != dist.end())
                dist[s] = max(dist[s], 1 + it->second);

            candidate = s;
            for (candidate[i] = 'a'; candidate[i] < s[i]; candidate[i]++)
                if (auto it = dist.find(candidate); it != dist.end())
                    dist[s] = max(dist[s], 1 + it->second);

            candidate = s;
            candidate.insert(candidate.begin() + i, 'a');
            for (candidate[i] = 'a'; candidate[i] <= s[i]; candidate[i]++)
                if (auto it = dist.find(candidate); it != dist.end())
                    dist[s] = max(dist[s], 1 + it->second);
        }

        res = max(res, dist[s]);
    }

    cout << res << "\n";
}