#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    string name, region;
    int dist;

    bool operator < (const Student &that) const {
        if (dist != that.dist)
            return dist < that.dist;
        if (region != that.region)
            return region < that.region;
        return name < that.name;
    }
};

bool solve() {
    int studentCount;
    if (!(cin >> studentCount))
        return 0;

    vector<Student> students(studentCount);
    for (auto &[n, r, d] : students)
        cin >> n >> r >> d;

    sort(students.begin(), students.end());

    for (auto &[n, r, d] : students)
        cout << n << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}