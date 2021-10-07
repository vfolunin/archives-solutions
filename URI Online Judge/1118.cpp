#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double readMark() {
    double x;
    while (1) {
        cin >> x;

        if (0 <= x && x <= 10)
            return x;

        cout << "nota invalida\n";
    }
}

bool readStop() {
    int x;
    while (1) {
        cout << "novo calculo (1-sim 2-nao)\n";
        cin >> x;

        if (1 <= x && x <= 2)
            return x == 2;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (1) {
        double a = readMark();
        double b = readMark();

        cout.precision(2);
        cout << "media = " << fixed << (a + b) / 2 << "\n";

        if (readStop())
            break;
    }
}