#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<string> &a, int y, int x) {
    queue<int> q;
    q.push(y);
    q.push(x);
    char c = a[y][x];
    a[y][x] = '#';

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = {  0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == c) {
                q.push(ty);
                q.push(tx);
                a[ty][tx] = '#';
            }
        }
    }
}

bool compare(pair<char, int> &a, pair<char, int> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    map<char, int> frequencyMap;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] != '#') {
                frequencyMap[a[y][x]]++;
                bfs(a, y, x);
            }
        }
    }

    vector<pair<char, int>> frequencyVector(frequencyMap.begin(), frequencyMap.end());
    sort(frequencyVector.begin(), frequencyVector.end(), compare);

    cout << "World #" << test << "\n";
    for (auto &[c, frequency] : frequencyVector)
        cout << c << ": " << frequency << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}