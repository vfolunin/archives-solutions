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

    int size, limit;
    cin >> size >> limit;

    int sum = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (sum + value <= limit) {
            sum += value;
        } else {
            res++;
            sum = value;
        }
    }
    res += sum > 0;

    cout << res;
}