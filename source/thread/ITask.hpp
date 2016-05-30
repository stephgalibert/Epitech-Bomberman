/*
** ITask.hpp for  in /home/salete_s/rendu/cpp_plazza
**
** Made by salete_s
** Login   <salete_s@epitech.net>
**
** Started on  Mon Apr 11 17:05:25 2016 salete_s
*/

#ifndef ITASK__HPP__
#define ITASK__HPP__

namespace bbman
{
  class ITask
  {
  public:
    virtual ~ITask(void) {}
    virtual void start(void) = 0;
    virtual void stop(void) = 0;
    virtual void setFinished(bool v) = 0;
    virtual bool isFinished(void) const = 0;
    virtual bool isRunning(void) const = 0;
  };
}

#endif // ifndef ITASK__HPP__
