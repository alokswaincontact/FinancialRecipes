#ifndef _DATED_UTIL_H_
#define _DATED_UTIL_H_

template<class T> dated<T> observations_between( const dated<T>& obs, const date& first, const date& last) {
    //    cout << " picking obs between " << first << last << endl;
    dated<T> picked = obs;     // assume that the first and last date should be included.
    picked.remove_after(last);// just copy and then remove. Fast enough
    picked.remove_before(first);
    return picked;
};

template<class T> dated<T> observations_after( const dated<T>& obs, const date& first) {
    // assume that the first date is to be included in the result // should maybe be observations_on_and_after....
    dated<T> dobs = obs; // just copy and then remove. Fast enough
    dobs.remove_before(first);
    return dobs;
};

template<class T> dated<T> observations_before( const dated<T>& obs, const date& last) {
    dated<T> dobs = obs;     // assume that the last date is to be included in the result
    dobs.remove_after(last);
    return dobs;
};

template<class T> dated<T> end_of_year_observations(const dated<T>& dobs) {
    dated<T> eoy_obs;
    if (dobs.first_date().month()==1) {// take first obs in january as end of previous year
	eoy_obs.append(dobs.date_at(0),dobs.element_at(0));
    };
    for (unsigned int t=0;t<dobs.size()-1;++t) {
	if (dobs.date_at(t).year()!=dobs.date_at(t+1).year()) {
	    eoy_obs.append(dobs.date_at(t),dobs.element_at(t));
	};
    };
    if (eoy_obs.last_date().year() != dobs.last_date().year()) {
	eoy_obs.append(dobs.last_date(),dobs.element_at(dobs.size()-1));
    }
    return eoy_obs;
}

template<class T> dated<T> beginning_of_month_observations(const dated<T>& dobs) {
    dated<T> eom_obs;
    eom_obs.append(dobs.date_at(0),dobs.element_at(0));// take first observation always
    for (unsigned int t=1;t<dobs.size();++t) {
	if ( (dobs.date_at(t).month()!=dobs.date_at(t-1).month())|| (dobs.date_at(t).year()!=dobs.date_at(t-1).year()) ) {
	    eom_obs.append(dobs.date_at(t),dobs.element_at(t));
	};
    };
    return eom_obs;
}

template<class T> dated<T> end_of_month_observations(const dated<T>& dobs) {
   dated<T> eom_obs;
   for (unsigned int t=0;t<dobs.size()-1;++t) {
      if ( (dobs.date_at(t).month()!=dobs.date_at(t+1).month()) || (dobs.date_at(t).year()!=dobs.date_at(t+1).year())) {
	 eom_obs.append(dobs.date_at(t),dobs.element_at(t));
      };
   };
   if ( (eom_obs.last_date().month() != dobs.last_date().month()) || (eom_obs.last_date().year() != dobs.last_date().year()) ) {
      eom_obs.append(dobs.last_date(),dobs.element_at(dobs.size()-1));
   }
   return eom_obs;
};

template<class T> dated<T> observations_matching_dates( const dated<T>& obs, const vector<date>& dates){
   dated<T> dobs;
   for (unsigned int t=0;t<dates.size();++t){
      if (obs.contains(dates[t])) {
	 dobs.append(dates[t],obs.element_at(dates[t]));
      };
   };   return dobs;
};
#endif
