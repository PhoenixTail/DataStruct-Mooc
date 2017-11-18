#ifndef _PASSWORDLOCK_H_
#define _PASSWORDLOCK_H_

class PassWordLock {
public:
    PassWordLock(char *pswd, char *lockstatus, int len);

	bool Unlock();

private: 
	int len;
    char CurInput[32];
	char Password[32];
	char Initial[32];

	bool Open() ;
	bool ChkEqual(int idx);

	void ChangeAt(int idx);

	void ChangeOver(int idx) ;

	bool Unkock_next(int &times);
};

#endif