#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long ask(long long value) {
    cout << "? " << value << endl;

    long long ans;
    cin >> ans;

    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (long long value = 1; 1; value = value * 2 + 1) {
        long long ans = ask(value);
        if (ans != value) {
            cout << "! " << value - ans << endl;
            break;
        }
    }
}