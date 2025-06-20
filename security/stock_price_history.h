#ifndef _STOCK_PRICE_HISTORY_H_

#include "security_price_history.h"
#include "dated_obs.h"

class stock_price_history : public security_price_history {       // most of the functionality is inherited from security price history
private:
    dated_observations dividends_;
    dated_observations adjustments_;
public: 
    stock_price_history();
    stock_price_history(const stock_price_history&);
    stock_price_history operator = (const stock_price_history&);
    ~stock_price_history(){ clear(); };
    void clear();

    bool empty() const;
    ///////////////////// dividends //////////////////////////
    void      add_dividend (const date&, const double&);
    void      remove_dividend (const date&);
    int       no_dividends() const;
    date      dividend_date(const int&) const;
    double    dividend(const int&) const;
    bool      dividends_between(const date&, const date&) const;
    int       no_dividends_between(const date&, const date&) const;
    double    total_dividends_between(const date&, const date&) const;
    bool      dividend_on(const date&) const;
    double     dividend(const date&) const;

    ///// adjustments ///////////////////////////////
    void   add_adjustment         (const date&, const double&);
    void   remove_adjustment      (const date&);
    int    no_adjustments() const;
    date   adjustment_date(const int& i) const;
    double adjustment(const int& i) const;
    bool   adjustments_between(const date& d1, const date& d2) const;
    int    no_adjustments_between(const date& d1, const date& d2) const;
    double aggregated_adjustments_between(const date& d1, const date& d2) const;
    bool   adjustment_on(const date& d) const;
    double adjustment(const date& d) const;
};
/*
dated_observations daily_prices       (const stock_price_history& st);
dated_observations daily_prices       (const stock_price_history& st, const date& from, const date& to);
dated_observations daily_trade_prices (const stock_price_history& st);
dated_observations daily_trade_prices (const stock_price_history& st, const date& from, const date& to);
dated_observations monthly_prices     (const stock_price_history& st);
dated_observations annual_prices      (const stock_price_history& st);
*/
dated_observations dividends(const stock_price_history&);
dated_observations dividends(const stock_price_history&, const date& d1, const date& d2);

dated_observations adjustments(const stock_price_history&);
dated_observations adjustments(const stock_price_history&, const date& d1, const date& d2);

#define _STOCK_PRICE_HISTORY_H_
#endif
