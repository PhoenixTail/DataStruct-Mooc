#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

class PassWordLock {
public:
    PassWordLock(char *pswd, char *lockstatus, int len);

	bool Unlock();

private: 
	int len;
    char CurInput[32];
	char Password[32];
	char Initial[32];

	bool ChkEqual(int idx);

	void ChangeAt(int idx);

	void ChangeOver(int idx) ;

	bool Unkock_next(int &times);
};



PassWordLock::PassWordLock(char *pswd, char *lockstatus, int len) {
	this->len = len;
    strcpy(Password,pswd);
	strcpy(CurInput,lockstatus);
	strcpy(Initial,lockstatus);
}

bool PassWordLock::Unlock() {
	int min = INT_MAX;
	for(int i = 0; i <= 1; i++) {
		int times = 0;
		strcpy(CurInput,Initial);
		if(i == 0) {
			ChangeAt(0);
			times++;
		}
		if(Unkock_next(times)) {
            if(times < min)
				min  = times;
		}
	}

	if(min == INT_MAX) {
		cout<<"impossible"<<endl;
	    return false;
	}

	cout<<min<<endl;
	return true;
}

bool PassWordLock::ChkEqual(int idx) {
    return (CurInput[idx]==Password[idx]);
}

void PassWordLock::ChangeAt(int idx) {
	if(idx <= 0) {
		ChangeOver(0);
		ChangeOver(1);
	}
	else if(idx >= len-1) {
		ChangeOver(len-1);
		ChangeOver(len-2);
	}
	else {
		ChangeOver(idx+1);
		ChangeOver(idx-1);
		ChangeOver(idx);
	}
}

void PassWordLock::ChangeOver(int idx) {
    if(CurInput[idx] == '0')
		CurInput[idx] = '1';
	else
		CurInput[idx] = '0';
}


bool PassWordLock::Unkock_next(int &times){
	for(int i = 1; i < len; i++) {
		if(! ChkEqual(i-1)) {
			ChangeAt(i);
			times++;
		} 
	}
	return(ChkEqual(len-1));
}


int main(){

	char cur[32];
	char obj[32];

	cin.getline(cur,32);
	cin.getline(obj,32);

    PassWordLock lock(obj,cur,strlen(obj));
	lock.Unlock();
    
	return 0;
}