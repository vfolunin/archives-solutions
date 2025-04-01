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

    for (int i = 0; i < 3; i++) {
        string s;
        int value;
        cin >> s >> value;

        sum += value;
    }

    cout << sum;
}