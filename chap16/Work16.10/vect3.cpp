// vect3.cpp -- using STL function
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Review {
    std::string title;
    int rating;
    int price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const shared_ptr<Review> & rr);

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool expenThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
int main() 
{
    using namespace std;
    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
    {
        shared_ptr<Review> pd(new Review(temp));
        books.push_back(pd);
    }
    if (books.size() > 0)
    {
        cout << "Choose the way to sort: "
             << "r: rate, s: rate r, p: price, d: price r, q: quit\n";
        char choice;
        while (cin >> choice && choice != 'q')
        {
            switch (choice)
            {
                case 'r': sort(books.begin(), books.end(), worseThan);
                break;
                case 's': sort(books.rbegin(), books.rend(), worseThan);
                break;
                case 'p': sort(books.begin(), books.end(), expenThan);
                break;
                case 'd': sort(books.rbegin(), books.rend(), expenThan);
                break;
                default: sort(books.begin(), books.end());
                break;
            }
            for_each(books.begin(), books.end(), ShowReview);
            cout << "Please choose the way to sort: "
                 << "r: rate, s: rate r, p: price, d: price r, q: quit\n";
        }
    }
    return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(cin, rr.title);
    if (rr.title == "quit" || rr.title == "")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!cin)
        return false;
    cout << "Enter book price: ";
    cin >> rr.price;
    if (!cin)
        return false;
    // get rid of rest of input line
    while (cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else if (r1->rating == r2->rating && r1->price < r2->price)
        return true;
    else
        return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool expenThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}
