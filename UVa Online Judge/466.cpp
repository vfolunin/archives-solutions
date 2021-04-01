#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void flip(vector<string> &a) {
    for (int i = 0; i * 2 < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            swap(a[i][j], a[a.size() - 1 - i][j]);
}

void rotate(vector<string> &a) {
    for (int i = 0; i < a.size() / 2; i++) {
        for (int j = 0; j * 2 < a.size(); j++) {
            swap(a[a.size() - 1 - i][a.size() - 1 - j], a[a.size() - 1 - j][i]);
            swap(a[j][a.size() - 1 - i], a[a.size() - 1 - i][a.size() - 1 - j]);
            swap(a[i][j], a[j][a.size() - 1 - i]);
        }
    }
}

bool solve(int test) {
    int size;
    if (!(cin >> size))
        return 0;

    vector<string> a(size), b(size);
    for (int i = 0; i < size; i++)
        cin >> a[i] >> b[i];

    cout << "Pattern " << test << " was ";

    if (a == b) {
        cout << "preserved.\n";
        return 1;
    }

    for (int i = 1; i <= 3; i++) {
        rotate(a);
        if (a == b) {
            cout << "rotated " << 90 * i << " degrees.\n";
            return 1;
        }
    }

    rotate(a);
    flip(a);
    if (a == b) {
        cout << "reflected vertically.\n";
        return 1;
    }

    for (int i = 1; i <= 3; i++) {
        rotate(a);
        if (a == b) {
            cout << "reflected vertically and rotated " << 90 * i << " degrees.\n";
            return 1;
        }
    }

    cout << "improperly transformed.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}