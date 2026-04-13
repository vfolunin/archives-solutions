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
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            int value;
            cin >> value;

            sum += value;
        }

        res += sum >= 2;
    }

    cout << res;
}