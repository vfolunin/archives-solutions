#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> to(size);
    for (int &value : to)
        cin >> value;

    vector<int> visited(to.size());
    for (int startV = 0; startV < to.size(); startV++) {
        if (!visited[startV]) {
            for (int v = to[startV]; !visited[v]; v = to[v]) {
                visited[v] = 1;
                cout << v << " ";
            }
            cout << "\n";
        }
    }
}