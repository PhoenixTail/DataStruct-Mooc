#include <iostream>
#include <fstream>
#include "PassWordLock.h"


using namespace std;


int main(){

	char cur[32];
	char obj[32];

	cin.getline(cur,32);

	cout<<cur<<endl;

	cin.getline(obj,32);

	cout<<obj<<endl;

    PassWordLock lock(obj,cur,strlen(obj));
	lock.Unlock();
    
	return 0;
}


