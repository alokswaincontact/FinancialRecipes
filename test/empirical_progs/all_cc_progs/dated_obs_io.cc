#include "dated_obs.h"
#include <iomanip>

void print_dated_observations(ostream& of, 
			      const dated_observations& obs,
			      int precision) {
   if (obs.title().length()>0) of <<  obs.title()  << endl; 
   for (unsigned int t=0;t<obs.size();t++) {
       of << obs.date_at(t) << " "
      	 << setprecision(precision) << fixed << obs.element_at(t) 
	 << endl;
   };
};

ostream& operator << (ostream& os, const dated_observations& obs) {
    print_dated_observations(os,obs,4);
    return os;
};
