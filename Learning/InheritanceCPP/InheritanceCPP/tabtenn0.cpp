#include "tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn,
	const string &ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {}

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

// Boi vi derived class khong the truy cap truc tiep vao private
// variable duoc cho nen la trong constructor cuar derived class se
// khai bao luon bien cua baseclass thong qua constructor cua base class
RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
	const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
	: TableTennisPlayer(tp), rating(r)
{
}