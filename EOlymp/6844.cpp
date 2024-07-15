#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> read() {
    int sum = 0, sumX = 0;

    while (cin.peek() != '=' && cin.peek() != '\n' && cin.peek() != EOF) {
        int factor = 1;

        if (cin.peek() == '-' || cin.peek() == '+') {
            if (cin.peek() == '-')
                factor = -1;
            cin.ignore();
        }

        if (cin.peek() != 'x') {
            int val;
            cin >> val;
            factor *= val;
        }

        if (cin.peek() == 'x') {
            sumX += factor;
            cin.ignore();
        } else {
            sum += factor;
        }
    }

    cin.ignore();
    return { sum, sumX };
}

int floor(int a, int b) {
    int res = a / b, mod = a % b;
    if (res < 0 && mod)
        res--;
    return res;
}

void solve() {
    auto [a, ax] = read();
    auto [b, bx] = read();

    ax -= bx;
    b -= a;

    if (!ax && !b)
        cout << "IDENTITY\n";
    else if (!ax && b)
        cout << "IMPOSSIBLE\n";
    else
        cout << floor(b, ax) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    while (isspace(cin.peek()))
        cin.get();

    for (int i = 0; i < n; i++)
        solve();
}