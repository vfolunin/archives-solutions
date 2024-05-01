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

    int size, pairCount;
    cin >> size >> pairCount;

    set<pair<int, int>> pairs;
    for (int i = 0; i < pairCount; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        pairs.insert({ a, b });
    }

    int res = 0;
    for (int a = 1; a <= size; a++)
        for (int b = a + 1; b <= size; b++)
            for (int c = b + 1; c <= size; c++)
                res += !pairs.count({ a, b }) && !pairs.count({ a, c }) && !pairs.count({ b, c });

    cout << res;
}