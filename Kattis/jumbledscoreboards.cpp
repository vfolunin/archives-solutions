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

    int prevA = 0, prevB = 0;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        if (prevA > a || prevB > b) {
            cout << "no";
            return 0;
        }

        prevA = a;
        prevB = b;
    }

    cout << "yes";
}