struct Data {
    int day, month, year;

    bool isLeap(int year) {
        return year % 400 == 0 || year % 100 && year % 4 == 0;
    }

    int daysInMonth(int month, int year) {
        vector<int> days = { 0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return days[month];
    }

    Data() : day(1), month(1), year(1900) {}

    Data(int day, int month, int year) : day(day), month(month), year(year) {}

    void OutDataddmmyyyy() const {
        cout << setw(2) << setfill('0') << day << ".";
        cout << setw(2) << setfill('0') << month << ".";
        cout << setw(4) << setfill('0') << year << "\n";
    }

    Data &operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Data operator++(int) {
        Data res = *this;
        ++*this;
        return res;
    }

    Data &operator--() {
        day--;
        if (!day) {
            month--;
            if (!month) {
                month = 12;
                year--;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    Data operator--(int) {
        Data res = *this;
        --*this;
        return res;
    }

    bool operator == (const Data &that) const {
        return year == that.year && month == that.month && day == that.day;
    }

    bool operator != (const Data &that) const {
        return !(*this == that);
    }

    bool operator < (const Data &that) const {
        if (year != that.year)
            return year < that.year;
        if (month != that.month)
            return month < that.month;
        return day < that.day;
    }

    bool operator <= (const Data &that) const {
        return *this < that || *this == that;
    }

    bool operator > (const Data &that) const {
        return !(*this <= that);
    }

    bool operator >= (const Data &that) const {
        return !(*this < that);
    }
};