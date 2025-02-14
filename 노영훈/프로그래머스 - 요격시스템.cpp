// 문제 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/181188
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
A 나라 폭격 시 x축에 평행한 직선 형태 모양
(s, e) 형태로 폭격

B 나라 관통 미사일은 x 좌표에 걸쳐있는 모든 폭격 미사일을 관통하여 요격가능 
다만 s, e 좌표에 발사하는 요격 미사일로는 요격 불가.(끝점은 요격이 안됨.)

모든 미사일을 요격하기 위해 필요한 요격 미사일 수의 최솟값 리턴 
*/

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    
    int s(0), e(0);
    int curE(0), curS(0);
    for (auto target : targets)
    {
        // 현재 시작점, 현재 끝점.
        curS = target[0];
        curE = target[1];
        
        // 현재 시작점이 기존 끝점보다 같거나 크다면? => 기존 미사일로 요격이 불가능.
        // 요격 미사일 개수를 늘립니다.
        if (curS >= e)
        {
            answer++;
            s = curS;
            e = curE;
        }
    }
    
    return answer;
}
