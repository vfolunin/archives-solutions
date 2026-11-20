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

    vector<string> a(size);
    for (int i = 0; i < size; i++)
        cin >> a[i];

    for (int i = 0; i < size; i++)
        if (a[i].find("rest") != string::npos)
            a[i] = "\U0001F60E";
        else if (a[i].find("leg") != string::npos)
            a[i] = "\U0001F9B5";
        else
            a[i] = "\U0001F4AA";

    for (int i = 0; i < 31; i++) {
        cout << a[i % size];
        if (i % 7 == 6)
            cout << '\n';
    }
}