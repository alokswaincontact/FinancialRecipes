#include "dated_obs.h"

/////////// testing basic usage of dated observations //////////////////

inline dated_observations create_example_data_series_dated_observations(int wanted_size = 20 ) {
   dated_observations obs;
   string t("test data");
   obs.set_title(t);
   date d(1,1,1994);
   int i = 1;
   while (i<=wanted_size) {
      obs.insert(d++,double(i++));
   };
   return obs;
};

void example_dobs_simple() { 
    cout << "TEST simple, dated observation " << endl;
    cout << " first creating data series " << endl;
    dated_observations obs = create_example_data_series_dated_observations(10);
    obs.set_title(string("title"));
    cout << "  created list from " << obs.first_date() << " to  " << obs.last_date() << endl;
    cout << obs.size() << " observations " << endl;
    cout << " checking whether obs no 3 is picked" << endl;
    // check code to pick one date: // remember indexing is c style, starting with zero
    cout << " date 3 " << obs.date_at(3-1) << " " << obs.element_at(3-1) << endl;
    cout << " date 10 " << obs.date_at(10-1) << " " << obs.element_at(10-1) << endl;
    cout << "Done testing simple " << endl; 
    cout << "DONE TEST simple, dated observation " << endl;
};

void example_dobs_indexing(){
   cout << "TESTING indexing " << endl;
    dated_observations obs = create_example_data_series_dated_observations(5);
    cout << " checking indexing, should get 1 - 5 " << endl;
    for (int t=0;t<5;t++){
	cout << obs.date_at(t) << " " << obs.element_at(t) << endl;
    };
   cout << "DONE TESTING indexing " << endl;
};

void example_dobs_insertion() {
   cout << "TESTING insertion: if adding one element is in the correct place " << endl;
   dated_observations  obs;
   date d0 (31,12,1993);
   date d1 (3,1,1994);
   date d2 (2,2,1994);
   date d3 (28,12,1993);
   date d4 (30,12,1993);
   cout << " insert  " << d0 << endl;
   obs.insert(d0,0.5);
   cout << obs;
   cout << " insert  " << d1 << endl;
   obs.insert(d1,0.5);
   cout << obs;
   cout << " insert  " << d2 << endl;
   obs.insert(d2,0.5);
   cout << obs;
   cout << " insert  " << d3 << endl;
   obs.insert(d3,0.5);
   cout << obs;
   cout << " insert  " << d4 << endl;
   obs.insert(d4,0.5); 
   cout << obs;
   cout << " changing value of " << d1 << endl;
   obs.insert(d1,1.0); 
   cout << obs;
   cout << "DONE testing insertion" << endl;
};

void example_dobs_removals(){
   cout << "TESTING removals: check if removing elements based on date works  " << endl;
   dated_observations obs = beginning_of_month_observations(create_example_data_series_dated_observations(300));
   cout << obs;
   cout << " after deleting between " << obs.date_at(3) << " and " << obs.date_at(6) << endl;
   obs.remove_between(obs.date_at(3), obs.date_at(6));
   cout << obs ;
   cout << " after deleting after " << obs.date_at(6) << endl;
   obs.remove_after(obs.date_at(6));
   cout << obs ;
   cout << " after deleting before " << obs.date_at(3) << endl;
   obs.remove_before(obs.date_at(3));
   cout << obs ;
   cout << "DONE TESTING removals " << endl;
};

void example_dobs_counting(){
   cout << "TESTING COUNTING " << endl;
    dated_observations obs = create_example_data_series_dated_observations(10);
    cout << " total (should be 10) = " << obs.size() << endl;
    date d1=date(4,1,1994);
    cout << obs.no_obs_before(d1) << "  observations before " << d1 << endl;
    cout << obs.no_obs_after(d1) << "  observations after " << d1 << endl;
    date d2 = date(7,1,1994);
    cout << obs.no_obs_between(d1,d2) << " observations between " << d1 << " and " 
	 << d2 << endl;
    cout << "DONE TESTING counting " << endl;
};

void example_dobs_pick_part() {
   cout << "TESTING DATED OBSERVATIONS:  pick part of time series" << endl;
   // check if I'm able to pick part of the time series.
   dated_observations dobs =  create_example_data_series_dated_observations(10);
   cout << " before picking " << endl;
   cout << dobs;
   dated_observations picked = observations_between(dobs, date(1,1,1994), date(4,1,1994));
   cout << " after picking between 1/1/94 and 4/1/94 " << endl;
   cout << picked;
   cout << "DONE TESTING  pick part of time series" << endl;
};

/////////////////////////////////////////////////////////////
// calling the routines for testing of basics.

void examples_dated_obs(){
    example_dobs_simple(); 
    example_dobs_indexing();
    example_dobs_insertion();
    example_dobs_removals();
    example_dobs_counting();
    example_dobs_pick_part();
};
