cmake_minimum_required(VERSION 3.28)
project(SunnyDays)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(SunnyDays src/main.cpp
        src/helper/MIDIHelper.cpp
        src/instrument/Chord.cpp
        src/helper/LyricController.cpp
        src/instrument/Accompany.cpp
        src/instrument/Voice.cpp
        src/instrument/BassDrum.cpp)
target_link_libraries(SunnyDays winmm)