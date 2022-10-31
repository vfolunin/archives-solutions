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

    int count = 0;

    for (int i = 0; i < 30; i++) {
        int value;
        cin >> value;
        count += value > 175;
    }

    if (count)
        cout << count;
    else
        cout << "NO";
}