// https://www.acmicpc.net/problem/28278
// 스택 2 (스택 실버4)

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> st;

	int n;
	int input = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> input;

		switch (input)
		{
		case 1:
		{
			int x;
			cin >> x;

			st.push(x);
		}
		break;
		case 2:
		{
			if (st.empty())
				cout << -1 << '\n';
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		break;
		case 3:
		{
			cout << st.size() << '\n';
		}
		break;
		case 4:
		{
			cout << st.empty() << '\n';
		}
			break;
		case 5:
		{
			if (st.empty())
				cout << -1 << '\n';
			else
				cout << st.top() << '\n';
		}
			break;
		default:
			break;
		}
	}
}
