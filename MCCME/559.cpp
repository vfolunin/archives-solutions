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

    int index;
    cin >> index;

    vector<string> months = {
        "YAN", "FEV", "MAR", "APR", "MAI", "IUN",
        "IUL", "AVG", "SEN", "OKT", "NOV", "DEC"
    };

    cout << months[index - 1];
}