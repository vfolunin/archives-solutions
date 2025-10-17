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

    double weight, height;
    cin >> weight >> height;

    double bmi = weight / (height * height);

    if (bmi > 25)
        cout << "Overweight";
    else if (bmi >= 18.5)
        cout << "Normal weight";
    else
        cout << "Underweight";
}