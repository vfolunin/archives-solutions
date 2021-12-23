#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getSymbolWeight(char symbol) {
    int res = 1;
    while (symbol > 'A') {
        symbol--;
        res *= 10;
    }
    return res;
}

int getHeuristic(vector<string> &v) {
    int res = 0;
    for (int y = 1; y < 3; y++)
        for (int x = 2, c = 'A'; x < 9; x += 2, c++)
            if (v[y][x] != c)
                res += getSymbolWeight(c);
    return res;
}

int getMoveValue(vector<string> &v, int y1, int x1, int y2, int x2) {
    if (y1)
        return getMoveValue(v, y2, x2, y1, x1);

    int y = y1, x = x1, res = 0;

    while (x != x2) {
        if ((y != y1 || x != x1) && (y != y2 || x != x2) && v[y][x] != '.')
            return -1;

        x += x < x2 ? 1 : -1;
        res++;
    }

    while (y != y2) {
        if ((y != y1 || x != x1) && (y != y2 || x != x2) && v[y][x] != '.')
            return -1;

        y++;
        res++;
    }

    return res;
}

int aStar(vector<string> &start) {
    map<vector<string>, int> dist, distH;
    set<pair<int, vector<string>>> q;

    dist[start] = 0;
    distH[start] = getHeuristic(start);
    q.insert({ distH[start], start });

    while (!q.empty()) {
        vector<string> v = q.begin()->second;
        q.erase(q.begin());

        static vector<string> target = {
            "...........",
            "##A#B#C#D##",
            " #A#B#C#D#",
        };

        if (v == target)
            return dist[v];

        int y1 = 0;
        for (int x1 = 0; x1 < 11; x1++) {
            if (!isalpha(v[y1][x1]))
                continue;

            int y2 = 1, x2 = 2 + 2 * (v[y1][x1] - 'A');
            if (v[y2][x2] != '.' || v[y2 + 1][x2] != '.' && v[y2 + 1][x2] != v[y1][x1])
                continue;
            if (v[y2 + 1][x2] == '.')
                y2++;

            int w = getMoveValue(v, y1, x1, y2, x2) * getSymbolWeight(v[y1][x1]);
            if (w < 0)
                continue;

            vector<string> to = v;
            swap(to[y1][x1], to[y2][x2]);

            if (!dist.count(to) || dist[to] > dist[v] + w) {
                q.erase({ distH[to], to });
                dist[to] = dist[v] + w;
                distH[to] = dist[to] + getHeuristic(to);
                q.insert({ distH[to], to });
            }
        }

        for (int y1 = 1; y1 < 3; y1++) {
            for (int x1 = 2; x1 < 9; x1 += 2) {
                if (!isalpha(v[y1][x1]))
                    continue;

                int y2 = 0;
                for (int x2 = 0; x2 < 11; x2++) {
                    if (v[y2][x2] != '.' || 2 <= x2 && x2 <= 8 && x2 % 2 == 0)
                        continue;

                    int w = getMoveValue(v, y1, x1, y2, x2) * getSymbolWeight(v[y1][x1]);
                    if (w < 0)
                        continue;

                    vector<string> to = v;
                    swap(to[y1][x1], to[y2][x2]);

                    if (!dist.count(to) || dist[to] > dist[v] + w) {
                        q.erase({ distH[to], to });
                        dist[to] = dist[v] + w;
                        distH[to] = dist[to] + getHeuristic(to);
                        q.insert({ distH[to], to });
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> input(5);
    for (string &line : input)
        getline(cin, line);

    vector<string> start = {
        input[1].substr(1, 11),
        input[2].substr(1, 11),
        input[3].substr(1, 10)
    };
    cout << aStar(start);
}