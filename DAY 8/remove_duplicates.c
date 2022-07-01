// C program to delete the duplicate
// from the array
#include <stdio.h>
int delete_duplicate(int arr[], int n)
{
int ret = 0;
int maximum_size = 0;
int i = 0;

for(;i < n;i++){
    if(arr[i] > maximum_size){
        maximum_size =  arr[i];
    }
}

maximum_size = maximum_size +1;
int count[maximum_size];
for(i = 0;i < maximum_size ;i++){
    count[i] = 0;
}
for(i = 0;i < n ;i++){
    count[arr[i]]++;
}
for(i = 0;i < maximum_size ;i++){
    if(count[i] > 0){
        arr[ret] = i;
        ret++;
    }
}

return ret;
}
int main()
{
int n;
printf("\n Enter the array size ");
scanf("%d", &n);
int array[n];
int i;
printf("\n Enter the array values ");
for (i = 0; i < n; i++)
{
scanf("%d", &array[i]);
}
printf("\nArray value before removing duplicate ");
for(i = 0;i < n;i++){
    printf("%d ",array[i]);
}
n = delete_duplicate(array, n);

for(i = 0;i < n;i++){
    printf("%d ",array[i]);
}

return 0;
}