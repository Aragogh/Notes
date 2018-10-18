#include <iostream>
using namespace std;

int main()
{
  int odostrt;
  int odoend;
  int days;
  string lux;

  cout << "Odometer at start:";
  cin >> odostrt;
  cout << "Odometer at end:";
  cin >> odoend;

  int miles = odoend - odostrt;
  
  cout << "Rental days:";
  cin >> days;
  cin.ignore(10000, '\n');
  
  cout << "Customer name:";
  string name;
  getline(cin, name);

  cout<< "Luxury car? (y/n):";
  cin >> lux;

  int month;
  cout << "Month (1=Jan, 2=Feb, etc.):";
  cin >> month;
  cout << "---" << endl;

  // The following is ugly, but in my defense I missed class and hadn't known if we were allowed to use switch statements or not. There's an easier, much more elegant case number assigning solve that I had in mind, but I committed to this and so I went for it and it works. I apologize, please forgive me.
  
  float charge;
  int base;
    if (lux == "y") {
      base = 61;
      if ( odostrt < 0 ) {
	cout << "The starting odometer reading must be nonnegative.";
      }
      else if ( odostrt > odoend ) {
	cout << "The final odometer reading must be at least as large as the starting reading.";
	  }
      else {
	if ( name == "" ) {
	  cout << "You must enter a customer name";
	}
	else {
	  if ( month < 1 || month > 12 ) {
	    cout << "The month number must be in the range 1 through 12.";
	  }
	  else {
	    	    if ( days < 0 ) {
		      cout << "The number of rental days must be positive.";
		}
		    else {
		      
	    	    if ( month < 12 && month > 3 ) {
		      charge = 0.21;
		      if ( miles < 100 ) {
			double amount = base*days + ( miles * 0.27 );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		      else {
			double amount = base*days + ( 100 * 0.27 ) + ( ( miles - 100 ) * charge );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		    }
		    else {
		      charge = 0.27;
		      	      if ( miles < 100 ) {
			double amount = base*days + ( miles * 0.27 );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		      else {
			double amount = base*days + ( 100 * 0.27 ) + ( ( miles - 100 ) * charge );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
	    }
		    }
	  }
	}
      }
    }
    else if (lux == "n") {
      base = 33;
      if ( odostrt < 0 ) {
	cout << "The starting odometer reading must be nonnegative.";
      }
      else if ( odostrt > odoend ) {
	cout << "The final odometer reading must be at least as large as the starting reading.";
	  }
      else {
	if ( name == "" ) {
	  cout << "You must enter a customer name.";
	}
	else {
	  if ( month < 1 || month > 12 ) {
	    cout << "The month number must be in the range 1 through 12.";
	  }
	  else {
	    if ( days < 0 ) {
	      cout << "The number of rental days must be positive.";
		}
	    else {
	    	    if ( month < 12 && month > 3 ) {
		      charge = 0.21;
		      if ( miles < 100 ) {
			double amount = base*days + ( miles * 0.27 );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		      else {
			double amount = base*days + ( 100 * 0.27 ) + ( ( miles - 100 ) * charge );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		    }
		    else {
		      charge = 0.27;
		      	      if ( miles < 100 ) {
			double amount = base*days + ( miles * 0.27 );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		      else {
			double amount = base*days + ( 100 * 0.27 ) + ( ( miles - 100 ) * charge );
		        cout << "The rental charge for " << name << "is $" << amount;
		      }
		    }
	    }
	  }
	}
      }
    }
    else {
      cout << "You must enter y or n";
    }

    }
