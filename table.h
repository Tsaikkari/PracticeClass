#define MAX_NUM_COLUMNS 30
#define MAX_NUM_ROWS 30

using namespace std;
class Header {
public:
	string columns[MAX_NUM_COLUMNS];
	void show(int);
};

class Row {
public:
	string columns[MAX_NUM_COLUMNS];
	void show(int);
};


class Table {
public:
	Header h;
	Row row[MAX_NUM_ROWS];
	int NumberOfRows, NumberOfColumns;

	Table(int, int);
	void show();
	void SwapRows(int, int);
	void SortTable(int);
};

int ArrayFromString(string, string, string*);