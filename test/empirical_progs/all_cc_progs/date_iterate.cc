#include "date.h"

inline date next_date(const date& d){
    date ndat;
    if (!d.valid()) { return ndat; };
    ndat=date((d.day()+1),d.month(),d.year());  if (ndat.valid()) return ndat;
    ndat=date(1,(d.month()+1),d.year());      if (ndat.valid()) return ndat;
    ndat = date(1,1,(d.year()+1));          return ndat;
}

inline date previous_date(const date& d){
    date ndat;
    if (!d.valid()) { return ndat; }; // return zero
    ndat = date((d.day()-1),d.month(),d.year());  if (ndat.valid()) return ndat;
    ndat = date(31,(d.month()-1),d.year());     if (ndat.valid()) return ndat;
    ndat = date(30,(d.month()-1),d.year());     if (ndat.valid()) return ndat;
    ndat = date(29,(d.month()-1),d.year());     if (ndat.valid()) return ndat;
    ndat = date(28,(d.month()-1),d.year());     if (ndat.valid()) return ndat;
    ndat = date(31,12,(d.year()-1));          return ndat;
};

date date::operator ++(int){ // postfix operator
   date d = *this;
   *this = next_date(d);
   return d;
}

date date::operator ++(){ // prefix operator
   *this = next_date(*this);
   return *this;
}

date date::operator --(int){ // postfix operator, return current value
   date d = *this;
   *this = previous_date(*this);
   return d;
}

date date::operator --(){ // prefix operator, return new value
   *this = previous_date(*this);
   return *this;
};

inline long long_date(const date& d) {
    if (d.valid()){ return d.year() * 10000 + d.month() * 100 + d.day();  };
    return -1;
};

ostream & operator << (ostream& os,  const date& d){
    if (d.valid()) {	os << " " << long_date(d) << " " ; } 
    else {       	os << " invalid date ";    };
    return os;
}
