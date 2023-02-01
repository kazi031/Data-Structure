#include<stdio.h>
#include<stdlib.h>
#define init_size 4

int length;
int capacity;
int *list;

void init();
void expand();
void shrink();
void print();

/**
Insert a given integer in such a position that the list remains sorted and print the modified list
Return index of the inserted element.
**/
int insert(int element){
	// Write your code here
	if (length>=capacity){
        expand();
	}
        for(int i=0; i<length; i++){
            if(list[i]>element){
                    for(int j=length; j>i; j--){
                            list[j]=list[j-1];
                    }
                list[i]=element;
                length++;
                printf("2");
                return i;
            }

          }
            list[length]=element;
            length++;
            printf("3");
            return length-1;

}


/**
Determine if a given integer exists in the list.
Return index of the element.
If the given integer does not exist in the list return -1
**/
int linear_search(int element){
	// Write your code here
	for (int i=0; i<length; i++){
        if (list[i]==element)
        {
            return i;
        }
	}
	return -1;
}

/**
Delete the first occurrence of a given integer from the list.
Return index of the deleted element.
If the given integer does not exist in the list return -1
**/
int remove(int element)
{
	// Write your code here


}
/**
Search an element using bianry search algorithm from the list.
Return index if the element is found.
If the given element is not found then return -1.
**/

int binary_search(int element)
{




}


/** Bonus if binary search algorithm can be implemented in recursive way
Recursion binary.
If found, return index
if not return -1.
**/


int binary_search(int high, int low, int element){







}




/**
Each line of input starts with a code letter: I for insert, D for delete, L for linear search, P for print, B for linear search, R for recursive binary search
and Q for quit .
For I,D and L; the code letter is followed by a blank space and then an integer, which is to be inserted, deleted or found.
**/
int main(){
	char option; int element, result;
	init();
	while(1){
		scanf("%c",&option);
		switch(option){
			case 'Q':
				return 0;
			case 'I':
				scanf("%d",&element);
				result=insert(element);
				printf("\nInserted at position %d\n",result);
				print();
				break;
			case 'D':
				scanf("%d",&element);
				result=remove(element);
				if(result==-1){
					printf("\nElement not exist\n");
				}
				else{
					printf("\nDeleted from position %d\n",result);
				}
				print();
				break;
			case 'L':
				scanf("%d",&element);
				result=linear_search(element);
				if(result==-1){
					printf("\nElement not exist\n");
				}
				else{
					printf("\nFound at position %d\n",result);
				}
				print();
				break;
			case 'P':
				print();
				break;
		}
	}
}

/**
Initialize the list with capacity=init_size
**/
void init(){
    list=(int*)malloc(sizeof(int)*init_size);
    capacity=init_size;
    length=0;
}

/**
Double the capacity of the list
Hint: Double the value of capacity, Take another integer pointer
    Allocate memory of size capacity to it and copy the content from previous list to it
    Release the memory occupied by previous list and assign new list to the previous one
**/
void expand(){
    int *temp,i;
    capacity=capacity<<1;
    temp=(int*)malloc(sizeof(int)*capacity);
    for(i=0;i<length;i++){
        temp[i]=list[i];
    }
    free(list);
    list=temp;
}

/**
Half the capacity of list
**/
void shrink(){
    int *temp,i;
    if(capacity==init_size) return;
    capacity=capacity>>1;
    temp=(int*)malloc(sizeof(int)*capacity);
    for(i=0;i<length;i++){
        temp[i]=list[i];
    }
    free(list);
    list=temp;
}

/**
Print all the elements of the list
**/
void print(){
	int i;
	for(i=0;i<length;i++){
		printf("%d ",list[i]);
	}
	printf("\n");
}
