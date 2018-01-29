#include "security_price_history.h"


void security_price_history::add_prices(const date& d,
					const double& bid,
					const double& trade,
					const double& ask) {
    if (!d.valid()) return;  // don't add 
    if ( (bid<0) && (trade<0) && (ask<0) ) return;  // don't bother about empty dates
    if ( (no_dates()<1) || (d>last_date() ) ) {
	dates_ .push_back(d);
	trades_.push_back(trade);
	bids_  .push_back(bid);
	asks_  .push_back(ask);
	return;
    };
    if (d<first_date()) {
	dates_.insert(dates_.begin(),d);
	bids_.insert(bids_.begin(),bid); 
	trades_.insert(trades_.begin(),trade);
	asks_.insert(asks_.begin(),ask);
	return;
    };
    int i = index_of_date(d);
    if (i>=0) { // found, replace
	trades_[i]=trade;
	bids_[i]=bid;
	asks_[i]=ask;
	return;
    }
    // evidently should be inserted somewhere in between other observations.
    for (i=0;i<no_dates();++i){
	if (date_at(i)>d) {
	    dates_.insert(dates_.begin()+i,d);
	    bids_.insert(bids_.begin()+i,bid); 
	    trades_.insert(trades_.begin()+i,trade);
	    asks_.insert(asks_.begin()+i,ask);
	    return;
	};
    };
};


int security_price_history::size() const { return int(dates_.size()); };

date security_price_history::first_date() const { 
    if (dates_.size()>0) { return dates_.front();}; 
    return date(); // else
};

date security_price_history::last_date() const { 
    if (dates_.size()>0) { return dates_.back();};
    return date();
};

vector<date> security_price_history::dates() const {
    return dates_;
};
