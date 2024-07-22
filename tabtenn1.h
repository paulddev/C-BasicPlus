#ifndef TABTENN1_H_
#define TABTENN1_H_ 
#include <string>
using std::string;

class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;

public:
	TableTennisPlayer(const string& fn = "none", const string& ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return hasTable; }
	void ResetTable(bool v) { hasTable = v; }
};

// 파생 클래스
// 두 클래스는 서로 연계되어 있기 때문에, 클래서 선언들을 함께 묶어두는 것이 더 체계적이라고 한다.
class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int rating;

public:
	RatedPlayer(unsigned int r = 0, const string& fn = "none", const string& ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
	unsigned int Rating() { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
};

#endif
