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

    int count = 9, res = count;
    for (int i = 1; i < size; i++) {
        count *= 10 - i;
        res += count;
    }

    cout << res;
}