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

    while (1) {
        int n;
        cin >> n;

        if (!n)
            break;

        int res = 0;
        for (int i = 0; i < 5; n++) {
            if (n % 2 == 0) {
                res += n;
                i++;
            }
        }

        cout << res << "\n";
    }
}