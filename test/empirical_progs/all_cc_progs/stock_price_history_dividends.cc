#include "stock_price_history.h"
// querying
int stock_price_history::no_dividends() const { return dividends_.size(); };
date stock_price_history::dividend_date(const int& i) const { return dividends_.date_at(i); };
double stock_price_history::dividend(const int& i) const { return dividends_.element_at(i); };

bool stock_price_history::dividend_on(const date& d) const { return dividends_.contains(d); };

double stock_price_history::dividend(const date& d) const {
   double div = dividends_.element_at(d);
   if (div>0) return div;
   return 0.0;
};

void stock_price_history::add_dividend(const date&   dividend_date,  const double& dividend_amount) {
   dividends_.insert(dividend_date,dividend_amount);
};

void stock_price_history::remove_dividend(const date& dividend_date) { dividends_.remove(dividend_date);};

bool stock_price_history::dividends_between(const date& d1, const date& d2) const {
    date first, last;
    if (d1<d2) { first=d1; last=d2; } else { first=d2; last=d1; };
    if( dividends_.no_obs_between(first,last)>0) return true;
    return false;
};

int stock_price_history::no_dividends_between(const date& d1, const date& d2)  const {
    date first, last;
    if (d1<d2) { first=d1; last=d2; } else { first=d2; last=d1; };
    return dividends_.no_obs_between(first,last);
};

double stock_price_history::total_dividends_between(const date& d1, const date& d2) const {
   if (!dividends_between(d1,d2)) return 0;
   date first, last;
   if (d1<d2) { first=d1; last=d2; } else { first=d2; last=d1; };
   double tot_dividend = 0.0;
   for (int i=0; i<dividends_.size(); ++i){
      if ( (dividends_.date_at(i)>first) && (dividends_.date_at(i)<=last) ) {
	 tot_dividend += dividends_.element_at(i);
      };
   };
   return tot_dividend;
};

dated_observations dividends(const stock_price_history& sphist, const date& d1, const date& d2){
    dated_observations dividends;
    for (int i=0;i<sphist.no_dividends();++i){
	date d=sphist.dividend_date(i);
	if ( (d>=d1) && (d<=d2) && (sphist.dividend(i)>=0.0) ){
	    dividends.insert(d,sphist.dividend(i));
	};
    };
    return dividends;
};

dated_observations dividends(const stock_price_history& sphist){
    return dividends(sphist,sphist.first_date(),sphist.last_date());
};
