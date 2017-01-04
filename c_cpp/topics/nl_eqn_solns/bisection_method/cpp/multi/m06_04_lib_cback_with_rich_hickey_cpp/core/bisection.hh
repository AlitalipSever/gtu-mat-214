#ifndef BISECTION_HH_
#define BISECTION_HH_

#include<list>
#include<iostream>
#include<cstdio>
#include<cmath>
#include <functional>

#include "internals/bisection_internals.hh"
#include "utilities/utilities_general.hh"
#include "utilities/callback_rich_hickey.hh"

namespace nummethods
{

// typedef std::function<double(double)> CallbackFunction;
typedef CBFunctor1wRet<double, double> CallbackFunction;

class BisectionMethod
{
  
private:
  
  CallbackFunction callback_;
  
//   double (*callback_)(double,void*);
//   void    *userdata_;
  
  double   limLeft_;
  double   limRight_;
  double   abstol_;
  double   reltol_;
  double   ftol_;
  double   maxIter_;
  
private:
  
  int                 flag_;
  std::list<SolnItem> llist_;
  
public:
  
  BisectionMethod
  (
    CallbackFunction callback ,
//     double (*callback)(double,void*) ,
//     void    *userdata ,
    double   limLeft ,
    double   limRight ,
    double   abstol   = 1.0e-30 ,
    double   reltol   = 1.0e-3 ,
    double   ftol     = 1.0e-4 ,
    double   maxIter  = 50
  )
  :
  callback_ (callback) ,
//   userdata_ (userdata) ,
  limLeft_  (limLeft) ,
  limRight_ (limRight) ,
  abstol_   (abstol) ,
  reltol_   (reltol) ,
  ftol_     (ftol) ,
  maxIter_  (maxIter)
  {
    llist_.clear();
  }
  
  ~BisectionMethod
  ()
  {
    llist_.clear();
  }
  
  void
  compute
  ();
  
  int
  getFlag
  ()
  const
  {
    return flag_;
  }
  
  const std::list<SolnItem> &
  getList
  ()
  const
  {
    return llist_;
  }
};
  
} // nummethods

#endif
