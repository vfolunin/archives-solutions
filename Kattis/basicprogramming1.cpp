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

    int size, type;
    cin >> size >> type;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    if (type == 1) {

        cout << 7;

    } else if (type == 2) {

        if (a[0] > a[1])
            cout << "Bigger";
        else if (a[0] == a[1])
            cout << "Equal";
        else
            cout << "Smaller";

    } else if (type == 3) {

        sort(a.begin(), a.begin() + 3);
        cout << a[1];

    } else if (type == 4) {

        long long sum = 0;
        for (int value : a)
            sum += value;
        cout << sum;

    } else if (type == 5) {

        long long sum = 0;
        for (int value : a)
            if (value % 2 == 0)
                sum += value;
        cout << sum;

    } else if (type == 6) {

        for (int value : a)
            cout << (char)(value % 26 + 'a');

    } else {

        vector<int> visited(a.size());
        for (int v = 0; 1; v = a[v]) {
            if (v < 0 || v >= a.size()) {
                cout << "Out";
                break;
            }
            if (visited[v]) {
                cout << "Cyclic";
                break;
            }
            visited[v] = 1;
            if (v == a.size() - 1) {
                cout << "Done";
                break;
            }
        }

    }
}