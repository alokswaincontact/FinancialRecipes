#ifndef _SECURITY_PRICE_HISTORY_H_
#define _SECURITY_PRICE_HISTORY_H_

#include "dated_obs.h"

class security_price_history {
private:
    string         security_name_;
    vector<date>   dates_;
    vector<double> bids_;
    vector<double> trades_;
    vector<double> asks_;
public: 
    security_price_history();
    security_price_history(const string&);
    security_price_history(const security_price_history&); 
    security_price_history operator=(const security_price_history&);
    ~security_price_history();
    void clear();
    void set_security_name(const string&);
    void add_prices(const date& d, const double& bid, const double& trade, const double& ask);
    // the most important function, all dates is added through calls to add_prices

    void set_bid   (const int& i, const double& bid);  // to change current data.
    void set_trade (const int& i, const double& trade);
    void set_ask   (const int& i, const double& ask);

    void erase(const date&);  // delete on given dates
    void erase_before(const date&);
    void erase_between(const date&, const date&);
    void erase_after(const date&);
    bool contains(const date&) const;  // check whether this date is present
private:
    int index_of_date(const date&) const;// where in vector is this date?
    int index_of_last_date_before(const date&) const ;
    int index_of_first_date_after(const date&) const ;
public:
    bool empty() const;
    int size() const;// { return dates_.size(); };
    string security_name() const; 
    vector<date> dates() const;

    int no_dates() const;
    int no_prices() const;
    int no_bids() const;
    int no_trades() const;
    int no_asks() const;
    int no_prices_between(const date&, const date&) const;
    date date_at(const int&) const;  
    double bid(const int&) const; 
    double bid(const date&) const;
    double trade(const int&) const;
    double trade(const date&) const;
    double ask(const int&) const;
    double ask(const date&) const;
    date first_date() const;
    date last_date()  const;
    double price(const date&) const;  // price at given data
    double current_price(const date&) const; // price at or before given data
    double price(const int&) const; 
    double buy_price(const int&) const;
    double sell_price(const int&) const; 
};

dated_observations prices(const security_price_history&);
vector<date> dates(const security_price_history&);

#endif
