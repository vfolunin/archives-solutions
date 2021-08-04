#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    string sl, sr;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        sl += c;
        sr += ('1' + i);
    }

    unordered_map<string, int> distL, distR;
    queue<string> ql, qr;

    distL[sl] = 0;
    ql.push(sl);
    distR[sr] = 0;
    qr.push(sr);

    cout << "Case " << test << ": ";
    if (sl == sr) {
        cout << "0\n";
        return 1;
    }

    for (int d = 0; 1; d++) {
        for (int turn = 0; turn < 2; turn++) {
            unordered_map<string, int> &dist = turn ? distR : distL;
            unordered_map<string, int> &otherDist = turn ? distL : distR;
            queue<string> &q = turn ? qr : ql;

            while (dist[q.front()] == d) {
                string v = q.front();
                q.pop();

                for (int len = 1; len <= v.size(); len++) {
                    for (int pos1 = 0; pos1 + len <= v.size(); pos1++) {
                        string part = v.substr(pos1, len);
                        string remains = v;
                        remains.erase(pos1, len);

                        for (int pos2 = 0; pos2 <= remains.size(); pos2++) {
                            string to = remains;
                            to.insert(pos2, part);

                            if (dist.count(to))
                                continue;

                            if (otherDist.count(to)) {
                                cout << dist[v] + 1 + otherDist[to] << "\n";
                                return 1;
                            }

                            dist[to] = dist[v] + 1;
                            q.push(to);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}