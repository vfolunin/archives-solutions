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

    int res = 1, sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (sum + value <= 50) {
            sum += value;
        } else {
            sum = value;
            res++;
        }
    }

    cout << res;
}