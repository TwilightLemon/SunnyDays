#include "BassDrum.h"
#include "MIDIHelper.h"
#include <iostream>
#include "LyricController.h"
using namespace std;

namespace SunnyDays {
    int channelBassDrum=9;

    void playDrum(int note, int velocity, int duration){
        PlayNote(hMidiOut, channelBassDrum, note, velocity);
        if(duration>0) {
            Sleep(duration);
            PlayNote(hMidiOut, channelBassDrum, note, 0);
        }
    }

    void bassDrum(){
        Sleep(11260);
        cout<<"Drum Bass Start!"<<endl;
        playDrum(SnareDrum,100,180);
        playDrum(SnareDrum,100,210);
        playDrum(BassDrum, 100, 210);
        playDrum(SnareDrum,100,190);
        playDrum(BassDrum, 100, 210);
        playDrum(SnareDrum,100,200);
        playDrum(SnareDrum,100,200);
        playDrum(OpenHiHat,100,-1);
        Sleep(200);
        int count=14;
        for(int i=0;i<count;i++){
            cout<<"drum "<<i<<endl;
            playDrum(BassDrum,50,200);
            playDrum(SnareDrum,80,210);
            playDrum(BassDrum,50,440);
            playDrum(BassDrum,50,400);
            playDrum(SnareDrum,80,380);
            playDrum(BassDrum,50,200);
            playDrum(SnareDrum,80,200);
            playDrum(BassDrum,50,200);
            playDrum(SnareDrum,80,200);
            playDrum(BassDrum,60,400);
            playDrum(SnareDrum,80,-1);
            Sleep(480);
        }
        logTime("drum stage1 end.");
        Sleep(57631);
        cout<<"drum stage2 start."<<endl;
        int count2=7;
        for(int i=0;i<count2;i++){
            cout<<"drum "<<i<<endl;
            playDrum(BassDrum,50,200);
            playDrum(SnareDrum,80,210);
            playDrum(BassDrum,50,440);
            playDrum(BassDrum,50,400);
            playDrum(SnareDrum,80,380);
            playDrum(BassDrum,50,200);
            playDrum(SnareDrum,80,200);
            playDrum(BassDrum,50,200);
            playDrum(SnareDrum,80,200);
            playDrum(BassDrum,60,400);
            playDrum(SnareDrum,80,-1);
            Sleep(480);
        }
        logTime("drum stage2 end.");
    }
}