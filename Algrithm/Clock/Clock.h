class Clock {
private:
	int position;
public:
	Clock(int position);
	void Tick();
	bool IsZero();
}

Clock::Clock(int position) {
	this->position = position;
}

void Clock::Tick() {
	position++;
	position = position%4;
}

bool Clock::IsZero() {
	return (positon == 0);
}

/*********************************/
Class ClockMatrix {
private:
	Clock clock[9] = {Clock(0),Clock(0),Clock(0),Clock(0),Clock(0),Clock(0),Clock(0),Clock(0),Clock(0)};
public:
    ClockMatrix(char status[3][3]);
}

ClockMatrix::ClockMatrix(char status[3][3]) {
	int i,j;

	for(i = 0; i < 3; i++) {
        for(j = 0; j < 
	}
}