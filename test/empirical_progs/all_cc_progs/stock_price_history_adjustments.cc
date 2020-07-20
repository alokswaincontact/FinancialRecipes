#include "stock_price_history.h"

int stock_price_history::no_adjustments()  const{  return adjustments_.size(); };
date stock_price_history::adjustment_date(const int& i) const{ return adjustments_.date_at(i); };
double stock_price_history::adjustment(const int& i)  const {  return adjustments_.element_at(i);};
bool stock_price_history::adjustment_on(const date& d) const {
   for (int i=0; i<adjustments_.size(); ++i) {
      if (adjustments_.date_at(i)==d) return true; 
   };
   return false;
};
double stock_price_history::adjustment(const date& d) const {
    for (int i=0; i<adjustments_.size(); ++i){ if (adjustments_.date_at(i)==d) return adjustments_.element_at(i); };
    return 0.0;
};

void stock_price_history::add_adjustment ( const date& adjustment_date, const double& adj_factor) {
   if (adjustments_.contains(adjustment_date)) {
      adjustments_.insert(adjustment_date, adjustments_.element_at(adjustment_date)*adj_factor);
   }
   else { adjustments_.insert(adjustment_date,adj_factor); };
};

void stock_price_history::remove_adjustment(const date& adjustment_date){ adjustments_.remove(adjustment_date); };

bool stock_price_history::adjustments_between(const date& d1, const date& d2)  const{
    date first, last;
    if (d1<d2) { first=d1; last=d2; } else { first=d2; last=d1; };
    if (adjustments_.no_obs_between(first,last)>0) return true;
    return false;
};

int stock_price_history::no_adjustments_between(const date& d1, const date& d2) const {
    date first, last;
    if (d1<d2) { first=d1; last=d2; } else { first=d2; last=d1; };
    return adjustments_.no_obs_between(first,last);
};

double stock_price_history::aggregated_adjustments_between(const date& d1, const date& d2)  const {
    date first, last;
    if (d1<d2) { first=d1; last=d2; } else { first=d2; last=d1; };
    double tot_adjustments=1.0;
    for (int i=0; i<adjustments_.size(); ++i){
	if ( (adjustments_.date_at(i)>first) && (adjustments_.date_at(i)<=last) ) {
	   tot_adjustments *= adjustments_.element_at(i);
	};
    };
    return tot_adjustments;
};

dated_observations adjustments(const stock_price_history& sphist,  const date& d1, const date& d2){
    dated_observations adjustments;
    for (int i=0;i<sphist.no_adjustments();++i){
	date d=sphist.adjustment_date(i);
	if ( (d>=d1) && (d<=d2) && (sphist.adjustment(i)>0) ){
	    adjustments.insert(d,sphist.adjustment(i));
	};
    };
    return adjustments;
};

dated_observations adjustments(const stock_price_history& sphist){
    return adjustments(sphist,sphist.first_date(),sphist.last_date());
};
