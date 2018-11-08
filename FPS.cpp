#include "FPS.hh"

FPS FPS::singletonFPS;

FPS &FPS::GetInstanceFPS(){
	return singletonFPS;
}

FPS::FPS(){
	fps = 0;
}
FPS::~FPS(){}

float FPS::getFps(TimeManager &instance){
	float elipsed = instance.GetElapsedTime();
	if(elipsed > 1){
		fps = CLOCKS_PER_SEC / elipsed;
	}
	return fps;
}