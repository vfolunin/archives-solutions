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

    string s;
    int size;
    cin >> s >> size;

    for (int i = 0; i < size; i++)
        cout << "Hipp hipp hurra, " << s << "!\n";
}