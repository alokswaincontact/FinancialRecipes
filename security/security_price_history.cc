#include "security_price_history.h"  

security_price_history:: security_price_history(){ clear(); }; // make sure empty

security_price_history:: security_price_history(const string& name){
   clear(); 
   security_name_ = name; 
};
security_price_history:: ~security_price_history(){ clear(); }; 

// copy construction
security_price_history:: security_price_history(const security_price_history& sh) {
    clear();
    dates_  = vector<date>(sh.size());
    bids_   = vector<double>(sh.size());
    trades_ = vector<double>(sh.size());
    asks_   = vector<double>(sh.size());
    for (unsigned i=0;i<sh.no_dates();++i){
	dates_[i]=sh.date_at(i);
	bids_[i]=sh.bid(i);
	trades_[i]=sh.trade(i);
	asks_[i]=sh.ask(i);
    };
    set_security_name(sh.security_name()); 
};

security_price_history security_price_history:: operator=  (const security_price_history& sh) {
    clear();
    dates_ = vector<date>(sh.size());
    bids_  = vector<double>(sh.size());
    trades_= vector<double>(sh.size());
    asks_  = vector<double>(sh.size());
    for (unsigned i=0;i<sh.no_dates();++i){
	dates_[i]=sh.date_at(i);
	bids_[i]=sh.bid(i);
	trades_[i]=sh.trade(i);
	asks_[i]=sh.ask(i);
    };
    set_security_name(sh.security_name()); 
    return (*this);
};

void security_price_history::clear() {
    dates_.erase(dates_.begin(),dates_.end());
    bids_.erase(bids_.begin(),bids_.end());
    trades_.erase(trades_.begin(),trades_.end());
    asks_.erase(asks_.begin(),asks_.end());
    security_name_=string();
};
string security_price_history::security_name() const { return security_name_;    };
void security_price_history::set_security_name(const string& s)             { security_name_ = s; };
date   security_price_history::date_at(const int& t)  const { return dates_[t]; };

bool security_price_history::empty() const{
    if ( (no_dates()<1) && (security_name().length()<1) ) return true;
    return false;
};

void security_price_history::set_bid   (const int& i, const double& bid)    { if (i<no_dates()) bids_[i]=bid; };
void security_price_history::set_trade (const int& i, const double& trade)  { if (i<no_dates()) trades_[i]=trade; };
void security_price_history::set_ask   (const int& i, const double& ask)    { if (i<no_dates()) asks_[i]=ask; };

double security_price_history::bid (const int& t)     const { return bids_[t]; };
double security_price_history::trade(const int& t)    const { return trades_[t]; };
double security_price_history::ask (const int& t)     const { return asks_[t]; };

