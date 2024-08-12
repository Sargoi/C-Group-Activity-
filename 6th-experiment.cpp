#include <iostream>
#include <iomanip>


class date {
private:
    int day, month, year;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

public:
    date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    // Relational operators
    bool operator<(const date& other) const {
        return (year < other.year) || (year == other.year && month < other.month) || (year == other.year && month == other.month && day < other.day);
    }

    bool operator<=(const date& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const date& other) const {
        return !(*this < other);
    }

    bool operator==(const date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const date& other) const {
        return !(*this == other);
    }

    // Increment operator
    date& operator++() {
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

    // Addition operator
    date operator+(int days) const {
        date newDate = *this;
        newDate.day += days;
        while (newDate.day > newDate.daysInMonth(newDate.month, newDate.year)) {
            newDate.day -= newDate.daysInMonth(newDate.month, newDate.year);
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }
        return newDate;
    }

    // Conversion to int (days elapsed in the current year)
    operator int() const {
        int daysElapsed = day;
        for (int m = 1; m < month; ++m) {
            daysElapsed += daysInMonth(m, year);
        }
        return daysElapsed;
    }

    // Display function
    void display() const {
        std::cout << std::setw(2) << std::setfill('0') << day << "/"
                  << std::setw(2) << std::setfill('0') << month << "/"
                  << year << std::endl;
    }
};

int main() {
    date dt(28, 2, 2024);
    dt.display();

    ++dt;
    dt.display();

    date newDate = dt + 5;
    newDate.display();

    int daysElapsed = dt;
    std::cout << "Days elapsed in the current year: " << daysElapsed << std::endl;

    return 0;
}
