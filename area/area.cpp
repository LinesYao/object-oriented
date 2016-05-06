#include<iostream>
#include"cal_area.h"
using namespace std;

int main() 
{
	double radius;
	while(cin >> radius) 
	{
		cout << cal_area(radius) << endl;
	}
	return 0;
}

