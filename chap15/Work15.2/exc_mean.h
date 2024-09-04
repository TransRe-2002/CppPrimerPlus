// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class bad_hmean : public std::logic_error
{
public:
    bad_hmean(const string what_arg = "HMean, Invalid argument ") : logic_error(what_arg) {}
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean(const string what_arg = "GMean, Invalid argument ") : logic_error(what_arg){}
};
