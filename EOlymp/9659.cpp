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
 
    for (string type, args; cin >> type; ) {
        getline(cin, args);
        cout << args << "\n";
    }
}