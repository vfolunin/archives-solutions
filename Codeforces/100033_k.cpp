#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("standing.in", "r", stdin);
    freopen("standing.out", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        while (value + 1 <= limit && limit % (value + 1) == 0) {
            value++;
            res++;
        }
    }

    cout << res;
}