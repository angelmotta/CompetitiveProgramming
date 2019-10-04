#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <chrono>
#include <iostream>
using namespace std;

struct formula{
	int row = 0, col = 0;
	char form[100000];
	vector<pair<int,int>> operandos;

	formula(int _row, int _col, char *_form){
		//printf("This form: %s\n", _form);
		row = _row;
		col = _col;
		//form = _form;
		strcpy(form,_form);
		read_linea_form();
	}

	void read_linea_form(){
		string cel_name = "";
		for(int i=1;i<100000; ++i){
			if(form[i] == '\0'){
				//printf("***Get index %s\n",cel_name.c_str());
				get_operando_index(cel_name);
				break;
			}
			if(form[i] == '+'){
				get_operando_index(cel_name);
				cel_name="";
				continue;
			}
			cel_name += form[i];
		}
		/*printf("%s\n","-- Sumandos --" );
		for(auto sumando : operandos){
			printf("%d %d \n", sumando.first, sumando.second);
		}*/
		//printf("%s\n",cel_name.c_str());
	}
	
	void get_operando_index(const string celda){
		int x = 0, y = -1;
		int exponent = 0;
		for(int i=0; i<celda.size(); ++i){
			if(int(celda[i]) >= 65){
				exponent++;
			}
			else break;
		}
		x = stoi(celda.substr(exponent)) - 1;
		int index_celda = 0;
		for(int i=exponent-1; i>=0; --i){
			y += (int(celda[index_celda]) - 64) * pow(26,i);
			index_celda++;
		}
		operandos.push_back(make_pair(x,y));
	}
};

struct spreadhsheet{
	int rows = 0, cols = 0;
	int **arr_spread = nullptr;
	bool **arr_check_formulas = nullptr;
	vector<formula*> formulas_vec;

	spreadhsheet(int _rows, int _cols){
		rows = _rows;
		cols = _cols;
		arr_spread = new int *[rows];
		arr_check_formulas = new bool *[rows];
		//printf("%s\n", "Constructor called");
		for(int i=0; i<rows; ++i){
			arr_spread[i] = new int[cols];
			arr_check_formulas[i] = new bool[cols];
		}
		//printf("%s\n", "Constructor called end");
	}

	void input_values(){
		//printf("%s\n","INPUT VALUES" );
		int value = 0;
		char str_value[100000];
		size_t n;
		for(int i=0; i<rows; ++i){
			for(int j=0; j<cols; ++j){
				scanf("%99999s", str_value);
				if(str_value[0] == '='){
					//formula f1(i,j,str_value);
					formula* f1 = new formula(i,j,str_value);
					formulas_vec.push_back(f1);
					//printf("read Formula: %s \n",formulas_vec[j].form);
					arr_spread[i][j] = 0;
					arr_check_formulas[i][j] = 1;
				}
				else{
					arr_spread[i][j] = atoi(str_value);
					arr_check_formulas[i][j] = 0;	
				}
				//printf("Ingresaste: %s\n",str_value);
				//arr_spread[i][j] = value;
			}
		}
		//printf("xxxxread Formula: %s \n",formulas_vec[1].form);
	}

	/*void print_formulas(){
		printf("%s\n", "-- Print Vector of formulas --");
		for(auto f1 : formulas_vec){
			printf("Formula: %s - En Fila: %d - En columna: %d \n", f1.form, f1.row, f1.col);
		}
	}*/

	void execute_formula(){
		//printf("%s\n", "-- Start Execution cell formulas --");
		while(formulas_vec.size() > 0){
			//printf("formulas_vec size: %lu\n",formulas_vec.size());
			for(int i=0; i<formulas_vec.size(); ++i){		// Toma Cada formula (Struct) del Vector
				//printf("%d ",i);
				
				int execute_form = 1;
				// Analiza si puede ejecutar
				//printf("%s\n", "-- Start check execution cell formulas --");
				for(auto sumando : formulas_vec[i]->operandos){
					if(arr_check_formulas[sumando.first][sumando.second]){
						execute_form = 0;	
						break;
					}
				}
				//printf("%s\n", "-- End check execution cell formulas --");
				//Ejecuta
				if(execute_form){
					//printf("%s\n", "-- Start sum cell formulas --");
					int result = 0;
					for(int j = 0; j < formulas_vec[i]->operandos.size(); ++j){		// itera cada operando de la formula
						result += arr_spread[formulas_vec[i]->operandos[j].first][formulas_vec[i]->operandos[j].second];
					}
					arr_spread[formulas_vec[i]->row][formulas_vec[i]->col] = result;
					arr_check_formulas[formulas_vec[i]->row][formulas_vec[i]->col] = 0;
					//DELETE
					formulas_vec.erase(formulas_vec.begin() + i);
					//printf("%s\n", "-- End sum cell formulas --");
				}
			}
			//break;
		}
	}

	void print_spreadsheet(){
		//printf("%s\n", "-- Print spreadhsheet --");
		for(int i=0; i<rows; ++i){
			for(int j=0; j<cols; ++j){
				if(j == cols-1){
					printf("%d", arr_spread[i][j]);	
				}
				else printf("%d ", arr_spread[i][j]);
			}
			printf("\n");
		}
	}

	~spreadhsheet(){
		//printf("%s\n", "Destructor called");
		for(int i=0; i<rows; ++i){
			delete[] arr_spread[i];
		}
		delete[] arr_spread;
	}

};

int main(){
	int num_spreadsheet = 0;
	int cols = 0 , rows = 0;
	scanf("%d",&num_spreadsheet);
	for(int i=0; i<num_spreadsheet; ++i){
		scanf("%d %d",&cols, &rows);
		spreadhsheet sp(rows, cols);
		sp.input_values();
		//sp.print_formulas();
		sp.execute_formula();
		sp.print_spreadsheet();
	}
	return 0;
}