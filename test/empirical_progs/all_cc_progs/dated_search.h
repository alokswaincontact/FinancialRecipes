#include <algorithm>

template<class T> bool dated<T>::contains(const date& d) const {
   return binary_search(dates_.begin(),dates_.end(),d);
};

template<class T>  date dated<T>::first_date() const { 
    if (empty()) return date(); 
    return dates_.front();
};

template<class T> date dated<T>::last_date() const { 
   if (empty()) return date(); 
   return dates_.back();
};

template<class T> T dated<T>::first_element() const { 
   if (empty()) return T(); 
   return elements_.front();
};

template<class T> T dated<T>::last_element() const { 
   if (empty()) return T(); 
   return elements_.back();
};

template <class T> int dated<T>::index_of_date(const date& d) const {
   // this routine returns the index at which date d is, or -1 if not found.
   if (!d.valid()) return -1;
   if (!contains(d)) return -1;
   int dist=0;
   for (unsigned int i=0;i<dates_.size();++i){
       if (dates_[i]==d) return i; // slow implementation, but works (for now), 
   };
   return dist;
};

template <class T> int dated<T>::index_of_first_date_after(const date& d) const {
    // this routine returns the index of the first date after d.
    if (!d.valid()) return -1;
    if (d>=last_date()) return -1;
    if (d<first_date()) return 0;
    for (unsigned int i=0;i<dates_.size();++i){
	if (dates_[i]>d) return i;
    };
    return -1;
};

template <class T> int dated<T>::index_of_last_date_before(const date& d) const {
    // this routine returns the index of the first date before d.
    if (!d.valid()) return -1;
    if (d<=first_date()) return -1;
    if (d>last_date()) return index_of_date(last_date());
    for (unsigned int i=0;i<dates_.size();++i){
	if (dates_[i]>=d) return i-1; // slow implementation, but works (for now)
    };
    return -1;
};
