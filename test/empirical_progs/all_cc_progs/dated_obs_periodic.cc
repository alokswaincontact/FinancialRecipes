#include "dated_obs.h"

dated_observations end_of_year_observations(const dated_observations& dobs) {
   if (dobs.size()<1) return dated_observations();
    dated_observations eoy_obs;
    eoy_obs.set_title(dobs.title());
    if (dobs.first_date().month()==1) { // include beginning of first year
	eoy_obs.insert(dobs.date_at(0),dobs.element_at(0)); 
    };  
    for (int t=0;t<dobs.size()-1;++t) {
	if (dobs.date_at(t).year()!=dobs.date_at(t+1).year()) {
	    eoy_obs.insert(dobs.date_at(t),dobs.element_at(t));
	};
    };
    if (eoy_obs.last_date().year() != dobs.last_date().year()) {
	eoy_obs.insert(dobs.last_date(),dobs.element_at(dobs.size()-1));
    }
    return eoy_obs;
};

dated_observations end_of_year_current_observations(const dated_observations& dobs) {
   if (dobs.size()<1) return dated_observations();
    dated_observations eoy_obs;
    eoy_obs.set_title(dobs.title());
    if (dobs.first_date().month()==1) {	eoy_obs.insert(dobs.date_at(0),dobs.element_at(0)); };  
    for (int year=dobs.first_date().year(); year<=dobs.last_date().year(); ++year){
	eoy_obs.insert(date(31,12,year),dobs.current_element_at(date(31,12,year))); 
    };
    return eoy_obs;
}

dated_observations beginning_of_month_observations(const dated_observations& dobs) {
    if (dobs.size()<1) return dated_observations();
    dated_observations eom_obs;
    eom_obs.set_title(dobs.title());
    if (dobs.first_date().day()<5) { eom_obs.insert(dobs.date_at(0),dobs.element_at(0)); };
    for (int t=1;t<dobs.size();++t) {
	if ( (dobs.date_at(t).month()!=dobs.date_at(t-1).month())
	     || (dobs.date_at(t).year()!=dobs.date_at(t-1).year()) )	{
	    eom_obs.insert(dobs.date_at(t),dobs.element_at(t));
	};
    };
    return eom_obs;
}

dated_observations end_of_month_observations(const dated_observations& dobs) {
    if (dobs.size()<1) return dated_observations();
    dated_observations eom_obs;
    eom_obs.set_title(dobs.title());
    if (dobs.first_date().day()<10) { eom_obs.insert(dobs.date_at(0),dobs.element_at(0)); };
    for (int t=0;t<dobs.size()-1;++t) {
	if ( (dobs.date_at(t).month()!=dobs.date_at(t+1).month())
	     || (dobs.date_at(t).year()!=dobs.date_at(t+1).year()) )	{
	    eom_obs.insert(dobs.date_at(t),dobs.element_at(t));
	};
    };
    if ( (eom_obs.last_date().month() != dobs.last_date().month())
	 || (eom_obs.last_date().year() != dobs.last_date().year()) ) {
	eom_obs.insert(dobs.last_date(),dobs.element_at(dobs.size()-1));
    }
    return eom_obs;
};
