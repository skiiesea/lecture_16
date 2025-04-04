class Day {
private:
    int d;
public:
    Day(int day) : d(day) {}
    int get_day() const;
};

class Month {
private:
    int m;
    explicit Month(int month_) : m(month_){}
public:
    static Month Jan();
    static Month Feb();
    static Month Mar();
    static Month Apr();
    static Month May();
    static Month Jun();
    static Month Jul();
    static Month Aug();
    static Month Sep();
    static Month Oct();
    static Month Nov();
    static Month Dec();
    int get_month() const;
    const Month& operator++();
    const Month operator++(int);
    const Month& operator--();
    const Month operator--(int);
    int get_max_days(const Year &y) const;
};

class Year {
private:
    int y;
public:
    Year(int year) : y(year) {}
    int get_year() const;
    bool is_leap() const;
};


class MyDate {
private:
    Day day;
    Month month;
    Year year;
public:
    MyDate() = delete;
    MyDate(Day day, Month month, Year year);
    const MyDate& add_day(int days);
    const MyDate& add_month(int month);
    const MyDate& add_year(int year);
};

