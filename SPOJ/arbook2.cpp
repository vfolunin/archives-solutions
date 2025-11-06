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
    cin.ignore();

    for (int i = 0; i < size; i++) {
        vector<string> a(4);
        for (string &s : a)
            getline(cin, s);

        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? " : " : "\n");
    }
}