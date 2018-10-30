#include "TimeManager.hh"



TimeManager TimeManager::singleton;

TimeManager &TimeManager::GetInstance() {
    /*if(!singleton){
        singleton = new TimeManager;
    }*/
    return singleton;
}


TimeManager::TimeManager() {}
TimeManager::~TimeManager() {}

std::chrono::time_point<std::chrono::system_clock> start, firstUpdate, secondUpdate;

void TimeManager::Start() {
    start = std::chrono::system_clock::now();
}
void TimeManager::Update() {
    firstUpdate = secondUpdate;
    secondUpdate = std::chrono::system_clock::now();
}
unsigned int TimeManager::GetElapsedTime() const {
    unsigned int elapsed_seconds_update = std::chrono::duration_cast<std::chrono::milliseconds >
            (secondUpdate-firstUpdate).count();
    return elapsed_seconds_update;

}
unsigned int TimeManager::GetStartedTime() const {
    unsigned int elapsed_seconds_start = std::chrono::duration_cast<std::chrono::milliseconds >
            (start-secondUpdate).count();
    return elapsed_seconds_start;
}