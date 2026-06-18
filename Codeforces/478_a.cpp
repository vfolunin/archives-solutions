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
    for (int i = 0; i < 5; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    cout << (sum && sum % 5 == 0 ? sum / 5 : -1);
}