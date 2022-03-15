#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int day;
    string month;
    cin >> day >> month;

    static vector<string> months = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    int date = (find(months.begin(), months.end(), month) - months.begin() + 1) * 100 + day;

    static vector<string> signs = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"
    };
    static vector<int> dates = {
        100, 121, 220, 321, 421, 521, 622, 723, 823, 922, 1023, 1123, 1222
    };

    cout << signs[upper_bound(dates.begin(), dates.end(), date) - dates.begin() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}