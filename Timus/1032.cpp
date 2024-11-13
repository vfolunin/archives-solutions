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

    vector<int> a(size);
    int sum = 0;
    vector<int> from(a.size(), -1);
    from[sum] = 0;

    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        sum = (sum + a[i]) % a.size();

        if (from[sum] != -1) {
            cout << i - from[sum] + 1 << "\n";
            for (int j = from[sum]; j <= i; j++)
                cout << a[j] << "\n";
            break;
        }

        from[sum] = i + 1;
    }
}