#ifndef SUNNYDAYS_LYRICCONTROLLER_H
#define SUNNYDAYS_LYRICCONTROLLER_H
#include <iostream>
#include <chrono>
#include <string>

namespace SunnyDays {
    void beginLogger();
    void logTime(const std::string &msg);

    void NextLyric();
}

#endif
