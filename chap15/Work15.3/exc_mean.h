// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class unexpected_mean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    unexpected_mean(double a = 0, double b = 0, std::string s = "mean error")
        : v1(a), v2(b), logic_error(s) {}
    virtual void mesg() = 0;
};

class bad_hmean : public unexpected_mean
{
private:
public:
    bad_hmean(double a = 0, double b = 0, std::string s = "HMean ")
        : unexpected_mean(a, b, s) {}
    void mesg();
};

class bad_gmean : public unexpected_mean
{
public:
    bad_gmean(double a = 0, double b = 0, std::string s = "GMean ")
        : unexpected_mean(a, b, s) {}
    void mesg();
};

inline void unexpected_mean::mesg()
{
    cout << v1 << " " << v2 << endl;
}

inline void bad_hmean::mesg()
{
    std::cout << "bad_HMean() now!" << std::endl;
    std::cout << what() << "\n";
    std::cout << "HMean invalid arguments\n";
    unexpected_mean::mesg();
}

inline void bad_gmean::mesg()
{
    std::cout << "bad_GMean() now!" << std::endl;
    std::cout << what() << "\n";
    std::cout << "GMean invalid arguments\n";
    unexpected_mean::mesg();
}
