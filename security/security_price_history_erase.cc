#include "security_price_history.h"

void security_price_history::erase(const date& d) {
   int i = index_of_date(d);
   //   cout << "erasing" << endl;
   if (i>=0) { // returns -1 if not there
       //      cout << "erasing" << endl;
      dates_.erase(dates_.begin()+i);
      trades_.erase(trades_.begin()+i);
      bids_.erase(bids_.begin()+i); 
      asks_.erase(asks_.begin()+i);
   };
};

void security_price_history::erase_between(const date& first,
					   const date& last) {
   int i1 = index_of_first_date_after(first);
   int i2 = index_of_last_date_before(last);
   if ( (i1>=0) && (i2>=0) ) { // returns -1 if not there
      i2++;  // the erase does not delete the last one.
      dates_.erase(dates_.begin()+i1,dates_.begin()+i2);
      trades_.erase(trades_.begin()+i1,trades_.begin()+i2);
      bids_.erase(bids_.begin()+i1,bids_.begin()+i2);
      asks_.erase(asks_.begin()+i1,asks_.begin()+i2);
   };
};

void security_price_history::erase_before(const date& d) {
   int i = index_of_last_date_before(d);
   if (i>=0)  { // returns -1 if not there
      i++;// the erase does not delete the last one, so add one.
      dates_.erase(dates_.begin(),dates_.begin()+i);
      trades_.erase(trades_.begin(),trades_.begin()+i);
      bids_.erase(bids_.begin(),bids_.begin()+i);
      asks_.erase(asks_.begin(),asks_.begin()+i);
   };
};

void security_price_history::erase_after(const date& d) {
   int i = index_of_first_date_after(d);
   if (i>=0)  { // returns -1 if not there
      dates_.erase(dates_.begin()+i,dates_.end());
      trades_.erase(trades_.begin()+i,trades_.end());
      bids_.erase(bids_.begin()+i,bids_.end());
      asks_.erase(asks_.begin()+i,asks_.end());
   };
};
