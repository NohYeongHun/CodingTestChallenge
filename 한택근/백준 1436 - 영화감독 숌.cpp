// https://www.acmicpc.net/problem/1436
// 백준 1436 영화감독 숌 (브루트포스(완전탐색) 실버5)

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int idx = 0;

	for (int i = 666; i <= 9999999; ++i)
	{
		if (to_string(i).find("666") != string::npos)
		{
			++idx;

			if (idx == n)
			{
				cout << i;
				break;
			}
		}
	}

	return 0;
}
