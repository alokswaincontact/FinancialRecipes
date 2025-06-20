#include "stock_price_history.h"  

const double MISSING_OBS = -1; //  Assumption: Prices are positive.  Negative prices are missing observations.

stock_price_history::stock_price_history(){; }; 

stock_price_history::stock_price_history(const stock_price_history& sh): security_price_history(sh){
    dividends_.clear();
    for (unsigned i=0;i<sh.no_dividends();++i)
	add_dividend(sh.dividend_date(i), sh.dividend(i));
    adjustments_.clear();
    for (unsigned i=0;i<sh.no_adjustments();++i)  
	add_adjustment(sh.adjustment_date(i), sh.adjustment(i));
};

stock_price_history stock_price_history:: operator= (const stock_price_history& sh) {
    clear();
    security_price_history::operator=(sh);
    for (unsigned i=0;i<sh.no_dividends();++i)
	add_dividend(sh.dividend_date(i), sh.dividend(i));
    for (unsigned i=0;i<sh.no_adjustments();++i)  
	add_adjustment(sh.adjustment_date(i), sh.adjustment(i));
    return *this;
};

void stock_price_history::clear() {
    security_price_history::clear();
    dividends_.clear();
    adjustments_.clear();
};

bool stock_price_history::empty() const {
    if (no_dividends()>0) return false;
    if (no_adjustments()>0) return false;
    return security_price_history::empty();
};


dated_observations prices(const stock_price_history& sh ){ 
    dated_observations pr;
    for (int i=0;i<sh.no_prices();++i) {
	date d=sh.date_at(i);
	double price = sh.price(i);
	if (price>0) pr.insert(d,price);
    };
    return pr;
};
