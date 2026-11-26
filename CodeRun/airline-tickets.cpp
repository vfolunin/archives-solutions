#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

vector<string> findPath(const string& start, const string& finish, auto getAdjacent) {
    unordered_map<string, string> from;
    queue<string> q;

    from[start];
    q.push(start);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        if (v == finish) {
            vector<string> path;
            for (string v = finish; !v.empty(); v = from[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const string &to : getAdjacent(v)) {
            if (!from.contains(to)) {
                from[to] = v;
                q.push(to);
            }
        }
    }

    return {};
}