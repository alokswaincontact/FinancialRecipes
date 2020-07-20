testing.o: fin_recipes.h

CXX= gcc
CXXFLAGS = -c -O2
 %.o : %.cc
	$(CXX) $(CXXFLAGS) $*.cc

# date class
HXX_FILES += date.h
CXX_FILES += date.cc date_compare.cc date_iterate.cc
LIBOBJS += date.o date_compare.o date_iterate.o

# dated class (templated)
HXX_FILES += dated.h dated_main.h dated_remove.h dated_search.h dated_util.h

# dated observations class
HXX_FILES    += dated_obs.h
CXX_FILES    += dated_obs.cc \
                dated_obs_calc.cc dated_obs_io.cc dated_obs_periodic.cc dated_obs_subsets.cc
LIBOBJS      += dated_obs.o \
                dated_obs_calc.o dated_obs_io.o dated_obs_periodic.o dated_obs_subsets.o

# security price history
HXX_FILES += security_price_history.h
CXX_FILES += security_price_history.cc security_price_history_erase.cc security_price_history_prices.cc \
             security_price_history_search.cc security_price_history_sizes.cc security_price_history_utils.cc
LIBOBJS   += security_price_history.o security_price_history_erase.o security_price_history_prices.o \
             security_price_history_search.o security_price_history_sizes.o security_price_history_utils.o

# stock price history
HXX_FILES += stock_price_history.h
CXX_FILES += stock_price_history.cc stock_price_history_adjustments.cc stock_price_history_dividends.cc
LIBOBJS   += stock_price_history.o stock_price_history_adjustments.o stock_price_history_dividends.o

LIB = libempirdata.a 
$(LIB): $(LIBOBJS)
	ar r $(LIB) $(LIBOBJS)
lib:  $(LIB)
ZIPFILE = all_cc_progs.zip
ALLFILES = empirical_data.h
TO_CLEAN_FILES += $(LIB) 
TO_CLEAN_FILES += *.o *~
TO_CLEAN_FILES += $(HXX_FILES) $(CXX_FILES)
clean:
	rm -f $(TO_CLEAN_FILES) 
realclean: clean
pack:
	zip -u $(ZIPFILE) makefile $(ALLFILES)
crunch: clean
	zip -m -u $(ZIPFILE) $(ALLFILES) 
unpack:
	unzip -u -o $(ZIPFILE)
install-h:
install-lib:
install-www: