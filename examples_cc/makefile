ALLFILES = run_all_examples.cc

LIB = librecipes.a 

################################################
## IF NEWMAT IS AVAILABLE, UNCOMMENT
# may need to set path here, change to reflect your setup
#### CXXFLAGS += -I/home/bernt/include 
#### LIBS +=  -L/home/bernt/lib 
# CXXFLAGS += -D_HAVE_NEWMAT_ 
# LIBS +=  -lnewmat

################################################
## IF IT++ IS AVAILABLE, UNCOMMENT
# CXXFLAGS += -D_HAVE_ITPP_ 
# LIBS +=  -litpp -lcblas -latlas


################################################
## IF GSL IS AVAILABLE, UNCOMMENT
# CXXFLAGS += -D_HAVE_GSL_
# LIBS += -lgsl 

run_all_examples.o: librecipes.a ../all_cc_progs/fin_recipes.h ../all_cc_progs/normdist.h $(LIB) 
run_all_examples: librecipes.a run_all_examples.o 
	g++ run_all_examples.o  $(LIBS) -L. -lrecipes  -o run_all_examples 
run: run_all_examples
	./run_all_examples
