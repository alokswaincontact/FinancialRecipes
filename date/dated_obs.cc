#include "dated_obs.h" 
#include <algorithm>

void dated_observations::set_title(string s) { title_ = s; };

void dated_observations::clear() { 
   title_ = string();
   dated<double>::clear();
};

string dated_observations::title() const { return title_;};

int dated_observations::no_obs_between(const date& dat1, const date& dat2) const {
// count number of observations between given dates.
   if (!dat1.valid()) return -1;
   if (!dat2.valid()) return -1;
   int noobs=0;
   int T = size();
   for (int t=0;t<T;++t) {
      if ( (dat1<=date_at(t) ) && (date_at(t)<=dat2) ) ++noobs;
   };
   return noobs; 
};

int dated_observations::no_obs_before(const date& d) const { 
   return no_obs_between(first_date(),d);
};

int dated_observations::no_obs_after(const date& d) const {
   return no_obs_between(d,last_date());
};

