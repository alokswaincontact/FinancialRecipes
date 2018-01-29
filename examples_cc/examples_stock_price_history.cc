#include "stock_price_history.h"

//////////////////////////////////////////////////////
///  simplest possible test //////////////////////////
//////////////////////////////////////////////////////

void example_simple(){
   cout << "TESTING simple creation and copying of stock price history " << endl;
   stock_price_history sh;
   sh.set_security_name("Stock name");
   date d(1,1,1996);
   double bid   = 99.8;
   double price = 100;
   double ask   = 100.8;
   sh.add_prices(d++,bid,ask,price);
   double e = 0.04;
   sh.add_prices(d++,bid+=e,ask+=e,price+=e);
   e=-0.2;
   sh.add_prices(d++,bid+=e,ask+=e,price+=e); 
   
   cout<< "size " << sh.size() << endl;
   stock_price_history sh1(sh);
   cout << "dumping constr copy " << endl;
   cout<< "size " << sh1.size() << endl;
   stock_price_history sh2 = sh; 
   cout << " dumping copy" << endl;
   cout<< "size " << sh2.size() << endl;
   sh2.clear();
   sh2=sh;
   cout << " dumping copied onto copy" << endl;
   cout<< "size " << sh2.size() << endl;
   cout << " done test copying " << endl;
   cout << "DONE TESTING simple creation and copying of stock price history " << endl;
};

////////////////////////////////////////////////////////////////////
// general utility used in other testing. //////////////////////////
////////////////////////////////////////////////////////////////////

inline stock_price_history create_stock_price_test_history(int no_days=20){
   stock_price_history sh;
   date d(1,1,1980);
   double p=100;
   for (int day=0;day<no_days;day++) {
      sh.add_prices(d,p-0.005,p,p+0.005);
      d++;
      p*=1.001;
   };
   return sh;
}

/////////////////////////////////////////////////////////////
// test basics ////////
/////////////////////////////////////////////////////////////

void example_empty(){
    cout << "TEST: whether empty works well " << endl;
    stock_price_history sh;
    if (sh.empty()) { cout << " claims empty when empty " << endl; }
    else { cout << " claims nonempty when empty " << endl; }
    sh.set_security_name("name");
    if (sh.empty()) { cout << " claims empty when nonempty " << endl; }
    else { cout << " claims nonempty when nonempty " << endl; }
    sh.set_security_name("");
    if (sh.empty()) { cout << " claims empty when empty " << endl; }
    else { cout << " claims nonempty when empty " << endl; }
    sh.add_dividend(date(1,1,1980),10.0);
    if (sh.empty()) { cout << " claims empty when nonempty " << endl; }
    else { cout << " claims nonempty when nonempty " << endl; }
    cout << "DONE test of empty " << endl;
};

void example_delete() {
   cout << "TESTING: Delete prices " << endl;
   cout << " first create stock price history with 10 obs " << endl;
   stock_price_history sh = create_stock_price_test_history(10);
   cout << " before doing any erasing " << endl;
   cout<< "size " << sh.size() << endl;   
   sh.erase_before(date(4,1,80));
   cout << "after deleting  before 4/1" << endl;
   cout<< "size " << sh.size() << endl;   
   sh.erase_after(date(7,1,80));
   cout << "after deleting after 7/1" << endl;
   cout<< "size " << sh.size() << endl;   
   cout << "DONE testing deleting " << endl;
};


///////////////////////////////////////////////////////////////////
// testing adjustments ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void example_adjustments(){
   cout << "TESTING adding adjustments to stock price history " << endl;
   cout << " first create 2 period " << endl;
   stock_price_history sh = create_stock_price_test_history(2);
   cout << "size " << sh.size() << endl;   
   cout << " then add adjustment on 1/1/80" << endl;
   sh.add_adjustment(date(1,1,1980),1.5);
   cout << "size " << sh.size() << endl;   
   cout << " then remove adjustment on 1/1/80" << endl;
   sh.remove_adjustment(date(1,1,1980));
   cout << "size " << sh.size() << endl;   
   cout << "DONE TESTING adjustments " << endl;
};


///////////////////////////////////////////////////////////////////
// testing dividends ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void example_dividends(){
   cout << "TESTING adding dividends to stock price history " << endl;
   cout << " first create 2 period stock price history " << endl;
   stock_price_history sh = create_stock_price_test_history(2);
   cout<< "size " << sh.size()  << endl;   
   cout << " then add dividend on 1/1/80" << endl;
   sh.add_dividend(date(1,1,1980),1.5);
   cout<< "size " << sh.size() << endl;   
   cout << " then remove dividend on 1/1/80" << endl;
   sh.remove_dividend(date(1,1,1980));
   cout<< "size " << sh.size() << endl;   
   cout << "DONE TESTING dividends " << endl;
};

/////////////////////////////////////////////////////////////////////////////

void examples_stock_price_history(){
    cout << "TESTING: stock price history class " << endl;
    example_simple();
    example_empty();
    example_delete();
    example_adjustments();
    example_dividends();
    cout << "DONE: all testing of stock price history class " << endl;
};

