#include <stdio.h>
int main(){
    int num, count =0;
    printf("Enter the number: ");
    scanf("%d", &num);
    while(num > 0){
        count = count + (num & 1);
        num >>= 1;        
    }
    printf("%d",count);
    return 0;
}