//백준 11004번

/* pseudo code
    n (데이터 개수)  -> (범위 : 1<= n <= 5,000,000)
    k (k번째 수)
    vecData (데이터 배열)

    퀵정렬(start,end)
    {
        pivot = 피벗 구하기 함수(start, end)
        if( k == pivot ) 종료
        else if ( k < pivot ) 퀵 정렬(시작인덱스 , pivot -1) // k가 작으니 왼쪽 그룹 정렬
        else                  퀵 정렬(pivot , 마지막 인덱스) // k가 크니 오른쪽 그룹 정렬
    }

    피벗 구하기 함수(start, end)
    {
        mid (중앙값) 
        swap (mid, end)  // 중앙값을 마지막 위치와 스왑 (i,j 이동 편하게 할려고)
        i (시작 위치) , j(마지막 위치)
        while( i <= j )
        {
            while( i < pivot) i++
            while( j > pivot) j++
            swap(i,j)
        }
    }

*/

#include <iostream>
#include <vector>

using namespace std;

void init();
int partition(int start, int end);
void quickSort(int start, int end);
void swap(int a, int b);

int n, k;
vector<int> vecData(5'000'000, 0);

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    --k;

    for (int i = 0; i < n; ++i)
        cin >> vecData[i];
}

void quickSort(int start, int end)
{
    int pivot = partition(start, end);
    if( pivot == k) return;
    else if( pivot > k ) quickSort(start, pivot - 1);
    else quickSort(pivot + 1,end);
}

void swap(int a, int b){
    int temp = vecData[a];
    vecData[a] = vecData[b];
    vecData[b] = temp;
}

int partition(int start, int end)
{
    if (start + 1 == end)
    {
        if (vecData[start] > vecData[end])
            swap(start, end);
        return end;
    }

    int mid = (start+end)/2;
    swap(mid,start);
    int pivot = vecData[start];

    int i(start + 1), j(end);

    while (i <= j)
    {
        while (j >= start + 1 && vecData[j] > pivot) j--;
        while (i <= end && vecData[i] < pivot) i++;
        if (i < j) swap(i++, j--);
        else break;
    }

    vecData[start] = vecData[j];
    vecData[j] = pivot;
    return j;
}

int main()
{
    init();
    quickSort(0, n - 1);
    cout<<vecData[k];
}