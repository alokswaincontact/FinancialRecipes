#include "dated_obs.h"

dated_observations observations_between( const dated_observations& obs,
					 const date& first,
					 const date& last) {
// assume that the first and last date should be included.
    dated_observations picked = obs; // just copy and then remove. Fast enough
    picked.remove_after(last);
    picked.remove_before(first);
    return picked;
};

dated_observations observations_after( const dated_observations& obs,
				       const date& first) {
// assume that the first date is to be included in the result
// should maybe be observations_on_and_after....
   dated_observations dobs = obs; // just copy and then remove. Fast enough
   dobs.remove_before(first);
   return dobs;
};

dated_observations observations_before( const dated_observations& obs,
					const date& last) {
// assume that the last date is to be included in the result
   dated_observations dobs = obs; 
   dobs.remove_after(last);
   return dobs;
};
