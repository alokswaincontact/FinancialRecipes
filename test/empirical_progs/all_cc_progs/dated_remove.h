
template<class T> void dated<T>::clear() {
   dates_    .erase(dates_    .begin(),dates_    .end());
   elements_ .erase(elements_ .begin(),elements_ .end());
};

template<class T> void dated<T>::remove(const date& d) {
   int i=index_of_date(d);
   if (i>=0) {
      dates_.erase(dates_.begin()+i);
      elements_.erase(elements_.begin()+i);
   };
};

template<class T> void dated<T>::remove_between(const date& d1, const date& d2) {
    //    cout << " removing between " << d1 << d2 << endl;
    if (!d1.valid()) return;
    if (!d2.valid()) return;
    if ( (d1<first_date()) && (d2>last_date()) ) {
	dates_.clear();
	elements_.clear();
	return;
    };
    /* below has a bug, use the slow version for now
    ** problem is that the last observation before the one to be removed is not removed.
       int first=index_of_first_date_after(d1);
       int last=index_of_last_date_before(d2);
       cout << " first " << first << " last " << last << endl;
       cout << " before " << first_date() << last_date() << endl;
       if ( (first>=0) && (last>=0) ) {
       if (first==last) { // just remove one element
       dates_ .erase(dates_ .begin()+first);
       elements_ .erase(elements_ .begin()+first); 
       }
       else if (first<last) {
       if (d2>last_date()){
       dates_ .erase(dates_ .begin()+first,dates_ .end());
       elements_ .erase(elements_ .begin()+first,elements_ .end()); 
       }
       else if (d1<first_date()) {
       dates_ .erase(dates_ .begin(),dates_ .begin()+last);
       elements_ .erase(elements_ .begin(),elements_ .begin()+last); 
       }
       else {
       dates_ .erase(dates_ .begin()+first,dates_ .begin()+last);
       elements_ .erase(elements_ .begin()+first,elements_ .begin()+last); 
       };
       };
       };
       cout << " after " << first_date() << last_date() << endl;
    */

    for (int t=size()-1;t>=0;t--){  // this is very slow, to be replaced with one using vector erase.
	date d=date_at(t);
	if ( (d>d1) && (d<d2) ) { 
	    dates_.erase(dates_.begin()+t);
	    elements_.erase(elements_.begin()+t);
	};
    };

};


template<class T> void dated<T>::remove_between_including_end_points(const date& d1, const date& d2) {
    if (!d1.valid()) return;
    if (!d2.valid()) return;
    remove_between(d1,d2); // simply use above, and then remove two end points
    remove(d1);
    remove(d2);
    /*
    for (int t=size()-1;t>=0;t--){  // this is very slow, to be replaced with one using vector erase.
	date d=date_at(t);
	if ( (d>=d1) && (d<=d2) ) { 
	    dates_.erase(dates_.begin()+t);
	    elements_.erase(elements_.begin()+t);
	};
    };
    */
};

template<class T> void dated<T>::remove_before(const date& d) {
   remove_between(--first_date(),d);
};

template<class T> void dated<T>::remove_after(const date& d) {
    remove_between(d,++last_date());
};

template <class T> ostream& operator << (ostream& outf, const dated<T>& dobs ) {
   if (dobs.empty()) return outf;
   for (unsigned int t=0; t<dobs.size(); ++t) {
      outf << dobs.date_at(t) << " "  << dobs.element_at(t)  << endl;
   };
   return outf;
};
