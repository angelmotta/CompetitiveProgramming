//#include<bits/stdc++.h>
#include <iostream>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();                   OK
// Box(int,int,int);        OK
// Box(Box);                OK


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
private:
    int l;
    int b;
    int h;
public:
    // Default Constructor
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }
    // Custom Constructor
    Box(int length, int breadth, int height){
        l = length;
        b = breadth;
        h = height;
    }
    // Copy Constructor. Overwrite the default Copy Constructor doing the same
    Box(const Box &boxObj): l(boxObj.l), b(boxObj.b), h(boxObj.h){}

    //Member functions
    int getLength() const{return l;}
    int getBreadth() const{return b;}
    int getHeight() const{return h;}
    long long int CalculateVolume(){
    	long long int result;
		//std::cout << l << "*" << b << "*" << h << std::endl;
    	result = l*b;
    	result = result * h;
    	//std::cout << result << std::endl;
    	return result;
    }

    // Overload operator '<'
    friend bool operator<(const Box &A, const Box &B);

    //Overload operator '<<'
    friend std::ostream& operator<<(std::ostream& out, const Box &b1);
};

bool operator<(const Box &A, const Box &B){     //implementation Overlaod
    if(A.l < B.l){
        return true;
    }
    else if((A.b < B.b) && (A.l == B.l)){
        return true;
    }
    else if((A.h < B.h) && (A.b == B.b && A.l == B.l)){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, const Box &b1){ // implementation Overload
    out << b1.l << " " << b1.b << " " << b1.h;
    return out;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}