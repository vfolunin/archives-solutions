#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
    string surname, name, formLetter, date;
    int formNumber;

    bool operator < (const Student &that) const {
        if (formNumber != that.formNumber)
            return formNumber < that.formNumber;
        if (formLetter != that.formLetter)
            return formLetter < that.formLetter;
        return surname < that.surname;
    }

    friend istream &operator >> (istream &in, Student &s) {
        in >> s.surname >> s.name >> s.formNumber >> s.formLetter >> s.date;
        return in;
    }

    friend ostream &operator << (ostream &out, const Student &s) {
        out << s.formNumber << s.formLetter << " " << s.surname << " " << s.name << " " << s.date;
        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int studentCount;
    cin >> studentCount;

    vector<Student> students(studentCount);
    for (Student &student : students)
        cin >> student;

    sort(students.begin(), students.end());

    for (Student &student : students)
        cout << student << "\n";
}