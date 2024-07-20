#include "MIDIHelper.h"

void initDevice(){
    midiOutOpen(&hMidiOut, 0, 0, 0, CALLBACK_NULL);
}

void closeDevice(){
    midiOutClose(hMidiOut);
}

void setInstrument(int channel,int instrument){
    if (channel > 15 || instrument > 127) return;
    DWORD message = 0xC0 | channel | (instrument << 8);
    midiOutShortMsg(hMidiOut, message);
}

void setVolume(int channel,int volume){
    if (channel > 15 || volume > 127) return;
    DWORD message = 0xB0 | channel | (7 << 8) | (volume << 16);
    midiOutShortMsg(hMidiOut, message);
}

void PlayNote(HMIDIOUT handle, UINT channel, UINT note, UINT velocity) {
    if (channel > 15 || note > 127 || velocity > 127) return;
    DWORD message = 0x90 | channel | (note << 8) | (velocity << 16);
    midiOutShortMsg(handle, message);
}

void playChord(HMIDIOUT handle, UINT channel, UINT note1, UINT note2, UINT note3, UINT note4, UINT velocity){
    if (channel > 15 || note1 > 127 || note2 > 127 || note3 > 127 || note4 > 127 || velocity > 127) return;
    DWORD message1 = 0x90 | channel | (note1 << 8) | (velocity << 16);
    DWORD message2 = 0x90 | channel | (note2 << 8) | (velocity << 16);
    DWORD message3 = 0x90 | channel | (note3 << 8) | (velocity << 16);
    DWORD message4 = 0x90 | channel | (note4 << 8) | (velocity << 16);
    midiOutShortMsg(handle, message1);
    midiOutShortMsg(handle, message2);
    midiOutShortMsg(handle, message3);
    midiOutShortMsg(handle, message4);
}

void playChord(HMIDIOUT handle, UINT channel, UINT note1, UINT note2, UINT note3, UINT velocity) {
    if (channel > 15 || note1 > 127 || note2 > 127 || note3 > 127 || velocity > 127) return;
    DWORD message1 = 0x90 | channel | (note1 << 8) | (velocity << 16);
    DWORD message2 = 0x90 | channel | (note2 << 8) | (velocity << 16);
    DWORD message3 = 0x90 | channel | (note3 << 8) | (velocity << 16);
    midiOutShortMsg(handle, message1);
    midiOutShortMsg(handle, message2);
    midiOutShortMsg(handle, message3);
}
