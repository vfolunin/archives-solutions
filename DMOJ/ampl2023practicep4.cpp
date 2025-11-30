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

    int queryCount, count;
    cin >> queryCount >> count;

    for (int i = 0; i < queryCount; i++) {
        string type;
        int amount;
        cin >> type >> amount;

        count = clamp(count + (type == "INC" ? 1 : -1) * amount, 1, 1024);

        cout << count << "\n";
    }
}