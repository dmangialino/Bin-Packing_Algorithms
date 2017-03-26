#ifndef BIN_H
#define BIN_H

#include <iostream>
using namespace std;

class Bin {
  private:
    double amount_of_space_used_;
  public:
    Bin() {
      amount_of_space_used_ = 0.0;	
    }
    
    // Attempts to add the item to the bin
    // If there is enough space, adds the item and returns true
    // If there is not enough space, returns false
    bool add(const double &item) {
      if (amount_of_space_used_ + item > 1.0) {
        return false;
      } else {
        amount_of_space_used_ += item;
        return true;
      }
    }
		
    void print(ostream& out) const {
      cout << amount_of_space_used_;
    }
};

#endif

ostream& operator<< (ostream& out, const Bin& rhs) {
	rhs.print(out);
	return out;
}


