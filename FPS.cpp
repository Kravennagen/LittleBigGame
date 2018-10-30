#include "FPS.hh"

FPS FPS::singletonFPS;

FPS &FPS::GetInstanceFPS(){
	return singletonFPS;
}

FPS::FPS(){}
FPS::~FPS(){}

float FPS::getFps(TimeManager &instance){
	float fps = 1.f/ instance.GetElapsedTime();
	std::cout << fps << std::endl;
	return fps;
}