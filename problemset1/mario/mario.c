#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size;
    do{
        size = get_int("Enter the size of the pyramid :");
    }while(size < 1 || size > 8);

     int i,j;
        for(i=size;i>=0;i--){
            for(j=0;j<size;j++){
                if(j>=i){
                    printf("#");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
}
