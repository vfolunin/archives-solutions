#include "countingdays.h"

int d = 1, h = 0, m = 0;

void lookAtClock(int hours, int minutes) {
    d += hours < h || hours == h && minutes < m;
    h = hours;
    m = minutes;
}

int getDay() {
    return d;
}