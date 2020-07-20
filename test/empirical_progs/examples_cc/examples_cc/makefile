LIB = libempirdata.a
$(LIB): 
	cd ../all_cc_progs; make libempirdata.a
	cp ../all_cc_progs/libempirdata.a .
tst.o: $(LIB)

CXX= gcc
CXXFLAGS = -c -O2 -I../all_cc_progs
%.o : %.cc
	$(CXX) $(CXXFLAGS) $*.cc
run_examples: run_examples.o $(LIB)
	$(CXX) -L. run_examples.o -lempirdata -lempirdata -o run_examples -lm -lstdc++
run: run_examples
	./run_examples
TO_CLEAN_FILES += $(LIB) 
TO_CLEAN_FILES += *.o *~ run_examples
TO_CLEAN_FILES += example*.cc
clean:
	rm -f $(TO_CLEAN_FILES) 
realclean: clean
ZIPFILE = examples_cc.zip
ALLFILES += run_examples.cc
pack:
	zip -u $(ZIPFILE) makefile $(ALLFILES)
crunch: clean
	zip -m -u $(ZIPFILE) $(ALLFILES) 
unpack:
	unzip -u $(ZIPFILE)
install-www:




