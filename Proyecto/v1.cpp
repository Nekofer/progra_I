#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

int map1[18][32]={{0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","0","0","0","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,1,1,"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,1,1,1,1,1,1,1,1,1,1,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","0"},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}};
				  
int main(){
	for(int i=0; i<=18; i++){
		for(int j=0; j<=37; j++){
			cout << map1[i][j];
		}
		cout << endl;
	}
}


