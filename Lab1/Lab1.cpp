#include <iostream>

#define F 2

void print(unsigned int* arr, unsigned int N, int k)

{

for (int i=0;i<N;i++)

{

if (arr[i]==0)

std::cout<<".. ";

else if (arr[i] == k)

std::cout<<"["<<arr[i]<<"] ";

else

std::cout<<arr[i]<<" ";

}

}

int main()

{

using std::cout;

using std::endl;

using std::cin;

int n,k;

cout<<"Enter N: ";cin>>n;

unsigned int outarr[5+2*F];

unsigned char step;

do{

step = 0;

cout<<endl<<"Enter K: ";cin>>k;

cout<<endl;

if ((k<=0)||(k>n)) break;

if (k>1+F) outarr[step++] = 1;//cout<<"1 ";

if (k>2+F) outarr[step++] = 0;//cout<<".. ";

for (int i=k-F;i<=k;i++)

if (i>0)

outarr[step++] = i;

for (int i=k+1;i<=k+F;i++)

if (i<=n)

outarr[step++] = i;

if (k<n-F-1) outarr[step++] = 0;//cout<<".. ";

if (k<n-F) outarr[step++] = n;//cout<<n;

print(outarr,step,k);

} while (1);

cout<<"GAME OVER ";

return 0;

}
