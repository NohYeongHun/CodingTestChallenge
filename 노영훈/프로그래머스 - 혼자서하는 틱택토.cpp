// 문제 풀이 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/160585
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 승리 체크
bool winCheck(vector<string>& board, char sign)
{      
    // 대각선 체크
    if ((board[0][0] == sign) &&(board[1][1] == sign) && (board[2][2] == sign))
    {
        return true;
    }
    
    if ((board[0][2] == sign) &&(board[1][1] == sign) && (board[2][0] == sign))
    {
        return true;
    }
    
    // 가로 줄
    for (int i = 0; i < board.size(); ++i)
    {
        if ((board[i][0] == sign) && (board[i][1] == sign) && (board[i][2] == sign))
        {
            return true;
        }
    }
    
    // 세로 줄
    for (int i = 0; i < board.size(); ++i)
    {
        if ((board[0][i] == sign) &&(board[1][i] == sign) && (board[2][i] == sign))
        {
            return true;
        }
    }
    
    
    
    return false;
    
}


// 답안.
int solution(vector<string> board) {
    int OCnt = 0;
    int XCnt = 0;
    bool OWin = false;
    bool XWin = false;
    
    // O, X 개수 세기
    for (auto val : board)
    {
        for (char c : val)
        {
            if (c == 'O')
            {
                OCnt++;
            }
            else if (c == 'X')
            {
                XCnt++;
            }
        }
    }

  // 승리 체크
    OWin = winCheck(board, 'O');
    XWin = winCheck(board, 'X');
    
    /*
    1. O가 승리했을 경우
    2. X가 승리했을 경우
    3. 승자가 없는 경우
    4. 둘다 승리했을 경우
    => 불가능
    */
    if (OWin == true && XWin == true)
    {
        return 0;
    }
    else if (OWin == true)
    {
        // 개수가 1개 차이인 경우에만 승리 조건이 정확함.
        if (OCnt == XCnt + 1)
        {
            return 1;
        }
        // 승리를 했는데도 진행하는 경우는 어떻게??..
    }
    else if(XWin == true)
    {
        // 개수가 같은 경우에만 승리가 가능.
        if (XCnt == OCnt)
        {
            return 1;
        }
    }
    else if(XWin == false && OWin == false)
    {
        // 승자가 없는 경우
        // O가 X보다 1개더 많을때.
        if (OCnt == XCnt + 1)
        {
            return 1;
        }
        // O와 X가 아예 존재하지 않을 때.
        else if (XCnt == 0 && OCnt == 0)
        {
            return 1;
        }
        // 놓는 도중일 때
        else if (XCnt == OCnt)
        {
            return 1;
        }
    }
    
    
    return 0;
}
