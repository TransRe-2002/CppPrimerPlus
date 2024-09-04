//error4.cpp  using exception classes
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_mean.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try     // start of try block
        {
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << hmean(x, y) << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }       // end of try block
        catch (unexpected_mean& bg)      // start of catch block
        {
            if (typeid (bg) == typeid (bad_hmean))
            {
                bad_hmean *ph = dynamic_cast<bad_hmean*> (&bg);
                ph->mesg();
            }
            else if (typeid (bg) == typeid (bad_gmean))
            {
                bad_gmean *pg = dynamic_cast<bad_gmean*> (&bg);
                pg->mesg();
            }
            cout << "Try again.\n";
            continue;
        }
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}