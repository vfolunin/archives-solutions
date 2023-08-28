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

    int sum, count;
    cin >> sum >> count;

    if (sum <= count * 9) {    
        string res(count, '0');

        for (char &c : res) {
            int delta = min(sum, 9);
            c += delta;
            sum -= delta;
        }

        cout << res;
    } else {
        cout << -1;
    }
}