#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    string surname, name;
    int score = 0;

    friend istream &operator >> (istream &in, Student &s) {
        in >> s.surname >> s.name;
        for (int i = 0; i < 3; i++) {
            int value;
            cin >> value;
            s.score += value;
        }
        return in;
    }

    friend ostream &operator << (ostream &out, const Student &s) {
        out << s.surname << " " << s.name;
        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int studentCount;
    cin >> studentCount;

    vector<Student> students(studentCount);
    vector<int> scores(studentCount);
    for (int i = 0; i < students.size(); i++) {
        cin >> students[i];
        scores[i] = students[i].score;
    }

    sort(scores.rbegin(), scores.rend());

    for (Student &student : students)
        if (student.score >= scores[2])
            cout << student << "\n";
}