#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	char soundfile[] = "G:\si.wav";
	cout<< PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);
	system("pause");
	return 0;
}
