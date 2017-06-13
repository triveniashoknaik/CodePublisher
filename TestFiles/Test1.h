#pragma once
// Test1.h

#include "../SemiExp/SemiExp.h"
#include "../Tokenizer/Tokenizer.h"

namespace Test
{
  class Test1
  {
  public:
    Test1();
    Test1(const Test1&) = delete;
    Test1& operator=(const Test1&) = default;
    ~Test1();
    void doThing1() { /* don't do anything */ }
  private:
    Scanner::SemiExp se;
  };
  struct test1
  {
	  int a;
	  float b;
	  double c;
  };
 // enum wind_directions_t 
 // { NO_WIND, NORTH_WIND, SOUTH_WIND, EAST_WIND, WEST_WIND };

 // enum fruits;
//  typedef kdk;
  
}
