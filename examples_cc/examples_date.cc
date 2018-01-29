#include "date.h"

void example_date_simple(){
   cout << "TESTING DATE SIMPLE " << endl;
   cout << " construction: date(1,1,1998):" << date(1,1,1998) <<endl;
   cout << " increment: ++date(1,1,1998):" << ++date(1,1,1998) << endl;
   cout << " decrement: --date(1,1,1998):" << --date(1,1,1998) << endl;
   date d(1,1,2006);
   cout << "valid date(1,1,2006) ?" << date(1,1,2006).valid() << endl;
   cout << "valid date(33,1,2006) ?" << date(33,1,2006).valid() << endl;
   cout << "DONE TESTING DATE SIMPLE " << endl;
}

inline void dates_comparisons(date d1, date d2) {
    cout <<"COMPARISON TEST" << endl;
    cout << " Comparing " << d1 << "and" << d2 << endl;
    cout << "  is" << d1 <<"equal to      "  << d2 ;
    if (d1==d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
    cout << "  is" << d1 <<"different from"  << d2 ;
    if (d1!=d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
    cout << "  is" << d1 <<"less than     "  << d2 ;
    if (d1<d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
    cout << "  is" << d1 <<"greater than  "  << d2 ;
    if (d1>d2){ cout << "YES"; } else { cout << "NO"; };
    cout << endl;
};

void example_date_comparisons (){
   cout << "TESTING DATE COMPARISONS " << endl;
   date d1(25,7,1993);
   date d2(8,10,1993);
   dates_comparisons (d1,d2);
   dates_comparisons (d1,d1);
   cout << "DONE TESTING DATE COMPARISONS " << endl;
};

void examples_date() {
   cout << "TESTING DATE " << endl;
   example_date_simple();
   example_date_comparisons();
   cout << "DONE TESTING DATE " << endl;
};
