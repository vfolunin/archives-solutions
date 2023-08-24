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

    int n;
    cin >> n;

    vector<string> a = {
        "###   # ### ### # # ### ### ### ### ###",
        "# #  ##   #   # # # #   #     # # # # #",
        "# # # # ### ### ### ### ###   # ### ###",
        "# #   # #     #   #   # # #   # # #   #",
        "###   # ### ###   # ### ###   # ### ###"
    };

    for (string &row : a)
        cout << row.substr(n * 4, 3) << "\n";
}