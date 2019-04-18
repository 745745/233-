#include"head.h"
using namespace std;
void FCFS(int *A,int n)
{
	int *p = new int[n];
	memset(p, 0, sizeof(int)*(n + 1));
	
	for (int i = 2; i <= n; i++)
		p[i] = p[i - 1] + A[i];
	int tot = 0;
	for (int i = 1; i <= n; i++)
		tot += p[i];
	cout << "FCFS中Cj之和为" << tot<<endl;

}

void SJF(int *A, int n)
{
	sort(A, A + n);
	int *p = new int[n];
	memset(p, 0, sizeof(int)*(n+1));
	
	p[1] = A[1];
	for (int i = 2; i <= n; i++)
		p[i] = p[i-1]+A[i];
	int tot = 0;
	for (int i = 1; i <= n; i++)
		tot += p[i];
	cout << "SJF中Cj之和为" << tot<<endl;


}


void FCFS2(int *A, int *B, int n)
{
	int *p = new int[n];
	int *x = new int[n];
	x[1] = A[1];
	p[1] = A[1] - B[1];
	for (int i = 2; i <= n; i++)
	{
		x[i] = x[i - 1] + A[i];
		p[i] = x[i] - B[i];
	}
	sort(p, p + n);
	cout << endl;
	cout << "FCFS中L_max为" << p[n];
}



void EDD(int *A,int *B, int n)
{
	pair<int,int>*p=new pair<int, int>[n];
	for (int i = 1; i <= n; i++)
	{
		p[i].first = B[i];
		p[i].second = i;
	}
	sort(p, p + n+1);  //把工期排好序
	int *q = new int[n];
	int *x = new int[n];
	x[1] = A[p[1].second];
	q[1] = p[1].first -A[p[1].second];
	for (int i = 2; i <= n; i++)
	{
		x[i] = x[i - 1] + A[p[i].second];
		q[i] = x[i] - p[i].first;
	}
	sort(q, q + n);
	cout << endl;
	cout << "EDD中L_max为" << q[n]<<endl;
	
}

void test1()
{
	int n;
	cin >> n;
	int *A = new int[n];
	srand(time(0));
	for (int i = 1; i <= n; i++)
		A[i] = rand() % 100;
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
	FCFS(A, n);
	SJF(A, n);
	system("pause");



}


void test2()
{
	int n;
	cin >> n;
	int *A = new int[n];
	int *B = new int[n];
	memset(B, 0, sizeof(int)*(n + 1));
	srand(time(0));
	for (int i = 1; i <= n; i++)
	{
		A[i] = rand() % 100;
		for (; B[i] < A[i];)
			B[i] = rand() % 100;
	}
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << B[i] << " ";
	cout << endl;
	FCFS2(A,B, n);
	EDD(A,B, n);
	system("pause");






}
