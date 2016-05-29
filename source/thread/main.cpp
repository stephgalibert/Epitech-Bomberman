/*
** main.cpp for in cpp_plazza
**
** Made by sebperso
** Login   <salete_s@epitech.net>
**
** Started on  Fri May 27 10:51:48 2016 sebperso
// Last update Sat May 28 10:11:17 2016 stephane galibert
*/

#include <unistd.h>
#include "ThreadPool.hpp"
#define NB_TASK 100
#define NB_THREAD 8

namespace bbman
{
  class Action : public ITask
  {
  public:

    Action(int newId)
    {
      id = newId;
    }

    ~Action() {}

    virtual void start()
    {
      int delay = rand() % 4;

      std::cout << "Thread start working on action " << id <<
	" delay is " << delay << " sec" << std::endl;
      sleep(delay);
    }

    virtual void stop()
    {
      running = false;
    }

    int id;
    bool running;
  };
}

#include <iostream>
#include <thread>

// int main()
// {
//   bbman::ThreadPool tpool(NB_THREAD);

//   srand(time(NULL));
//   tpool.init();

//   for (uint64_t i = 0; i < NB_TASK; i++) {
//     std::cout << "Core add action " << i << std::endl;
//     tpool.addTask(new bbman::Action(i));
//   }
//   int i = 0;
//   while (++i < 10000);
//   return 0;
// }
