#include <iostream>
#include <thread>
#include "MIDIHelper.h"
#include "Chord.h"
#include "MainLine.h"
#include "LyricController.h"
#include "Voice.h"
#include "BassDrum.h"

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
