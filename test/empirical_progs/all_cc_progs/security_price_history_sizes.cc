#include "security_price_history.h"

int security_price_history::no_dates ()  const { 
    return int(dates_.size()); 
};

int security_price_history::no_prices() const {
    int n_prices=0;
    for (int i=0;i<no_dates();++i){
	if ( (bid(i)>0) || (trade(i)>0) || (ask(i)>0) ) { ++n_prices; };
    };
    return n_prices;
};

int security_price_history::no_prices_between(const date& first, const date& last) const {
    int n_pric_between=0;
    for (int i=0;i<no_dates();++i) { 
	if  ((date_at(i)>=first) && (date_at(i)<=last)) {
	    if((bid(i)>0)||(trade(i)>0)||(ask(i)>0)) {++n_pric_between;};
	};
    };
    return n_pric_between;
};

int security_price_history::no_bids() const {
    int n_prices=0;
    for (int i=0;i<no_dates();++i){
	if (bid(i)>0) { ++n_prices; };
    };
    return n_prices;
};

int security_price_history::no_trades() const {
    int n_prices=0;
    for (int i=0;i<no_dates();++i){
	if (trade(i)>0) { ++n_prices; };
    };
    return n_prices;
};

int security_price_history::no_asks() const  {
    int n_prices=0;
    for (int i=0;i<no_dates();++i){
	if (ask(i)>0) { ++n_prices; };
    };
    return n_prices;
};
