#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    queue<int> q;
    for (int j = 0; j < size; j++) {
        if (a[0][j] == 'b') {
            q.push(0);
            q.push(j);
            a[0][j] = 'x';
        }
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();

        if (i == size - 1) {
            cout << test << " B\n";
            return 1;
        }

        static int di[] = { -1, 0, 1, 0, -1, 1 };
        static int dj[] = { 0, 1, 0, -1, -1, 1 };

        for (int d = 0; d < 6; d++) {
            int ti = i + di[d], tj = j + dj[d];
            if (0 <= ti && ti < size && 0 <= tj && tj < size && a[ti][tj] == 'b') {
                q.push(ti);
                q.push(tj);
                a[ti][tj] = 'x';
            }
        }
    }

    cout << test << " W\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}