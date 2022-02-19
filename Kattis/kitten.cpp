#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertex;
    cin >> vertex;

    map<int, int> to;
    while (1) {
        vector<int> adj = readInts();
        if (adj.size() == 1)
            break;
        for (int i = 1; i < adj.size(); i++)
            to[adj[i]] = adj[0];
    }

    for (; vertex; vertex = to[vertex])
        cout << vertex << " ";
}