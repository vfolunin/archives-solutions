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

    int size, target;
    cin >> size >> target;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    if (sum < target * size && target == 100) {
        cout << "impossible";
        return 0;
    }

    int res = 0;
    while (sum + 100 * res < target * (size + res))
        res++;

    cout << res;
}