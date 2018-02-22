#ifndef CLASSIFY_H 
#define CLASSIFY_H
#include<iostream> 

class Classify {
public: 
std::string classifyPoints(double resultA, double resultB, double resultC)
  {
    std::string finalResult; 
    if (resultA>resultB and resultA>resultC){
    finalResult="Class A";  
   }
   else if (resultB>resultA and resultB>resultC)
   {
    finalResult="Class B"; 
   }

   else if (resultC>resultA and resultC>resultB)
   {
    finalResult="Class C";  
   }

   else {
    finalResult="Ambigious"; 
   }

   return finalResult; 
    
  }; 

}; 

#endif

