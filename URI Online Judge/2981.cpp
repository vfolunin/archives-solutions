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

    int num, den;
    cin >> num >> den;

    int days = 21 + num / den;
    string month = "setembro";

    if (days > 30) {
        days -= 30;
        month = "outubro";
    }

    cout << "A UFSC fecha dia " << days << " de " << month << ".\n";
}