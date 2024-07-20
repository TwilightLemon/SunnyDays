#include "MainLine.h"
#include <iostream>
#include "MIDIHelper.h"
using namespace std;

namespace SunnyDays {
    int channelMainLine=0;
    void playPiano(int note, int velocity){
        PlayNote(hMidiOut, channelMainLine, note, velocity);
    }
    void mainLine(){
        int sleep=420;
        int data[] ={
                L6,M1,M5,M1,L4,-1,L5,0,L6,-2,M5,M1,L1,L5,M5,M1,L1,M5,L7,M5
        };

        int count=9;
        for(int i=0;i<count;i++) {
            cout<<"accompany "<<i<<endl;
            for (auto i: data) {
                if (i == -1) {
                    sleep = 220;
                    continue;
                }
                if (i == 0) {
                    sleep = 180;
                    continue;
                }
                if (i == -2) {
                    sleep = 420;
                    continue;
                }
                playPiano(i, 80);
                Sleep(sleep);
            }
        }
        cout<<"accompany stage1 end."<<endl;
        Sleep(56500);
        cout<<"accompany stage2 start."<<endl;
        count=3;
        for(int i=0;i<count;i++) {
            cout<<"accompany "<<i<<endl;
            for (auto i: data) {
                if (i == -1) {
                    sleep = 220;
                    continue;
                }
                if (i == 0) {
                    sleep = 180;
                    continue;
                }
                if (i == -2) {
                    sleep = 420;
                    continue;
                }
                playPiano(i, 80);
                Sleep(sleep);
            }
        }

    }
}