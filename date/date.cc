#include "date.h"

///////////////////////////// construction //////////

date::date(const int& d, const int& m, const int& y) {
   day_   = d; 
   month_ = m; 
   year_  = y;  // this assumes year is given fully, not Y2K corrections
};

///////////////////////////// inline definitions //////////

date::date(){ year_ = 0; month_ = 0; day_ = 0;};

int date::day()   const { return day_;   };
int date::month() const { return month_; };
int date::year()  const { return year_;  };

void date::set_day  (const int& day)     { date::day_   = day;   };
void date::set_month(const int& month)   { date::month_ = month; };
void date::set_year (const int& year)    { date::year_  = year;  };

bool date::valid() const {
// This function will check the given date is valid or not.
//  If the date is not valid then it will return the value false.
//   Need some more checks on the year, though
    if (year_ <0)                return false;
    if (month_>12 || month_<1)   return false;
    if (day_>31 || day_<1)       return false;
    if ((day_==31 && 
	 ( month_==2 || month_==4 || month_==6 || month_==9 || month_==11) ) )
	return false;
    if ( day_==30 && month_==2) return false;
    if ( year_<2000){
	if ((day_==29 && month_==2) && !((year_-1900)%4==0)) return false;
    };
    if ( year_>2000){
	if ((day_==29 && month_==2) && !((year_-2000)%4==0)) return false;
    };
    return true;

};
