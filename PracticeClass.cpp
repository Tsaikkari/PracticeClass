#include <iostream>
#include <sstream>

#define BREAK "b"
#define DEFAULT "d"
#define CREATE_TABLE "t"
#define EDIT_ROW "r"
#define NEW_ROW "n"
#define SHOW_TABLE "s"
#define SWAP_ROWS "sw"
#define SORT_TABLE "so"

#include "table.h"
int main() {
	cout << endl;  
	string DEL = ";";

	int NumberOfColumns = 3;
	int NumberOfRows = 4;
	string header_console_in;
	int edited_row_number = 1;
	int edited_col_number = 1;
	string edited_row_number_s;
	string edited_col_number_s;
	string value;

	while (1) { //1
		cout << "Create a table: give a header in csv file form (h0;h1;h2;h3)  or \"" 
			<< DEFAULT << "\" for default or \""
			<< BREAK << "\" to break" 
			<< endl;

		getline(cin, header_console_in);

		if (header_console_in == BREAK) break;
		if (header_console_in == DEFAULT) header_console_in = "h0;h1;h2;";

		string Header[MAX_NUM_COLUMNS];
		NumberOfColumns = ArrayFromString(header_console_in, DEL, Header);
		Table T(NumberOfRows, NumberOfColumns);
		NumberOfColumns = ArrayFromString(header_console_in, DEL, T.h.columns);
	
		cout << "Original table:" << endl;
		T.show();
		while (1) { //2 edit row
			cout << "\ngive the number of the row to edit  or \"" 
				<< NEW_ROW << "\" to create a new row,  or \""
				<< SHOW_TABLE << "\" to show the table or \""
				<< SWAP_ROWS << "\" to swap rows or \""
				<< SORT_TABLE << "\" to sort the table or \""
				<< BREAK << "\" to break" << endl;

			getline(cin, edited_row_number_s);
			if (edited_row_number_s == BREAK) break;
			else if (edited_row_number_s == SORT_TABLE) {
				cout << "\nnumber of the column to sort the table :" << "or \"" 
					<< BREAK << "\" to break" 
					<< endl;
				string NumberOfColumnToSort_s;
				getline(cin, NumberOfColumnToSort_s);
				if (NumberOfColumnToSort_s == BREAK) break;
				T.SortTable(stoi(NumberOfColumnToSort_s));
				T.show();
				cout << "\ngive the number of the row to edit  or \"" 
					<< NEW_ROW << "\" to create a new row,  or \""
					<< SHOW_TABLE << "\" to show the table or \"" 
					<< SWAP_ROWS << "\" to swap rows or \""
					<< BREAK << "\" to break" << endl;
				getline(cin, edited_row_number_s);
			}
			else if (edited_row_number_s == SWAP_ROWS) {
				cout << "\ngive numbers of the rows to swap (first number, enter, then the second number) :" << "or \"" 
					<< BREAK << "\" to break" 
					<< endl;
				string row1, row2;
				getline(cin, row1);
				if (row1 == BREAK) break;
				getline(cin, row2);
				cout << "stoi(r1)=" << stoi(row1) << endl;
				T.SwapRows(stoi(row1), stoi(row2));
				cout << "\ngive number of the row_to_edit or \""
					<< NEW_ROW << "\" to create a new row,  or \""
					<< SHOW_TABLE << "\" to show the table or \""
					<< SWAP_ROWS << "\" to swap rows or \""
					<< BREAK << "\" to break" << endl;
				getline(cin, edited_row_number_s);
			}
			else if (edited_row_number_s == NEW_ROW) {
				cout << "new row" << endl;
				T.NumberOfRows++;

				edited_row_number = T.NumberOfRows - 1;

			}
			else if (edited_row_number_s == SHOW_TABLE) {
				T.show();
				cout << "\give number of row_to_edit  or \"" 
					<< NEW_ROW << "\" to create new row,  or \""
					<< SHOW_TABLE << "\" to show table or \"" 
					<< BREAK << "\" to break" << endl;
				getline(cin, edited_row_number_s);
			}
			else edited_row_number = stoi(edited_row_number_s); {

				T.row[edited_row_number].show(T.NumberOfRows);
			}

			while (1) { 
				cout << "give column number for edit: or \"" 
					<< BREAK << "\" to break" 
					<< endl;
				getline(cin, edited_col_number_s);
				if (edited_col_number_s == BREAK) break;
				edited_col_number = stoi(edited_col_number_s);
				cout << "change the old value " << T.row[edited_row_number].columns[edited_col_number] << " for\n";
				getline(cin, value);
				T.row[edited_row_number].columns[edited_col_number] = value;
				T.row[edited_row_number].show(T.NumberOfColumns);
			}
		}
		cout << "after editing: T=" << endl;
		T.show();

	}

	return 0;
}




