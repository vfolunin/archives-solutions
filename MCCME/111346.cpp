#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    string surname, name;
    int form, score;

    bool operator < (const Student &that) const {
        return surname < that.surname;
    }
};

istream &operator >> (istream &in, Student &student) {
    return in >> student.surname >> student.name >> student.form >> student.score;
}

ostream &operator << (ostream &out, const Student &student) {
    return out << student.surname << " " << student.name << " " << student.score;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Student> students;
    Student student;

    while (cin >> student)
        students.push_back(student);

    sort(students.begin(), students.end());

    for (Student &student : students)
        cout << student << "\n";
}