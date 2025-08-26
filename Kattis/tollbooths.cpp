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

    int sum = 0, res = 0;
    for (int i = 0; i < size; i++) {
        char type;
        int value;
        cin >> type >> value;

        sum += type == 'G' ? value : -value;

        res = max(res, -sum);
    }

    cout << res;
}