#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;

    int Num() const
    {
        return (month - 1) * 31 + day;
    }

    void Days(int days)
    {
        while (days > 0)
        {
            day++;
            days--;

            if (day > 31)
            {
                day = 1;
                month++;

                if (month > 12)
                    month = 1;
            }
        }

        while (days < 0)
        {
            day--;
            days++;

            if (day < 1)
            {
                day = 31;
                month--;

                if (month < 1)
                    month = 12;
            }
        }
    }

public:
    Date()
    {
        cout << "Construct\n";
        day = month = 0;
    }

    Date(int d, int m)
    {
        day = d;
        month = m;
    }

    void Output()
    {
        cout << "Day: " << day << ' ' << "Month: " << month << endl;
    }

    void SetDay(int a) { day = a; }
    int GetDay() { return day; }

    void SetMonth(int a) { month = a; }
    int GetMonth() { return month; }

    Date operator+(int days)
    {
        Date result = *this;
        result.Days(days);
        return result;
    }

    Date operator-(int days)
    {
        Date result = *this;
        result.Days(days);
        return result;
    }

    int operator-(const Date& obj2) // date1-date2
    {
        return Num() - obj2.Num();
    }

    Date operator++(int) // date++
    {
        Date result = *this;
        Days(1);
        return result;
    }

    Date& operator++() // ++date
    {
        Days(1);
        return *this;
    }

    Date operator--(int) //date--
    {
        Date result = *this;
        Days(-1);
        return result;
    }

    Date& operator--() // --date
    {
        Days(-1);
        return *this;
    }

    Date& operator+=(int days)  // date += int
    {
        Days(days);
        return *this;
    }

    Date& operator-=(int days) // date -= int
    {
        Days(days);
        return *this;
    }

    bool operator>(const Date& obj2) // date1 > date2
    {
        return Num() > obj2.Num();
    }

    bool operator<(const Date& obj2) // date1 < date2
    {
        return Num() < obj2.Num();
    }

    bool operator==(const Date& obj2) // date1 == date2
    {
        return day == obj2.day && month == obj2.month;
    }

    bool operator>=(const Date& obj2) // date1 >= date2
    {
        return Num() >= obj2.Num();
    }

    bool operator<=(const Date& obj2) // date1 <= date2
    {
        return Num() <= obj2.Num();
    }

    bool operator!=(const Date& obj2) // date1 != date2
    {
        return !(*this == obj2);
    }
};

int main()
{
    Date date1(28, 2);
    Date date2(3, 3);

    Date date3 = date1 + 5;
    cout << "date1 + 5: ";
    date3.Output();

    cout << "date1 - date2: " << date2 - date1 << " days" << endl;

    date1++;
    cout << "After date1++: ";
    date1.Output();

    date1 -= 2;
    cout << "After date1 -= 2: ";
    date1.Output();

    if (date1 < date2)
        cout << "date1 before date2" << endl;

    return 0;
}