// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>

using namespace std;

struct Review
{
    string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review> sp1,const shared_ptr<Review> sp2)
{
    return sp1->title < sp2->title;
}

bool worthThan(const shared_ptr<Review> sp1,const shared_ptr<Review> sp2)
{
    return sp1->rating < sp2->rating;
}

bool cheaperThan(const shared_ptr<Review> sp1,const shared_ptr<Review> sp2)
{
    return sp1->price < sp2->price;
}

bool FillReview(shared_ptr<Review> sp)
{
    cout << "Enter the title of book(quit to quit): ";
    getline(cin,sp->title);
    if(sp->title == "quit") return false;
    else{
        cout << "Enter the rating: ";
        cin >> sp->rating;
        cin.get();
        cout << "Enter the price: ";
        cin >> sp->price;
        cin.get();
        return true;
    }
}

void showReview(shared_ptr<Review> sp)
{
    cout << sp->title << endl;
    cout << "   " << "Rating: " << sp->rating << endl;
    cout << "   " << "Price: " << sp->price << endl;
}

int main()
{
    vector<shared_ptr<Review> > books;
    shared_ptr<Review> temp(new Review);
    while(FillReview(temp)) {
        books.push_back(temp);
        temp = shared_ptr<Review>(new Review);
    }

    vector<shared_ptr<Review> > rating(books);
    vector<shared_ptr<Review> > price(books);
    vector<shared_ptr<Review> > alpha(books);
    sort(alpha.begin(),alpha.end());
    sort(rating.begin(),rating.end(),worthThan);
    sort(price.begin(),price.end(),cheaperThan);

    cout << "Choose show order:\n"
         << "1: initial order   2: rating up    3: rating down\n"
         << "4: price up        5: price down   6: alpha order\n"
         << "else: quit\n";
    int choice;
    while(cin >> choice){
        if(choice > 6 || choice < 1) break;
        if(choice == 1) for_each(books.begin(),books.end(),showReview);
        if(choice == 2) for_each(rating.begin(),rating.end(),showReview);
        if(choice == 3) for_each(rating.rbegin(),rating.rend(),showReview);
        if(choice == 4) for_each(price.begin(),price.end(),showReview);
        if(choice == 5) for_each(price.rbegin(),price.rend(),showReview);
        if(choice == 6) for_each(alpha.begin(),alpha.end(),showReview);
        cout << "Choose show order:\n"
        << "1: initial order   2: rating up    3: rating down\n"
        << "4: price up        5: price down   6: alpha order\n"
        << "else: quit\n";
    }

    return 0;
}
