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

    vector<int> count(5);
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;

        count[0] += !x || !y;
        count[1] += x > 0 && y > 0;
        count[2] += x < 0 && y > 0;
        count[3] += x < 0 && y < 0;
        count[4] += x > 0 && y < 0;
    }

    for (int i = 1; i < count.size(); i++)
        cout << "Q" << i << ": " << count[i] << "\n";
    cout << "AXIS: " << count[0];
}