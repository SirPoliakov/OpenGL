#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer {

public:
	Timer();
	virtual ~Timer();

	unsigned int computeDeltaTime();


	void delayTime();

	static double getTimeSinceStart() { return timeSinceStart; }

private:
	const static int FPS = 60;
	const static int frameDelay = 1000 / FPS;
	const unsigned int MAX_DT = 50;

	unsigned int frameStart;

	unsigned int lastFrame;

	unsigned int frameTime;

	static double timeSinceStart;

};

#endif