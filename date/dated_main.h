template<class T> dated<T>::dated(){;};   // not necessary to do anything, 

template<class T>dated<T>::dated(const dated<T>& dobs) {
    // for speed, initialize first with correct size and then copy
    dates_=vector<date>(dobs.size());
    elements_=vector<T>(dobs.size());
    for (unsigned int t=0;t<dobs.size();++t){
	dates_[t]      = dobs.date_at(t);
	elements_[t]   = dobs.element_at(t);
    };
};

template<class T> dated<T> dated<T>::operator= (const dated<T>& dobs) {
    if (this==&dobs) return *this; // check against self assignment;
    clear();
    dates_=vector<date>(dobs.size());
    elements_=vector<T>(dobs.size());
    for (unsigned int t=0;t<dobs.size();++t){
	dates_[t]        = dobs.date_at(t);
	elements_[t]     = dobs.element_at(t);
    };   
    return *this;
};

//template<class T> dated<T>::~dated(){;};

template<class T> bool dated<T>::empty() const { return (dates_.size()<1); };  

template<class T> int dated<T>::size() const { return int(dates_.size()); };

template<class T> date dated<T>::date_at(const int& t) const { // accessing with bounds checking 
   if ( (t>=0) && (t<size()) ) return dates_[t];
   return date();
};

template<class T> T dated<T>::element_at(const int& t) const {  // accessing with bounds checking 
   if ( (t>=0) && (t<size()) ) return elements_[t]; 
   return T();
};

template<class T> T dated<T>::element_at(const date& d) const {
   if (!contains(d)) return T();
   return elements_[index_of_date(d)];
};

template<class T> T dated<T>::current_element_at(const date& d) const {
    // the element either on date d, if d is here, else the last observation before d.
    if (size()<1) return T();
    if (contains(d)) return element_at(d);
    if (d<first_date()) { return T(); };
    return elements_[index_of_last_date_before(d)];
};

template<class T>  vector<T> dated<T>::elements() const {
    vector<T> elements(size());
    for (unsigned int t=0; t<size(); ++t){ elements[t]=element_at(t); };
    return elements;
};;

template<class T> vector<date> dated<T>::dates() const { 
    vector<date> ds(size());
    for (unsigned int t=0;t<size();++t){ ds[t]=date_at(t); };
    return ds;
};

template <class T> void dated<T>::insert(const date& d, const T& obs) {
    if (!d.valid()) return;
    if ( (empty() ) || (d>last_date()) ) {
	dates_.push_back(d);
	elements_.push_back(obs);
	return;
    };
    if (d<first_date()) {
	dates_.insert(dates_.begin(),d);
	elements_.insert(elements_.begin(),obs);
	return;
    };
    if (contains(d)) {
	int i = index_of_date(d);
	elements_[i]=obs;
	return;
    };
    int i = index_of_first_date_after(d);
    if (i>=0) {
	dates_.insert(dates_.begin()+i,d);
	elements_.insert(elements_.begin()+i,obs); 
    };
    return;
};
