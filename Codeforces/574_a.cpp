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

    int size, count;
    cin >> size >> count;

    multiset<int> counts;
    for (int i = 1; i < size; i++) {
        int count;
        cin >> count;

        counts.insert(count);
    }

    int res = 0;
    while (!counts.empty() && count <= *prev(counts.end())) {
        res++;
        count++;
        counts.insert(*prev(counts.end()) - 1);
        counts.erase(prev(counts.end()));
    }

    cout << res;
}