#include "FPS.hh"

FPS FPS::singletonFPS;

FPS &FPS::GetInstanceFPS(){
	return singletonFPS;
}

FPS::FPS(){}
FPS::~FPS(){}

float FPS::getFps(TimeManager &instance){
	sleep(0.5);
	float fps = 1.f/ instance.GetElapsedTime();
	return fps;
}