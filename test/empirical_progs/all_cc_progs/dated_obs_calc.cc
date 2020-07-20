#include "dated_obs.h"

bool dates_match(const dated_observations& d1, const dated_observations& d2){
   if (d1.size()!=d2.size()) { return false; } 
   for (unsigned int t=0;t<d1.size();++t){
      // slow, careful check that the time series match exactly
      if (d1.date_at(t) != d2.date_at(t)) return false;
   };
   return true;
};

double max_obs(dated_observations& dobs){
   vector<double> obs = dobs.elements();
   return *max_element(obs.begin(),obs.end()); 
};


double min_obs(dated_observations& dobs){
   vector<double> obs = dobs.elements();
   return *min_element(obs.begin(),obs.end()); 
};
