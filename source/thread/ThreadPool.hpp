/*
** ThreadPool.hpp for in /home/salete_s/rendu/cpp_plazza
**
** Made by salete_s
** Login   <salete_s@epitech.net>
**
** Started on  Mon Apr 11 14:30:36 2016 salete_s
*/

#ifndef THREADPOOL__HPP__
#define THREADPOOL__HPP__

#include <thread>
#include "SafeQueue.hpp"
#include "ITask.hpp"

namespace bbman
{
  class ThreadPool
  {
  public:
    ThreadPool(int newNbThread);
    ~ThreadPool();

    void pool();
    void addTask(ITask *t);

    void init();
  private:
    std::thread *_threads;
    int _nbThread;
    SafeQueue<ITask *> *_taskQueue;
  };
}

#endif // ifndef THREADPOOL__HPP__
