#include<iostream>
#include "perceptron.hpp"
#include<vector>

int  main()
{
  
  const int ROWS = 4;
  const int COLUMNS= 15;
  std::vector<int> vec;
  vec.resize(ROWS * COLUMNS);
  for (int ROWS = 0; ROWS < ROWS; ROWS++) {
    for (int col = 0; col < COLUMNS; col++) {
        vec[ROWS * COLUMNS + col] = ROWS * col;
    }
 }

 for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
 {
 	  std::cout << ' ' << *it;
      std::cout << '\n';

 }
  
  return 0;

}
