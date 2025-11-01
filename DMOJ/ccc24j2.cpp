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

    int a;
    cin >> a;

    while (1) {
        int b;
        cin >> b;

        if (a > b)
            a += b;
        else
            break;
    }

    cout << a;
}