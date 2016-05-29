/*
** TaskList.hpp for in /home/salete_s/rendu/cpp_plazza
**
** Made by salete_s
** Login   <salete_s@epitech.net>
**
** Started on  Mon Apr 11 14:37:44 2016 salete_s
*/

#ifndef SAFEQUEUE_HPP__
#define SAFEQUEUE_HPP__
#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

namespace bbman
{
  template<typename T>
  class SafeQueue
  {
  public:

    SafeQueue() : q(), mutex(), condVar() {}

    ~SafeQueue() {}

    void push(T newElem)
    {
      std::lock_guard<std::mutex> lock(mutex);
      q.push(newElem);
      condVar.notify_one();
    }

    T pop()
    {
      std::unique_lock<std::mutex> lock(mutex);

      while (q.empty()) {
	condVar.wait(lock);
      }

      T val = q.front();
      q.pop();
      return val;
    }

    size_t size(void) const
    {
      return (this->q.size());
    }

  private:
    std::queue<T> q;
    mutable std::mutex mutex;
    std::condition_variable condVar;
  };
}

#endif // ifndef SAFEQUEUE_HPP__
