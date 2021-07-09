#include"arrays.h"

int swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
	return 1;
}

int insertion_sort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	return 1;
}

int shell_sort(int arr[],int n)
{
	int gap,i,j,temp;
	for(gap=n/2;gap>=1;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			temp=arr[i];
			j=i-gap;
			while(j>=0 && arr[j]>temp)
			{
				arr[j+gap]=arr[j];
				j=j-gap;
			}
			arr[j+gap]=temp;
		}
	}
	return 1;
}

int merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while((i<n1) && (j<n2))
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
	return;
}
int merge_sort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);
		
		merge(arr,l,m,r);
	}
	return;
}

int partition_quicksort(myarray *p,int l, int r)
{
	int pivot=p->array[r];
	int i=l-1;int j;
	for(j=l;j<r;j++)
	{
		if(p->array[j]<pivot)
		{
			i++;
			swap(&p->array[i],&p->array[j]);
		}
	}
	swap(&p->array[i+1],&p->array[r]);
	return(i+1);
}
int quick_sort(myarray *p,int l, int r)
{
	if(l<r)
	{
		int pi= partition_quicksort(p,l,r);
		
		quick_sort(p,l,pi-1);
		quick_sort(p,pi+1,r);
	}
	return 1;
}

int print_array(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 1;
}

int main()
{
	myarray d;
	creating(&d);
	
	printf("ARRAY ELEMENTS BEFORE SORTING:\n");
	display(&d);
	
	quick_sort(&d,0,d.size);
	
	printf("\nARRAY ELEMENTS AFTER QUICK SORT:\n");
	display(&d);
	
	return 1;
}
