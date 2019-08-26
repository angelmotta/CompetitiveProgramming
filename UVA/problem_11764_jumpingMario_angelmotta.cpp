#include <iostream>

using namespace std;

int main() {
	int test_cases, case_num, high_jump, low_jump;
	case_num = 0;
	cin >> test_cases;
	while(test_cases--){
		int num_walls, prev_height, current_height;
		case_num++;
		high_jump = 0;
		low_jump = 0;
		cin >> num_walls;
		for(int i=0; i<num_walls; i++){
			if(i == 0){
				cin >> prev_height;
				continue;
			}
			cin >> current_height;
			if( current_height > prev_height){
				high_jump += 1;
				prev_height = current_height;
			}
			else if(prev_height > current_height){
				low_jump += 1;
				prev_height = current_height;
			}
			else{
				prev_height = current_height;
			}
		}
		cout << "Case " << case_num << ": " << high_jump << ' ' << low_jump << '\n';
	}
	return EXIT_SUCCESS;
}

