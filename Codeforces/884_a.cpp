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

    int size, threshold;
    cin >> size >> threshold;

    int sum = 0;
    for (int i = 1; i <= size; i++) {
        int time;
        cin >> time;

        sum += 24 * 60 * 60 - time;
        if (sum >= threshold) {
            cout << i;
            break;
        }
    }
}