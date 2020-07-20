#include "dated.h"

void examples_dated(){
   cout << "TESTING dated<> simple " << endl;
   dated<double> dd;
   date d=date(1,1,1998);
   dd.insert(d,1);
   d = date(1,2,1998);
   dd.insert(d,2);
   cout << dd.size() << " elements " << endl;
   cout << dd ;
   cout << " inserting at 1/1 and 1/3 " << endl;
   dd.insert(date(1,1,1998),0.5);
   dd.insert(date(1,3,1998),3);
   cout << dd;
   cout << " deleting 1/2" << endl;
   dd.remove(date(1,2,1998));
   cout << dd;
   cout << " dated<string> " << endl;
   dated<string> ds;
   ds.insert(date(1,1,1998),"A");
   ds.insert(date(1,2,1998),"B");
   cout << ds;
   cout << "DONE test dated<>"  << endl;
};
