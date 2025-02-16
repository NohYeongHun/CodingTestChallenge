//백준 11399번

/* pseudo code
    N(사람 수)
    P(자릿수별로 구분하여 저장한 인출 시간 배열)
    sum (합배열 P)

    for(i = 1 ~ N ){
        for(j = i-1 ~ 0 뒤에서 반복) {
            현재 범위에서 삽입 위치 찾기
        }
        for(j = i ~ 삽입위치+1 뒤에서 반복){
            삽입을 위해 데이터 한 칸씩 뒤로 밀기
        }
        데이터 삽입하기
    } 

    for(0 ~ N) 합배열 만들기
*/
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> P(1001, 0);
vector<int> sum(1001,0);

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
    }
}

void insetSort_Ascending()
{
    for (int i = 1; i < N; ++i)
    {
        int insertPoint = i;
        int insertValue = P[i];

        for (int j = i - 1; j >= 0; --j)
        {
            if (P[j] < P[i]) // 찾은 값이 현재 값보다 작으면
            {
                insertPoint = j + 1; // 들어갈 위치는 찾은 값 뒤에 위치해야하기 때문에 찾은 값 +1이 된다.
                break;
            }
            if (j == 0)
                insertPoint = 0;
        }

        for (int j = i; j > insertPoint; --j)
        {
            P[j] = P[j - 1];
        }

        P[insertPoint] = insertValue;
    }
}

void run()
{
    insetSort_Ascending();

    sum[0] = P[0];
    for (int i = 1; i < N; ++i)
    {
        sum[i] = sum[i - 1] + P[i];
    }

    int sumTime = 0;

    for (auto i : sum)
        sumTime += i;

    cout << sumTime;
}

int main()
{
    init();
    run();
}