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

    int sum = 0;

    for (int i = 0; i < 31; i++) {
        int value;
        cin >> value;
        sum += value;
    }

    cout << sum / 27;
}