/*
** ThreadPool.cpp for in /home/salete_s/rendu/cpp_plazza/core
**
** Made by salete_s
** Login   <salete_s@epitech.net>
**
** Started on  Mon Apr 18 13:03:12 2016 salete_s
*/

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int newNbThread)
{
  this->_nbThread  = newNbThread;
  this->_taskQueue = NULL;
}

ThreadPool::~ThreadPool()
{
  delete this->_taskQueue;
  // delete this->_threads;
}

void ThreadPool::pool()
{
  ITask *newOrder = NULL;

  while (true) {
    newOrder = this->_taskQueue->pop();
    newOrder->start();
    delete newOrder;
  }
}

void ThreadPool::addTask(ITask *t)
{
  this->_taskQueue->push(t);
}

void ThreadPool::init()
{
  this->_threads   = new std::thread[this->_nbThread];
  this->_taskQueue = new SafeQueue<ITask *>;

  for (int i = 0; i < this->_nbThread; i++) {
    this->_threads[i] = std::thread(&ThreadPool::pool, this);
  }

  for (int i = 0; i < this->_nbThread; i++) {
    this->_threads[i].detach();
  }
}
