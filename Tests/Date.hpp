#pragma once
#include <iostream>

enum Day{
	Monday = 1,
	Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};

enum Month{
	Jan = 1,
	Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
};


class Date {
public:
	Date(Day d = Day::Monday, Month m = Month::Jan, unsigned int y = 0);
	~Date();

	inline Day getDay() const { return this->d; }
	inline Month getMonth() const { return this->m; }
	inline unsigned int getYear() const { return this->y; }

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	
private:
	Day d;
	Month m;
	unsigned int y;

};

std::ostream& operator<<(std::ostream& os, Day d);

std::ostream& operator<<(std::ostream& os, Month m);

Day operator+(Day& d, int n);

Month operator+(Month& m, int n);

namespace DateUtils{
	
	namespace Days{
		static Date next(Date today) {
			Date tomorrow {Day(today.getDay()+1), today.getMonth(), today.getYear()};
			return tomorrow;
		}
		static Date next_spec(Date today, Day d) {
			return Date(Day(today.getDay() + d), today.getMonth(), today.getYear());
		}
	}
	
	namespace Months{
		static Date next(Date today) {
			return Date(today.getDay(), Month(today.getMonth()+1), today.getYear());
		}
		static Date next_spec(Date today, Month m) {
			return Date(today.getDay(), Month(today.getMonth() + m), today.getYear());
		}
	}
	
	namespace Years{
		static Date next(Date today) {
			return Date(today.getDay(), today.getMonth(), today.getYear()+1);
		}
		static Date next_spec(Date today, unsigned int y) {
			return Date(today.getDay(), today.getMonth(), today.getYear()+y);
		}
	}
}