#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int speed = 0;

    for (int i = 0; i < 10; i++) {
        while (!isPrime(n))
            n++;
        speed += n++;
    }

    int hours = (int)6e7 / speed;
    int days = hours / 24;

    cout << speed << " km/h\n";
    cout << hours << " h / " << days << " d\n";
}