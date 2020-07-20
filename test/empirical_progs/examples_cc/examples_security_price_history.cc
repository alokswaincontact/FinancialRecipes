// file example_security_price_history.cc


#include "security_price_history.h"

/////////////////////////////////////////////////////////////
//// simple testing of whether the class works.

void example_simple_security_price_history(){
   cout << "TEST: creating security history class" << endl;
   security_price_history sh;
   sh.add_prices(date(1,1,1996),0,1,2);
   cout << "size of sh : " << sh.size() << endl;
   cout << "DONE TEST: creating security history class" << endl;
};


void example_empty_sph(){
    cout << "TESTING whether the empty() call works well " << endl;
    security_price_history sh;
    if (sh.empty()) { cout << " claims empty when empty " << endl; }
    else { cout << " claims nonempty when empty " << endl; }
    sh.set_security_name("name");
    if (sh.empty()) { cout << " claims empty when nonempty " << endl; }
    else { cout << " claims nonempty when nonempty " << endl; }
    sh.set_security_name("");
    sh.add_prices(date(1,1,1980),1,1,1);
    if (sh.empty()) { cout << " claims empty when nonempty " << endl; }
    else { cout << " claims nonempty when nonempty " << endl; }
    cout << "DONE TESTING whether the empty() call works well " << endl;
};

//////////////////////////////////////////////////////////////////////////
// one function that creates a test history
//////////////////////////////////////////////////////////////////////////
security_price_history create_test_security_price_history(int no_days=20) {
    security_price_history sh;
    date d(1,1,1996);
    double p=1;
    for (int day=0;day<no_days;day++) {
       sh.add_prices(d,p*0.99,p,p*1.01); 
       d++;
       p*= 1.01;
    };
    return sh;
};

//////////////////////////////////////////////////////////////////////////
// check that the copy constructor work
///////////////////////////////////////////////////////////////////////// 

void example_copying_sph (){
   cout << "TEST: how the copying constructors work " << endl;
   cout << " All price histories should be equal " << endl;
   security_price_history sh = create_test_security_price_history(3);
   cout << " original " << endl;
   cout << sh.size() << " size " << endl;
   cout << " after copy constructor " << endl;
   security_price_history sh2(sh);
   cout << sh2.size() << " size " << endl;
   cout << " after operator = " << endl;
   security_price_history sh3=sh;
   cout << sh3.size() << " size " << endl;
   cout << "DONE TEST: how copying constructors work " << endl;
}

//////////////////////
// testing deletion //
//////////////////////

void example_delete_data_sph (){
   cout <<"TEST: Deleting data in history " << endl;
   security_price_history sh = create_test_security_price_history(15);
   cout << "original " << endl;
   cout << sh.size() << " size " << endl;
   sh.erase(date(2,1,1996));
   cout << " after deleting 2/1 " << endl;
   cout << sh.size() << " size " << endl;
   sh.erase(date(2,1,1996));
   cout << " after deleting 2/1 once more, should not change" << endl;
   cout << sh.size() << " size " << endl;
   cout << " deleting before 4/1 " << endl;
   sh.erase_before(date(4,1,1996)); 
   cout << sh.size() << " size " << endl;
   cout << " deleting after 13/1 " << endl;
   sh.erase_after(date(13,1,1996));
   cout << sh.size() << " size " << endl;
   cout << " deleting between 7/1 and 10/1 " << endl;
   sh.erase_between(date(7,1,1996),date(10,1,1996));
   cout << sh.size() << " size " << endl;

   cout << " now deleting after day before first date, should get empty" << endl;
   sh.erase_after(--sh.first_date());
   cout << sh.size() << " size " << endl;
   cout <<"DONE TEST: Deleting data in history " << endl;
};


//////////////////////
// testing addition //
//////////////////////

void example_add_data_sph(){
    cout << "TEST adding data in the middle " << endl;
    security_price_history sh = create_test_security_price_history(3);
    cout << " now adding on top, 2/1 " << endl; 
    date d(2,1,1996);
    sh.add_prices(d,1000,1000,1000);
    cout << " now adding after last, 2/2 " << endl;
    d=date(2,2,1996);
    sh.add_prices(d,1000,1000,1000);
    cout << " now adding before first, 31/12/95 " << endl;
    sh.add_prices(date(31,12,1995),1000,1000,1000);
    cout << sh.size() << " elements " << endl;
    cout << "DONE test middle " << endl;
};

////////////////////////////////////////////////////
/// calling all the above routines /////////////////
////////////////////////////////////////////////////

void examples_security_price_history() {
   example_simple_security_price_history();
   example_empty_sph();
   example_copying_sph();
   example_delete_data_sph();
   example_add_data_sph();
};


