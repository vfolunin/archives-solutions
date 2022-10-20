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

    int prevValue, value, count = 1;

    for (int i = 0; cin >> value; i++) {
        count += i && prevValue < value;
        prevValue = value;
    }

    cout << count;
}