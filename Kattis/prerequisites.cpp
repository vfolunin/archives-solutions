#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int takenCourseCount, categoryCount;
    if (!(cin >> takenCourseCount >> categoryCount))
        return 0;

    set<int> takenCourses;
    for (int i = 0; i < takenCourseCount; i++) {
        int course;
        cin >> course;
        takenCourses.insert(course);
    }

    bool graduated = 1;
    for (int i = 0; i < categoryCount; i++) {
        int courseCount, courseNeed, courseTaken = 0;
        cin >> courseCount >> courseNeed;

        for (int j = 0; j < courseCount; j++) {
            int course;
            cin >> course;
            courseTaken += takenCourses.count(course);
        }

        graduated &= courseTaken >= courseNeed;
    }

    cout << (graduated ? "yes\n" : "no\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}