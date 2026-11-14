#include "WaveManager.h"
#include <algorithm>

void WaveManager::reset(){level_=1;kills_=totalKills_=0;elapsed_=breakElapsed_=0.f;complete_=false;}
void WaveManager::registerKill(){if(complete_||kills_>=target())return;++kills_;++totalKills_;}
WaveManager::Event WaveManager::update(float dt,int living){
    if(!complete_){elapsed_+=dt;if(kills_>=target()&&living==0){complete_=true;breakElapsed_=0.f;return Event::LevelCompleted;}return Event::None;}
    breakElapsed_+=dt;if(breakElapsed_<5.f)return Event::None;
    ++level_;kills_=0;elapsed_=breakElapsed_=0.f;complete_=false;return Event::NextLevelStarted;
}
int WaveManager::zombieCountForLevel(int level){return 10+5*std::max(0,level-1);}
float WaveManager::zombieHealthForLevel(int level){return 100.f+12.f*std::max(0,level-1);}
float WaveManager::zombieSpeedForLevel(int level){return std::min(3.4f,1.15f+.055f*std::max(0,level-1));}
float WaveManager::zombieDamageForLevel(int level){return 8.f+std::min(14.f,1.f*std::max(0,level-1));}
