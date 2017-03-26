# Bin-packing_Algorithms
Tests next fit, first fit, and first fit decreasing bin-packing algorithms.

Bin.h implements the bin class. TestBinPackingAlgorithms.cpp creates a vector of user-defined length and fills it with random doubles between 0.0 and 1.0. It then uses this vector as items and tests the Next Fit, First Fit, and First Fit Decreasing bin packing algorithms and displays the number of bins each algorithm required for the vector input.

TESTING RESULTS:

First Fit Decreasing (FFD) is the best algorithm. After testing several times with different size inputs, it always requires the fewest bins. First Fit (FF) is better than Next Fit (NF), which required the most bins out of the three algorithms.

NUMBER OF BINS FOR 50 ITEMS:
    Trial 1	  Trial 2   Trial 3   Trial 4   Trial 5   AVERAGE
NF:	  33	      37	     37		      36  	   33 	     35.2
FF:	  30	      32	     32		      31	     28	       30.6
FFD:	28	      32	     32		      30	     26	       29.6

NUMBER OF BINS FOR 100 ITEMS:
    Trial 1	  Trial 2   Trial 3   Trial 4   Trial 5   AVERAGE
NF:   67	      70	     68		      65	      63	     66.6
FF:	  58	      60	     60		      51	      54	     56.6
FFD:	54	      57	     57		      48	      50	     53.2

NUMBER OF BINS FOR 500 ITEMS:
    Trial 1	  Trial 2   Trial 3   Trial 4   Trial 5   AVERAGE
NF:	  337	      359	     320	      317	      329	     332.4
FF:	  271	      290	     258	      253	      265	     267.4
FFD:	259	      280	     247	      240	      254	     256.0
