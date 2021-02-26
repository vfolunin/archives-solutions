#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

bool solve() {
    int studentCount, groupCount;
    cin >> studentCount >> groupCount;

    if (!studentCount && !groupCount)
        return 0;

    DSU dsu(studentCount);
    
    for (int i = 0; i < groupCount; i++) {
        int groupSize, groupRep;
        cin >> groupSize >> groupRep;

        for (int i = 1; i < groupSize; i++) {
            int student;
            cin >> student;
            dsu.merge(groupRep, student);
        }
    }

    int res = 0;
    for (int i = 0; i < studentCount; i++)
        res += dsu.connected(i, 0);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}