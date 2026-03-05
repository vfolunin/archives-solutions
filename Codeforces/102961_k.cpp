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

    vector<int> pos(size);
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        pos[x - 1] = i;
    }

    int res = 1;
    for (int i = 1; i < size; i++)
        res += pos[i] < pos[i - 1];

    cout << res;
}