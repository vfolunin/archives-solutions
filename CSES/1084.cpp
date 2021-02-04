#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int applicantCount, apartmentCount, maxDiff;
    cin >> applicantCount >> apartmentCount >> maxDiff;

    vector<int> desiredSize(applicantCount);
    for (int &x : desiredSize)
        cin >> x;
    sort(desiredSize.begin(), desiredSize.end());

    vector<int> apartmentSize(apartmentCount);
    for (int &x : apartmentSize)
        cin >> x;
    sort(apartmentSize.begin(), apartmentSize.end());

    int res = 0;
    for (; !desiredSize.empty(); desiredSize.pop_back()) {
        while (!apartmentSize.empty() && apartmentSize.back() > desiredSize.back() + maxDiff)
            apartmentSize.pop_back();

        if (!apartmentSize.empty() && 
            desiredSize.back() - maxDiff <= apartmentSize.back() &&
            apartmentSize.back() <= desiredSize.back() + maxDiff) {
            apartmentSize.pop_back();
            res++;
        }
    }

    cout << res;
}