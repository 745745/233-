#include "head.h"
using namespace std;
int n;
int time_max[10000] = {0}; 
int time_min = 0x3f3f3f;
int a[1000];
int b[1000];
int F[1000][10000];
int tempa[1000] = {0};
int sum_a=0, sum_b=0;
void randput()
{
	srand(time(NULL));
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		a[i] = rand() % 20+1;
		time_max[i] = a[i]+time_max[i-1];
	}
	for (int i = 1; i <= n; ++i)
	{
		b[i] = rand() % 20 + 1;
	}
	cout << "A的工时分别为:";
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i] << " "  ;
	}
	cout << endl;
	cout << "B的工时分别为:";
	for (int i = 1; i <= n; ++i)
	{
		cout << b[i] << " " ;
	}
	cout << endl;
}
void solve()
{
	memset(F, 0, sizeof(F));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= time_max[i]; j++)
		{
			if (j >= a[i])
			{
				F[i][j] = min(F[i - 1][j - a[i]], F[i - 1][j] + b[i]);
			}
			else
			{
				F[i][j] = F[i - 1][j] + b[i];
			}
		}
	}

	/*int temp;
	for (int i = 0; i <= time_max[n - 1]; i++)
	{
		temp = max(F[n - 1][i], i);
		if (time_min > temp)
			time_min = temp;
	}
	cout << time_min << endl;
	time_min = 0x3f3f3f;
	temp = 0;

	for (int i = 0; i <= time_max[n]; i++)
	{
		temp = max(F[n][i], i);
		if (time_min > temp)
			time_min = temp;

	}*/
}
void shunxu()
{
	int temp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= time_max[i]; j++)
		{
			temp = max(F[i][j], j);
			if (time_min > temp)
				time_min = temp;
		}
		tempa[i] = time_min;
		time_min= 0x3f3f3f;
	}
	for (int i = 1; i <= n; i++)
	{
		/*if (tempa[i] - sum_b == b[i])
		{
			sum_b += b[i];
			cout << "第" << i << "项工件给B做\n";
		}
		else 
		{ 
			cout << "第" << i << "项工件给A做\n";
			sum_a += a[i];
		}*/
		cout <<"完成第"<<i<<"项工件所需的最少时间"<< tempa[i] << "\n";
	}


}
int main()
{
	randput();
	solve();
	shunxu();
	cout <<"总共需要的最短时间为"<< tempa[n];
	system("pause");
}

