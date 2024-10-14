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

    int k1, k8 = 0;
    cin >> k1;

    while (k1 >= 5 || k8 >= 3) {
        if (k1 >= 5) {
            k1 -= 5;
            k8 += 2;
        } else {
            k8 -= 2;
        }
    }

    cout << string(k8, '8') << string(k1, '1');
}