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
        double value;
        cin >> value;
        count += 50 < value && value <= 57;
    }

    if (count)
        cout << count;
    else
        cout << "NO";
}