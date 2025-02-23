#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// 2 2 2 2
//f(n) = 3f(n-2) *  2f(n-4) * 2f(n-6) * 2f(n-8)  * 2f(n-10),,, + 2   

int solution(int n) {
    int answer = 0;
    long long arr[5001]= {0,}; 
    arr[0] = 1;                          
    arr[2] = 3;
    arr[4] = 11;
     arr[6] =41;

    for(int i = 8 ; i<5001 ; i+=2){
        arr[i]= (4*arr[i-2]%1'000'000'007 - arr[i-4]%1'000'000'007+1'000'000'007)%1'000'000'007;
        }

    return arr[n];
}

