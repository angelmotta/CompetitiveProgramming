#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

struct Point{
	int x, y;
};

struct Robot{
	int x, y;
	char orientation;
	int protection = 0;
	int next_is_invalid = 0;
};

struct Lost_Points{
	int x, y;
	char orientation;
};

map<string, char> direction {{"ER", 'S'}, {"EL", 'N'}, {"SR", 'W'}, {"SL", 'E'}, {"WR", 'N'}, {"WL", 'S'}, {"NR", 'E'}, {"NL", 'W'}};

void update_position(char &orientation, int &x, int &y){
	if(orientation == 'N') y++;
	else if(orientation == 'E') x++;
	else if(orientation == 'S') y--;
	else if(orientation == 'W') x--;
}

void update_orientation(char &orientation, char giro){
	//printf("Instruction inserted: %c \n", giro);
	string search_instruction;
	string instruction(1,giro);
	string orient(1,orientation);
	search_instruction = orient + instruction;
	orientation = direction[search_instruction];
}

bool exist_lost_point(int x, int y, vector<Lost_Points> &scent_list){
	for(const auto element : scent_list){
		if( x == element.x && y == element.y){
			//printf("ya existe lost_point en lista \n");
			return true;
		}
	}
	return false;
}

void is_invalid_movement(Robot &robot, const Point limit_world, vector<Lost_Points> &scent_list){
	//printf("Validate_movement function: \n");
	Lost_Points last_point;
	if(robot.orientation == 'N'){
		if(robot.y < limit_world.y){
			robot.next_is_invalid = 0;
		}
		else{
			//printf("activa robot.next_is_invalid \n");
			robot.next_is_invalid = 1;
			if(!exist_lost_point(robot.x, robot.y, scent_list)){
				last_point.x = robot.x;
				last_point.y = robot.y;
				scent_list.push_back(last_point);
			}
		}
	}
	else if(robot.orientation == 'E'){
		if(robot.x < limit_world.x){
			robot.next_is_invalid = 0;
		}
		else{
			robot.next_is_invalid = 1;
			if(!exist_lost_point(robot.x, robot.y, scent_list)){
				last_point.x = robot.x;
				last_point.y = robot.y;
				scent_list.push_back(last_point);
			}
		}
	}
	else if(robot.orientation == 'S'){
		if(robot.y > 0){
			robot.next_is_invalid = 0;
		}
		else{
			robot.next_is_invalid = 1;
			if(!exist_lost_point(robot.x, robot.y, scent_list)){
				last_point.x = robot.x;
				last_point.y = robot.y;
				scent_list.push_back(last_point);
			}
		}	
	}
	else if(robot.orientation == 'W'){
		if(robot.x > 0){
			robot.next_is_invalid = 0;
		}
		else{
			robot.next_is_invalid = 1;
			if(!exist_lost_point(robot.x, robot.y, scent_list)){
				last_point.x = robot.x;
				last_point.y = robot.y;
				scent_list.push_back(last_point);
			}
		}
	}
}

void check_position(Robot &robot, vector<Lost_Points> &scent_list){
	for(const auto element : scent_list){
		if( robot.x == element.x && robot.y == element.y){
			//printf("activa robot.protection \n");
			robot.protection = 1;
			return;
		}
	}
	robot.protection = 0;
}

void print_scent_list(vector<Lost_Points> &scent_list){
	printf("Scent_List: \n");
	for(auto element : scent_list){
		printf("%d %d \n", element.x, element.y);
	}
}

int main(){
	Point limit_world;
	Robot robot;
	char instruction[100];
	vector<Lost_Points> scent_list;
	int lost;
	scanf("%d %d", &limit_world.x, &limit_world.y);		// take Limits of the wolrd
	while(scanf("%d %d %c", &robot.x, &robot.y, &robot.orientation) != EOF){			// Receive Robot position
		//printf("x: %d, y: %d, orientation: %c \n", robot.x, robot.y, robot.orientation);
		scanf("%s", instruction);
		for(int i=0; instruction[i] != '\0'; ++i){
			lost = 0;
			if(instruction[i] == 'L' || instruction[i] == 'R'){
				update_orientation(robot.orientation, instruction[i]);
			}
			if(instruction[i] == 'F'){
				check_position(robot, scent_list);
				is_invalid_movement(robot, limit_world, scent_list);
				//printf("robot.next_is_invalid: %d robot.protection: %d \n", robot.next_is_invalid, robot.protection);
				if(robot.next_is_invalid && robot.protection){
					//printf("Ignore F \n");
					continue;
				}
				else if(robot.next_is_invalid && !(robot.protection)){
					printf("%d %d %c LOST\n", robot.x, robot.y, robot.orientation);
					lost = 1;
					break;
				}
				else{
					update_position(robot.orientation, robot.x, robot.y);
				}		
			}
		}	
		if(!(lost)){
			printf("%d %d %c\n", robot.x, robot.y, robot.orientation);
		}
		//print_scent_list(scent_list);
	}
	return 0;
}


