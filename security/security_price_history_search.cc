#include "security_price_history.h"

bool security_price_history::contains(const date& d) const {
    return binary_search(dates_.begin(),dates_.end(),d);
};

int security_price_history::index_of_date(const date& d) const {
   // this routine returns the index at which date d is, or -1 if not found.
   if (!contains(d)) return -1;
   for (int i=0;i<dates_.size();++i){
       if (dates_[i]==d) return i;
   };
   return -1;
};

int security_price_history::index_of_first_date_after(const date& d) const {
    if (!d.valid()) return -1;
    if (d>=last_date()) return -1;
    if (d<first_date()) return 0;
    for (int i=0;i<dates_.size();++i){
	if (dates_[i]>d) return i;
    };
    return -1;
};

int security_price_history::index_of_last_date_before(const date& d) const {
    if (!d.valid()) return -1;
    if (d<=first_date()) return -1;
    if (d>last_date()) return index_of_date(last_date());
    for (int i=0;i<dates_.size();++i){
	if (dates_[i]>=d) return i-1;
    };
    return -1;
};
