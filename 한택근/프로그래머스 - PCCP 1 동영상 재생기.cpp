// 프로그래머스 - PCCP 1 동영상 재생기
// https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ClockToInt(string _clock)
{
    int result = 0;
    int m1, m2, s1, s2;

    m1 = (int)_clock[0] - 48;
    m2 = (int)_clock[1] - 48;
    s1 = (int)_clock[3] - 48;
    s2 = (int)_clock[4] - 48;

    result = (m1 * 10 + m2) * 60 + (s1 * 10 + s2);

    return result;
}

string TimeToClock(int _time)
{
    int mm = _time / 60;
    int ss = _time % 60;

    int m1 = mm / 10;
    int m2 = mm % 10;
    int s1 = ss / 10;
    int s2 = ss % 10;

    string result;

    result += (char)(m1 + 48);
    result += (char)(m2 + 48);
    result += ':';
    result += (char)(s1 + 48);
    result += (char)(s2 + 48);

    return result;
}

struct Video
{
    Video(string _len, string _pos, string _start, string _end)
    {
        fullTime = ClockToInt(_len);
        crtTime = ClockToInt(_pos);
        opStart = ClockToInt(_start);
        opEnd = ClockToInt(_end);
        
        CheckOpening();
    }

    void Process_Command(string _command)
    {
        if (_command == "prev")
        {
            crtTime -= 10;

            if (crtTime < 0)
                crtTime = 0;
        }
        else if (_command == "next")
        {
            crtTime += 10;

            if (crtTime > fullTime)
                crtTime = fullTime;
        }

        CheckOpening();
    }

    void CheckOpening()
    {
        if (crtTime >= opStart && crtTime <= opEnd)
            crtTime = opEnd;
    }

    int fullTime, crtTime;
    int opStart, opEnd;
};

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    string answer = "";

    Video myVideo = Video(video_len, pos, op_start, op_end);

    for (int i = 0; i < commands.size(); ++i)
        myVideo.Process_Command(commands[i]);

    answer = TimeToClock(myVideo.crtTime);
    
    return answer;
}

int main()
{
    vector<string> commands = { "next" };
    cout << solution("07:22", "04:05", "00:15", "04:07", commands);

    return 0;
}
