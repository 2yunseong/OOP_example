#include <stdio.h>
#include <stdlib.h> 

int linear_search(const int a[], int n, int k)
{
	int i ;
	
	for(i=0; i<n; i++)
	{
		if(a[i]==k)
			return i ;
	}
	
	return -1 ;
}

void bubble_sort(int aa[], int n)
{
	int i,j;
	int temp;
	for(i=0; i<n-1; i++)
		{
			for(j=0; j<n-1-i; j++)
				{
					if(aa[j] > aa[j+1])
						{
							temp = aa[j];
							aa[j] = aa[j+1];
							aa[j+1] = temp ; 
						}
				}
		}
}
int binary_search(const int b[], int n, int k)
{
	int pl = 0;
	int pr = n-1;
	int pc ;
	
	do{
		pc = (pl+pr)/2;
		if(b[pc]==k)
			return pc;
		else if(b[pc] < k)
			pl = pc+1;
		else
			pr = pc-1 ;
	} while(pl <=pr);
	return -1 ;
}

int main ()
{
	int i,num;
	int *line_array;
	int *bin_array; 
	int key;
	int linear_answer, binary_answer ;
	printf("����� ���� �Է�:");
	scanf("%d", &num);
	
	line_array = calloc(num, sizeof(int));
	bin_array = calloc(num, sizeof(int));
	for(i=0; i<num; i++)
	{
		printf("%d��° ��� �Է�:", i);
		scanf("%d", &line_array[i]);
	}
		printf("�˻��ϰ� ���� ���� �Է�:");
		scanf("%d", &key);
		
	for(i=0; i<num; i++)
		bin_array[i] = line_array[i];
	
		bubble_sort(bin_array, num);
		linear_answer = linear_search(line_array, num, key);
		binary_answer = binary_search(bin_array,num,key);
		
		if(linear_answer == -1 && binary_answer == -1)
			printf("�˻��� �����߽��ϴ�!!\n");
				
		else
		{	
		printf("���� �˻� ��� : ��Ҵ� �迭[%d]�� ����.\n", linear_answer);
		printf("���� �˻� ��� : ��Ҵ� �迭[%d]�� ����.\n", binary_answer);
	 	}
		free(bin_array);
		free(line_array);		 
	
	return 0 ;
}
