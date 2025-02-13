#include "../../include/LyricController.h"
#include <queue>

namespace SunnyDays {
    void NextLyric(){
        static std::queue<std::string> lyricQueue=std::queue<std::string>({
            "故事的小黄花",
            "从出生那年就飘着",
            "童年的荡秋千",
            "随记忆一直晃到现在",

            "Re so so si do si la So la",
            "si si si si la si la so",
            "吹着前奏望着天空",
            "我想起花瓣试着掉落",

            "为你翘课的那一天",
            "花落的那一天",
            "教室的那一间",
            "我怎么看不见",
            "消失的下雨天",
            "我好想再淋一遍",
            "没想到失去的勇气我还留着",
            "好想再问一遍",
            "你会等待还是离开",

            "刮风这天 我试过握着你手",
            "但偏偏 雨渐渐",
            "大到我看你不见",
            "还有多久 我才能在你身边",
            "等到放晴的那天也许我会比较好一点",

            "从前从前 有个人爱你很久",
            "偏偏风渐渐 把距离吹得好远",
            "好不容易 又能再多爱一天",
            "但故事的最后你好像还是说了 拜拜",

            "为你翘课的那一天",
            "花落的那一天",
            "教室的那一间",
            "我怎么看不见",
            "消失的下雨天",
            "我好想再淋一遍",
            "没想到失去的勇气我还留着",
            "好想再问一遍",
            "你会等待还是离开",

            "从前从前 有个人爱你很久",
            "偏偏风渐渐 把距离吹得好远",
            "好不容易 又能再多爱一天",
            "但故事的最后你好像还是说了 拜拜"
        });
        std::string lyric=lyricQueue.front();
        std::cout<<lyric<<std::endl;
        lyricQueue.pop();
    }

    std::chrono::time_point<std::chrono::system_clock> startTime;
    void beginLogger(){
        startTime=std::chrono::system_clock::now();
    }
    void logTime(const std::string &msg){
        auto now=std::chrono::system_clock::now();
        auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(now-startTime);
        std::cout<<msg<<" Time: "<<duration.count()<<std::endl;
    }
}