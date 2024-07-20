#include "Chord.h"
#include <iostream>
#include "MIDIHelper.h"
#include "LyricController.h"
using namespace std;

namespace SunnyDays {
    int channelChord=2;
    void chordLevel(int level,int sleep,int repeat=2,int vel=70){
        repeat--;
        int down=8;
        if(level==1){
            //一级和弦 加右指
            playChord(hMidiOut, channelChord, M1, M3, M5, L1, vel);
            while(repeat--) {
                Sleep(sleep);
                playChord(hMidiOut, channelChord, M1, M3, M5, vel - down);
            }
        }else if(level==3){
            //三级和弦 加右指
            playChord(hMidiOut, channelChord, M3, M5, M7, L3, vel);
            while(repeat--) {
                Sleep(sleep);
                playChord(hMidiOut, channelChord, M3, M5, M7, vel - down);
            }
        }
        else if(level==4){
            //四级和弦 加右指
            playChord(hMidiOut, channelChord, L4, L6, M1, X4, vel);
            while(repeat--) {
                Sleep(sleep);
                playChord(hMidiOut, channelChord, L4, L6, M1, vel - down);
            }
        } else if(level ==5){
            //五级和弦 加右指
            playChord(hMidiOut, channelChord, L5, L7, L2, X5, vel);
            while(repeat--) {
                Sleep(sleep);
                playChord(hMidiOut, channelChord, L5, L7, L2, vel - down);
            }
        } else if(level==6){
            //六级和弦 加右指
            playChord(hMidiOut, channelChord, L6, M1, M3, X6, vel);
            while(repeat--) {
                Sleep(sleep);
                playChord(hMidiOut, channelChord, L6, M1, M3, vel - down);
            }
        }
    }
    void chord(){
        Sleep(63724);
        int sleep=740;
        int data[]={
                //刮风这天 我试过握着你手
                1,4,
                6,4,
                //但偏偏 雨渐渐
                4,2,
                5,2,
                //大到我看你不见
                1,4,
                //还有多久 我才能
                3,4,
                //↑ 在你身边
                6,4,
                //↓ 等到放晴的那天
                4,4,
                //↑ 也许我会比较好一点
                5,4,

                //从前从前 有个人
                1,4,
                //↑ 爱你很久
                6,4,
                //↓ 但偏偏
                4,2,
                //↑ 风渐渐
                5,2,
                //↓ 把距离吹得好远
                1,4,

                //好不容易 又能再
                3,4,
                //↑ 多爱一天
                6,4,
                //↓ 但故事的最后你
                4,4,
                //↑ 好像还是说了
                5,4,
                //↓ 拜拜
                1,4,
        };
        int count=sizeof(data)/sizeof(int);
        for(int i=0;i<count;i+=2){
            cout<<"chord "<<data[i]<<"  x"<<data[i+1]<<endl;
            chordLevel(data[i],sleep,data[i+1]);
            Sleep(sleep);
        }
        logTime("Chord State1 End");
        Sleep(27440);
        for(int i=18;i<count;i+=2){
            cout<<"chord "<<data[i]<<"  x"<<data[i+1]<<endl;
            chordLevel(data[i],sleep,data[i+1]);
            Sleep(sleep);
        }
        Sleep(1200);
        logTime("Chord State2 End");
    }
}