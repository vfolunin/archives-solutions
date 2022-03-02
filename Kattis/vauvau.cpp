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

    int aggressive1, calm1;
    int aggressive2, calm2;
    cin >> aggressive1 >> calm1;
    cin >> aggressive2 >> calm2;

    for (int i = 0; i < 3; i++) {
        int time;
        cin >> time;
        time--;

        int bite1 = time % (aggressive1 + calm1) < aggressive1;
        int bite2 = time % (aggressive2 + calm2) < aggressive2;

        if (bite1 && bite2)
            cout << "both\n";
        else if (bite1 || bite2)
            cout << "one\n";
        else
            cout << "none\n";
    }
}