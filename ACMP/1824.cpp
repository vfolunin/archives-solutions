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
    long long sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    int queryCount;
    cin >> queryCount;

    int offset = 0;
    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int index, value;
            cin >> index >> value;

            index = (index - 1 + offset) % a.size();
            sum -= a[index];
            a[index] = value;
            sum += a[index];
        } else {
            int shift;
            cin >> shift;

            offset = (offset + a.size() - shift) % a.size();
        }

        cout << sum << "\n";
    }
}