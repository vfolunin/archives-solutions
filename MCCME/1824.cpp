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

    for (int i = 0; i < 30; i++) {
        int value;
        cin >> value;

        if (value < 0)
            sum += value;
    }

    if (sum)
        cout << sum;
    else
        cout << "NO";
}