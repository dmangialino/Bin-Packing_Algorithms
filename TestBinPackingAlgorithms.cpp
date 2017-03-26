#include "Bin.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int NextFitBinPacking(vector<double> &rn) {
  vector<Bin> bins;

  // Make the bins vector the same size as the vector containing the items
  // Allows for enough bins for the worst case: one item per bin
  bins.resize(rn.size());

  int pos = 0;
  bool check;
  for (unsigned int i = 0; i < rn.size(); ++i) {
    check = bins[pos].add(rn[i]);
    while (check == false) {
      ++pos;
      check = bins[pos].add(rn[i]);
    }
  }
	
  // Increment pos to make it equal to the number of bins used (to account for the 0th bin)
  ++pos;
  return pos;
}

int FirstFitBinPacking(vector<double> &rn) {
  vector<Bin> bins;
  bins.resize(rn.size());
  
  int max = 0;
  int pos = 0;
  bool check;
  for (unsigned int i = 0; i < rn.size(); ++i) {
    check = bins[pos].add(rn[i]);
    while (check == false) {
      ++pos;
      check = bins[pos].add(rn[i]);
    }

    if (pos > max)
      max = pos;
		
    pos = 0;
  }
	
  // Increment the maximum position to make it equal to the number of bins used (to account for the 0th bin)
  ++max;
  return max;
}

void GenerateRandomNumbers(vector<double> &rn, const int &N) {
  srand(time(0));
  for (int i = 0; i < N; ++i) {
    const double random_variable = ((double)rand() / (RAND_MAX));
    rn.push_back(random_variable);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <number_of_items>" << endl;
    return 0;
  }

  const int N = stoi(argv[1]);

  vector<double> random_numbers;
  GenerateRandomNumbers(random_numbers, N);

  const int number_of_bins_next_fit = NextFitBinPacking(random_numbers);
  const int number_of_bins_first_fit = FirstFitBinPacking(random_numbers);
	
  // Sort the random_numbers from largest to smallest
  sort(random_numbers.begin(), random_numbers.end(), greater<double>());
	
  const int number_of_bins_first_fit_decreasing = FirstFitBinPacking(random_numbers);
	
  cout << "Number of bins:" << endl;
  cout << "Next Fit: " << number_of_bins_next_fit << endl;
  cout << "First Fit: " << number_of_bins_first_fit << endl;
  cout << "First Fit Decreasing: " << number_of_bins_first_fit_decreasing << endl;	
	
  return 0;  	
}

