#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second || a.second == b.second && a.first < b.first;
}

bool solve() {
    map<string, set<string>> studentProjects;
    map<string, int> studentCount;
    string project;

    while (1) {
        string line;
        getline(cin, line);

        if (line[0] == '0')
            return 0;

        if (line[0] == '1')
            break;

        if (isupper(line[0])) {
            project = line;
            studentCount[project];
        } else {
            studentProjects[line].insert(project);
        }
    }

    for (auto &[student, projects] : studentProjects)
        if (projects.size() == 1)
            studentCount[*projects.begin()]++;

    vector<pair<string, int>> res(studentCount.begin(), studentCount.end());
    sort(res.begin(), res.end(), compare);

    for (auto &[project, count] : res)
        cout << project << " " << count << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}