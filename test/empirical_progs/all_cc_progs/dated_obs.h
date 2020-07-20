#ifndef _DATED_OBS_H_
#define _DATED_OBS_H_

#include "dated.h"      // templated dated<> class
#include <string>     // ANSI string class

class dated_observations : public dated<double>{
   private:
      string         title_;
   public:            
      ~dated_observations() { clear(); };
      void clear();         

      void set_title(string s); // title
      string title() const;

      int no_obs() const;
      int no_obs_between(const date& d1, const date& d2) const;
      int no_obs_before(const date& d) const;
      int no_obs_after(const date& d) const;
};

///// io 
ostream& operator << (ostream&, const dated_observations& );
void print_dated_observations(ostream& of, const dated_observations& d, int precision=3);

//// mischellaneous utilities 
double max_obs(dated_observations& dobs);
double min_obs(dated_observations& dobs);
bool dates_match(const dated_observations& obs1, const dated_observations& obs2);

///// picking subsets.
dated_observations observations_between(const dated_observations& obs,const date& first,const date& last);
dated_observations observations_after(const dated_observations& obs, const date& first);
dated_observations observations_before(const dated_observations& obs, const date& last);
dated_observations observations_matching_dates(const dated_observations& obs, const vector<date>& dates);

///// picking periodic elements
dated_observations beginning_of_month_observations(const dated_observations&);
dated_observations end_of_month_observations(const dated_observations&);
dated_observations end_of_year_observations(const dated_observations&);
dated_observations end_of_year_current_observations(const dated_observations&);

#endif
