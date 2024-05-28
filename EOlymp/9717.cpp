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

    for (string op; cin >> op; ) {
        if (op == "fly")
            cout << "Bird flies\n";
        else if (op == "eat")
            cout << "Bird eats\n";
        else
            cout << "Bird sleeps\n";
    }
}