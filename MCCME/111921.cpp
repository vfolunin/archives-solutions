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

    int temperature;
    cin >> temperature;

    if (temperature >= 20)
        cout << "cap\n";
    else if (temperature <= -10)
        cout << "wintercap\n";

    if (temperature >= 15)
        cout << "sun";
    else if (temperature < 0)
        cout << "wintersun";
    else
        cout << "halfsun";
}