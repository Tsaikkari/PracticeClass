#include <iostream>
#include <sstream>

#include "table.h"
using namespace std;

void Header::show(int NumberOfColumns) {
	for (int c = 0;c < NumberOfColumns;c++) {
		cout << "\t" << columns[c];
	}
}

int ArrayFromString(string S, string DEL, string* ArrayOfStrings) {
	int pos_start = 0;	int pos_end = 0;
	int n = 0;
	while (pos_end != -1) {
		pos_end = S.find(DEL, pos_start);
		if (pos_end != -1) {
			ArrayOfStrings[n] = S.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + 1;
			n++;
		}
	}
	int NumberOfElements = n;
	return NumberOfElements;
}

void Row::show(int NumberOfColumns) {
	for (int c = 0;c < NumberOfColumns;c++) {
		cout << "\t" << columns[c];
	}
	cout << endl;
}

Table::Table(int ZahlDerRows, int ZahlDerColumns) {
	NumberOfRows = ZahlDerRows;
	NumberOfColumns = ZahlDerColumns;
	// initialisation header: 	
	for (int c = 0;c < NumberOfColumns;c++) {
		h.columns[c] = "c" + to_string(c);
	}
	// default values
	for (int r = 0; r < NumberOfRows; r++) {
		for (int c = 0; c < NumberOfColumns; c++) {
			row[r].columns[c] = to_string(r) + to_string(c);
		}
	}
}

void Table::show() {
	cout << endl;
	//print header		
	for (int c = 0; c < NumberOfColumns ;c++) {
		cout << "\t" << h.columns[c];
	}
	cout << endl << endl;
	for (int r = 0; r < NumberOfRows; r++) {
		row[r].show(NumberOfColumns);
	}
}

void Table::SwapRows(int NumOfRow1, int NumOfRow2) {
	string Temp[4];
	for (int c = 0; c < NumberOfColumns; c++) {
		Temp[c] = row[NumOfRow1].columns[c];
		row[NumOfRow1].columns[c] = row[NumOfRow2].columns[c];
		row[NumOfRow2].columns[c] = Temp[c];
	}
}

void Table::SortTable(int NumberOfColumnToSort) {
	string Col_Temp[4];
	for (int r = 0; r < NumberOfRows; r++) {
		Col_Temp[r] = row[r].columns[NumberOfColumnToSort];
	}
	string max;
	int i_max = 0;

	for (int i = 0; i < NumberOfRows; i++) {
		max = Col_Temp[i];
		i_max = i;
		for (int j = i; j < NumberOfRows; j++) {
			if (Col_Temp[j] > max) {
				max = Col_Temp[j];
				i_max = j;
			}
			SwapRows(i, i_max);
		}
	}
}

