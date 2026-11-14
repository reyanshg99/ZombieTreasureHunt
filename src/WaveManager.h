#pragma once

class WaveManager {
public:
    enum class Event { None, LevelCompleted, NextLevelStarted };
    void reset();
    void registerKill();
    Event update(float dt, int livingZombies);
    int level() const { return level_; }
    int target() const { return 10 + 5 * (level_ - 1); }
    int killsThisLevel() const { return kills_; }
    int totalKills() const { return totalKills_; }
    float levelElapsed() const { return elapsed_; }
    float breakElapsed() const { return breakElapsed_; }
    bool complete() const { return complete_; }
    static int zombieCountForLevel(int level);
    static float zombieHealthForLevel(int level);
    static float zombieSpeedForLevel(int level);
    static float zombieDamageForLevel(int level);
private:
    int level_=1, kills_=0, totalKills_=0;
    float elapsed_=0.f, breakElapsed_=0.f;
    bool complete_=false;
};
