#include "date.h"

bool operator == (const date& d1,const date& d2){ 
// check for equality
    if (!d1.valid()) { return false; }; 
    if (!d2.valid()) { return false; }; 
    if( (d1.day()==d2.day())
	&& (d1.month()==d2.month())
	&& (d1.year()==d2.year())) {
	return true;
    };
    return false;
}

bool operator !=(const date& d1, const date& d2){ 
    return !(d1==d2);
}

bool operator < (const date& d1, const date& d2){ 
    if (!d1.valid()) { return false; }; // not  meaningful, return anything
    if (!d2.valid()) { return false; }; // should really be an exception, but ?
    if (d1.year()<d2.year())      { return true;}
    else if (d1.year()>d2.year()) { return false;}
    else {                            // same year
	if (d1.month()<d2.month())      { return true;}
	else if (d1.month()>d2.month()) { return false;} 
	else { // same  month
	    if ( d1.day()<d2.day()) { return true;}
	    else { return false; }
	};
    };
    return false;
};

bool operator > (const date& d1, const date& d2) {
    if (d1==d2) { return false;};  // this is strict inequality 
    if (d1<d2) { return false; };
    return true;
}

bool operator <=(const date& d1, const date& d2){
  if (d1==d2) { return true; }
  return (d1<d2);
}

bool operator >=(const date& d1, const date& d2) {
    if (d1==d2) { return true;};
    return (d1>d2);
};
