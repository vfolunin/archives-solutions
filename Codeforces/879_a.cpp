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

    int res = 0;
    for (int i = 0; i < size; i++) {
        int start, interval;
        cin >> start >> interval;

        int nextRes = start;
        while (nextRes <= res)
            nextRes += interval;

        res = nextRes;
    }

    cout << res;
}