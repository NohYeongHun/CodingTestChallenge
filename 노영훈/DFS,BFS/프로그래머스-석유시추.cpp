/*
문제 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/250136
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
* land 매개 변수에서 1이 석유 0이 땅
* 시추관은 열 중에 하나를 꽂을 수 있음
* 열 중에 하나를 꽂으면 지나가면서 석유 덩어리 모든 값을 더한다.
* 1. 즉 열 하나에서 만나는 행열에 석유덩어리가 있다면
     해당 석유 덩어리를 만나고 1인 값을 모두 탐색해서 더한다.
  2. 열 탐색 한번에만 visited가 초기화되어야 함.
     => 500 * 500 * 500 시간 효율성 통과 못함.
     
* 
*/

vector<vector<int>> displayLand;
bool visited[501][501];
int  maxResult = -1;
int  curResult = 0;
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int row(-1);
int col(-1);
int  oilNumber = 1;
int  oilCheckMap[501][501]; // 각 행 열이 어떤 oilNumber인지.
int  oilNumberMap[500 * 500 + 1]; // oilNumber, 개수

void bfs(std::pair<int, int> pair)
{
    int result(1);
    std::queue<std::pair<int,int>> q;
    q.push(pair);
    
    while(!q.empty())
    {
        std::pair<int, int> cur = q.front();
        q.pop();
        
        int bfsRow = cur.first;
        int bfsCol = cur.second;
        
        for (int i = 0; i < 4; ++i)
        {
            // 다음 진행 방향.
            int nextRow = bfsRow + direction[i][0];
            int nextCol = bfsCol + direction[i][1];
            
            if (nextRow < 0 || nextRow >= row || nextCol < 0 || nextCol >= col)
            {
                continue;
            }
            else if (visited[nextRow][nextCol] != true && displayLand[nextRow][nextCol] == 1)
            {
                // 방문하지 않았고 석유 지역이라면
                visited[nextRow][nextCol] = true;
                // 행, 열이 어떤 오일 맵에 속하는지.
                oilCheckMap[nextRow][nextCol] = oilNumber;
                q.push(make_pair(nextRow, nextCol));
                result++;
            }
        }
    }
    
    oilNumberMap[oilNumber] = result;
    oilNumber++;
}


int solution(vector<vector<int>> land) {
    
    // 행 row, 열 col
    row = land.size();
    col = land[0].size();
    
    displayLand.swap(land);
    d
    // visited가 한번만 초기화되어야 함.
    fill(&visited[0][0], &visited[500][501], false);
    
    int curResult = 0;
    
    // 시추관 열 탐색.
    for (int c = 0; c < col; ++c)
    {
        for (int r = 0; r < row; ++r)
        {
            // 석유일 때만 탐사
            if (visited[r][c] != true && displayLand[r][c] == 1)
            {
                visited[r][c] = true;
                // 행, 열이 어떤 오일 넘버인지.
                oilCheckMap[r][c] = oilNumber;
                // 행, 열로 탐색.
                bfs(make_pair(r, c));  
            }
        }
    }
    
    for (int c = 0; c < col; ++c)
    {
        int colResult = 0;
        // 현재 오일맵 이 어떤것이 나왔는지 기록하기.
        set<int> oilSets;
        for (int r = 0; r < row; ++r)
        {
            if (displayLand[r][c] == 1)
            {
                oilSets.insert(oilCheckMap[r][c]);
            }
        }
        
        for (auto iter : oilSets)
        {
            colResult += oilNumberMap[iter];
        }
        maxResult = max(colResult, maxResult);
    }
    

    int answer = maxResult;
    return maxResult;
}
