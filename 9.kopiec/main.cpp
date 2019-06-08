#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int load(int n, int array[])
{
	for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i<<" element: ";
        cin>>array[i];
        for(int j=0;j<i;j++)
        {
            if(array[j]==array[i])
            {
                cout<<"Enter  a different element\n";
                i--;
            }
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int mound(int a, int n, int array[])
{
    int max=a;
    int left=2*a+1;
    int right=2*a+2;
    int auxiliary;

    if(array[left]>array[max]&&left<n)
    {
        max=left;
    }

    if(array[right]>array[max]&&right<n)
    {
        max=right;
    }
    if(max!=a)
    {
        auxiliary=array[a];
        array[a]=array[max];
        array[max]=auxiliary;
        mound(max, n, array);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int heap_sort(int n, int array[])
{
    int i, auxiliary;
    for(i=n/2-1;i>=0;i--)
    {
        mound(i, n, array);
    }
    for(i=n-1;i>=0;i--)
    {
        auxiliary=array[0];
        array[0]=array[i];
        array[i]=auxiliary;

        mound(0, i, array);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int print(int n, int array[])
{
    int i;

    for(i=0;i<n;i++)
    {
        cout<<array[i]<<"\t";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n;
	cout<<"Enter the number of elements: ";
	cin>>n;
	if(n>0)
    {
    	int array[n];
		load(n, array);
		cout<<"\nBefore moving: ";
		print(n, array);
        heap_sort(n, array);
		cout<<"\nAfter  moving: ";
		print(n, array);
    }
    return 0;
}
