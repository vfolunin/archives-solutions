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

    int prevValue, count = 0;

    for (int i = 0; 1; i++) {
        int value;
        cin >> value;

        if (!value)
            break;

        count += i && prevValue < value;
        prevValue = value;
    }

    cout << count;
}