#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void a(int n, int step) {
    cout << "sin(" << step;
    if (step != n) {
        cout << (step % 2 ? "-" : "+");
        a(n, step + 1);
    }
    cout << ")";
}

void s(int n, int step) {
    if (step != n)
        cout << "(";
    if (step > 1)
        s(n, step - 1);
    a(step, 1);
    cout << "+" << n - step + 1;
    if (step != n)
        cout << ")";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    s(n, n);
}