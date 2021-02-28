#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    set<char> vertices;
    vector<pair<char, char>> edges;

    while (1) {
        char v;
        cin >> v;
        vertices.insert(v);
        cin.ignore();

        if (v == '#')
            return 0;

        char to;
        while (isalpha(cin.peek())) {
            cin >> to;
            vertices.insert(to);
            edges.emplace_back(v, to);
        }

        if (cin.peek() == '\n')
            break;
        cin.ignore();
    }

    string order(vertices.begin(), vertices.end()), bestOrder;
    int bestBandwidth = 1e9;
    do {
        int bandwidth = 0;
        for (auto &[a, b] : edges) {
            int delta = order.find(a) - order.find(b);
            bandwidth = max(bandwidth, abs(delta));
        }

        if (bestBandwidth > bandwidth) {
            bestBandwidth = bandwidth;
            bestOrder = order;
        }
    } while (next_permutation(order.begin(), order.end()));

    for (char a : bestOrder)
        cout << a << " ";
    cout << "-> " << bestBandwidth << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}