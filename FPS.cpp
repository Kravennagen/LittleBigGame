#include "FPS.hh"

FPS FPS::singletonFPS;

FPS &FPS::GetInstanceFPS(){
	return singletonFPS;
}

FPS::FPS(){
	
}
FPS::~FPS(){}

float FPS::getFps(TimeManager &instance){
	fps = 0;
	
	float elipsed = instance.GetElapsedTime();
	if(elipsed > 1){
		fps = CLOCKS_PER_SEC / elipsed;
	}
	return fps;
}