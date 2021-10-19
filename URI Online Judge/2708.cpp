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

    int carCount = 0, passengerCount = 0;

    while (1) {
        string op;
        cin >> op;

        if (op == "SALIDA") {
            carCount++;
            int passengers;
            cin >> passengers;
            passengerCount += passengers;
        } else if (op == "VUELTA") {
            carCount--;
            int passengers;
            cin >> passengers;
            passengerCount -= passengers;
        } else {
            break;
        }
    }

    cout << passengerCount << "\n";
    cout << carCount << "\n";
}