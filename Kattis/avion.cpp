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

    bool found = 0;

    for (int i = 0; i < 5; i++) {
        string flight;
        cin >> flight;

        if (flight.find("FBI") != -1) {
            found = 1;
            cout << i + 1 << " ";
        }
    }

    if (!found)
        cout << "HE GOT AWAY!";
}