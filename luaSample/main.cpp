#include "Binding.hpp"
#include <unistd.h>




int main()
{
  bbman::Binding script;
  Data AIdata;
  AIdata.pos = 0;
  accessData(&AIdata);
  while (1)
  {
    script.init("script.lua");
    std::cout << "In C++ -> position : " << AIdata.pos << std::endl;
    script.runAI();
    AIdata.pos++;
    sleep(1);
  }
}
