#ifndef _DATED_H_
#define _DATED_H_

#include <vector>     
#include "date.h"       // my date class

template <class T> class dated {
private:
    vector<date> dates_;
    vector<T> elements_;
public:
    dated<T>();
    dated<T>(const dated<T>&);
    dated<T> operator= (const dated<T>&);
    ~dated() { clear(); }; 
    void clear();                     // erasing
    void insert(const date&, const T&); // insert somewhere
  
    bool empty() const ;
    int size() const ;
    bool contains(const date& d) const ;
    date date_at(const int& t) const ; // accessing elements, here dates
    T element_at(const int& t) const ;  // index directly
    T element_at(const date& d) const ; // index indirectly, specify what date

    // next: the element either on date d, if d is here, else the last observation before d.
    T current_element_at(const date& d) const ;

    vector<T> elements() const; // all elements as vector<T>
    vector<date> dates() const;  // all dates as vector<date>

    date first_date() const;  // simple queries
    date last_date() const;
    T first_element() const;
    T last_element() const;

    int index_of_date(const date& d) const; // when searching in the data, 
    int index_of_last_date_before(const date& d) const; // these are useful functions
    int index_of_first_date_after(const date& d) const;

    void remove(const date&);         // removing one or more elements
    void remove_between_including_end_points(const date&, const date&);
    void remove_between(const date&, const date&);
    void remove_before(const date&);
    void remove_after(const date&);
};

#include "dated_main.h"
#include "dated_search.h"
#include "dated_remove.h"

template<class T> dated<T> observations_between(const dated<T>& obs,const date&first, const date& last);
template<class T> dated<T> observations_after(const dated<T>& obs, const date& first);
template<class T> dated<T> observations_before(const dated<T>& obs, const date& last);
template<class T> dated<T> end_of_year_observations(const dated<T>&);
template<class T> dated<T> beginning_of_month_observations(const dated<T>&);
template<class T> dated<T> end_of_month_observations(const dated<T>&);
template<class T> dated<T> observations_matching_dates(const dated<T>& obs, const vector<date>& dates);

#include "dated_util.h"
#endif 
