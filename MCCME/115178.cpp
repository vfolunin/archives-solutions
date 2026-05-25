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

    string a;
    cin >> a;

    string b = a;
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            swap(a[i], *min_element(a.rbegin(), a.rend() - i));
            break;
        }
    }

    cout << a;
}