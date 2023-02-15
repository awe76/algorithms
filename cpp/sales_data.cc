#include <iostream>
#include <stdlib.h>
#include <string>
using std::string;
using std::istream;
using std::ostream;

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &);
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(istream &is) {
    read(is, *this);
}

struct Person {
    Person() = default;
    Person(const string &name, const string &address): name(name), address(address) { }
    string getName() const { return name; }
    string getAddress() const { return address; }
    string name;
    string address;
};

class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd): Screen(ht, wd, ' ') { };
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { };
    char get() const {
        return contents[cursor];
    }
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen() &set(char);
    Screen() &set(pos, pos, char);
    Screen() &display(ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen() &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    void do_display(ostream &os) const {
        os << contents;
    }
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r+width + col] = ch;
    return *this;
}

int main() {
    return 0;
}