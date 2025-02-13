#pragma once

#include <windows.h>
#pragma comment(lib,"winmm.lib")

enum Scale
{
    X1 = 36, X2 = 38, X3 = 40, X4 = 41, X5 = 43, X6 = 45, X7 = 47,
    L1 = 48, L2 = 50, L3 = 52, L4 = 53, L5 = 55, L6 = 57, L7 = 59,
    M1 = 60, M2 = 62, M3 = 64, M4 = 65, M5 = 67, M6 = 69, M7 = 71,
    H1 = 72, H2 = 74, H3 = 76, H4 = 77, H5 = 79, H6 = 81, H7 = 83,
    LOW_SPEED = 500, MIDDLE_SPEED = 400, HIGH_SPEED = 300,
    _ = 0XFF
};
enum Drum{
    BassDrum = 36, SnareDrum = 38, ClosedHiHat = 42, OpenHiHat = 46
};
enum Instrument{
    AcousticGrandPiano = 0, BrightAcousticPiano = 1,
    ElectricGrandPiano = 2, HonkyTonkPiano = 3,
    ElectricPiano1 = 4, ElectricPiano2 = 5
};

//全局 MIDI 输出设备句柄
extern HMIDIOUT hMidiOut;

void initDevice();
void closeDevice();
void setInstrument(int channel, int instrument);
void setVolume(int channel, int volume);

void PlayNote(HMIDIOUT handle, UINT channel, UINT note, UINT velocity);

void playChord(HMIDIOUT handle, UINT channel, UINT note1, UINT note2, UINT note3, UINT note4, UINT velocity);

void playChord(HMIDIOUT handle, UINT channel, UINT note1, UINT note2, UINT note3, UINT velocity);
