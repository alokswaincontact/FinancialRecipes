#include "security_price_history.h"
const double MISSING_OBS=-1;
double security_price_history::price(const int& i) const{
    if (i>=no_dates()) { return MISSING_OBS; };
    if (trade(i)>0.0) { return trade(i); };
    if ( (bid(i)>0.0) && (ask(i)>0.0)) { return 0.5*(bid(i)+ask(i)); };    // return bid ask average
    if (bid(i)>0.0)   { return bid(i); };  // to avoid big jumps, 
    if (ask(i)>0.0)   { return ask(i); };  // skip these
    return MISSING_OBS;
};

double security_price_history::bid(const date& d) const {
  int i = index_of_date(d);  // return price on date, only if obs on that date, else return missing
  if (i>=0) return bid(i);
  return MISSING_OBS;
};

double security_price_history::trade(const date& d) const {
  int i = index_of_date(d); 
  if (i>=0) return trade(i);
  return MISSING_OBS;
};

double security_price_history::ask(const date& d) const {
  int i = index_of_date(d); 
  if (i>=0) return ask(i);
  return MISSING_OBS;
};

double security_price_history::price(const date& d) const {
  int i = index_of_date(d); 
  if (i>=0) return price(i);
  return MISSING_OBS;
};

double security_price_history::current_price(const date& d) const {   // return price on given date.  
    if (empty())         { return MISSING_OBS; };    
    if (d<first_date())  { return MISSING_OBS; };    // if before first or after last, return missing
    if (d>last_date())   { return MISSING_OBS; };
    int i = index_of_date(d);  // If don't have that price, return the last one observed before the wanted date
    if (i>=0) return price(i);
    i=index_of_last_date_before(d);      // otherwise use last previously observed price.
    if (i>=0) return price(i);
    return MISSING_OBS; 
};

double security_price_history::buy_price(const int& i) const{
    if (i>=no_dates()) { return MISSING_OBS; };
    if (ask(i)>0.0)   { return ask(i); };
    if (trade(i)>0.0) { return trade(i); };
    return MISSING_OBS;
};

double security_price_history::sell_price(const int& i) const{
    if (i>=no_dates()) { return MISSING_OBS; };
    if (bid(i)>0.0)   { return bid(i); };
    if (trade(i)>0.0) { return trade(i); };
    return MISSING_OBS;
};

dated_observations prices(const security_price_history& sh ){ 
    dated_observations pr;
    for (int i=0;i<sh.no_prices();++i) {
	date d=sh.date_at(i);
	double price = sh.price(i);
	if (price>0) pr.insert(d,price);
    };
    return pr;
};
