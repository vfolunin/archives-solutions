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

    int month;
    cin >> month;

    vector<string> season = {
        "", "Winter", "Winter", "Spring", "Spring" , "Spring", "Summer",
        "Summer", "Summer", "Autumn", "Autumn", "Autumn", "Winter"
    };

    cout << (month <= 12 ? season[month] : "Error");
}