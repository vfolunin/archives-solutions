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

    int limit, size;
    cin >> limit >> size;

    int res;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value <= limit)
            res = i;
    }

    cout << res + 1;
}