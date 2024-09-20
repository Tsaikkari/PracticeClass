#include <iostream>
#include <sstream>

#define MAX_NUM_COLUMNS 30
#define MAX_NUM_ROWS 30


class Header {
public:
	std::string columns[MAX_NUM_COLUMNS];
};

class Row {
public:
	int columns[MAX_NUM_COLUMNS];
	std::string s = "str";
};

class Table {
public:
	Header header;
	Row row[MAX_NUM_ROWS];
	int Num_of_rows, Num_of_columns;
	Table(int num_of_rows, int num_of_columns) {
		// initialisation of header
		for (int c = 0; c < num_of_columns; c++) {
			header.columns[c] = "column" + std::to_string(c);
		}
		// default values
		for (int r = 0; r < num_of_rows; r++) {
			for (int c = 0; c < num_of_columns; c++) {
				row[r].columns[c] = c + r;
			}
		}
		Num_of_rows = num_of_rows;
		Num_of_columns = num_of_columns;
	}

	void ShowTable() {
		std::cout << std::endl;
		// header
		for (int c = 0; c < Num_of_columns; c++) {
			std::cout << "\t" << header.columns[c];
		}
		std::cout << std::endl;
		for (int r = 0; r < Num_of_rows; r++) {

			for (int c = 0; c < Num_of_columns; c++) {
				std::cout << "\t" << row[r].columns[c];
			}
			std::cout << std::endl;
		}
	}

	void SwapRows(int first_row_index, int second_row_index) {
		int temp[4];
		for (int c = 0; c < Num_of_columns; c++) {
			temp[c] = row[first_row_index].columns[c];
			row[first_row_index].columns[c] = row[second_row_index].columns[c];
			row[second_row_index].columns[c] = temp[c];
		}
	}

	void SortTable(int index_of_column_to_sort) {
		int col_temp[4];
		for (int r = 0; r < Num_of_rows; r++) {
			col_temp[r] = row[r].columns[index_of_column_to_sort];
		}

		int max;
		int i_max = 0;
		for (int i = 0; i < Num_of_rows; i++) {
			max = col_temp[i];
			i_max = i;
			for (int j = i; j < Num_of_rows; j++) {
				if (col_temp[j] > max) {
					max = col_temp[j];
					i_max = j;
				}
				SwapRows(i, i_max);
			}
		}
	}
};

int main()
{
	int num_of_rows = 4;
	int num_of_columns = 3;

	Table T(num_of_rows, num_of_columns);
    std::cout << "table original" << std::endl;
	T.ShowTable();

    T.SwapRows(1, 2);
    std::cout << "T.SwapRows(1,2)" << std::endl;
	T.ShowTable();

	int index_of_column_to_sort = 0;

	T.SortTable(index_of_column_to_sort);
	std::cout << "T.SortTable" << index_of_column_to_sort << std::endl;
	T.ShowTable();

	system("pause>0");
}

