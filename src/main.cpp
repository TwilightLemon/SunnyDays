#include <iostream>
#include <thread>
#include "../include/MIDIHelper.h"
#include "../include/Chord.h"
#include "../include/Accompany.h"
#include "../include/LyricController.h"
#include "../include/Voice.h"
#include "../include/BassDrum.h"

using namespace std;
using namespace SunnyDays;

HMIDIOUT hMidiOut;

int main() {
    system("chcp 65001");

    initDevice();
    //设置音量
    setVolume(channelChord,80);
    setVolume(channelMainLine,80);
    setVolume(channelVoice,120);
    setVolume(channelBassDrum,80);

    //设置乐器
    setInstrument(channelChord,ElectricPiano1);
    setInstrument(channelMainLine,ElectricPiano1);


    system("pause");
    beginLogger();


    thread t0(voice);
    thread t1(mainLine);
    thread t2(bassDrum);
    thread t3(chord);
    t0.join();
    t1.join();
    t2.join();
    t3.join();

    closeDevice();
    getchar();
    return 0;
}
