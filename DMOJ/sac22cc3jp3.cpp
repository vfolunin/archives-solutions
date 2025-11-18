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

    double res = 1;
    for (int i = 0; i < size; i++) {
        char type;
        cin >> type;

        res *= 1 - (type - 'A') * 0.2;
    }

    cout << fixed << res;
}