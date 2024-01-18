#include<cs50.h>
#include<string.h>
#include<stdio.h>

int getLength(long cno);
void calChecksum(long vcno);
void determineCard(long cno);

int main(void){
    long number = get_long("Enter the card number :");
    int length = getLength(number);

    if(length != 13 && length != 15 && length != 16){
        printf("INVALID !\n");
    }else{
        calChecksum(number);
    }
    return 0;
}

int getLength(long cardno){
    int count = 0;
    while(cardno > 0){
        cardno = cardno / 10;
        count++;
    }
    return count;
}
void calChecksum(long no){
    int sum1 = 0 ,sum2 = 0, ldegit, lsdegit, first, second, total, vcno;
    vcno = no;
    do{
        ldegit = vcno % 10;
        vcno = vcno / 10;
        sum1 = sum1 + ldegit;

        lsdegit = vcno % 10;

        vcno = vcno / 10;
        lsdegit = lsdegit * 2;
        second = lsdegit % 10;
        first = lsdegit / 10;
        sum2 = sum2 +first + second;
    }while(vcno > 0);

    total = sum1+sum2;
    if(total%10 != 0){
        printf("INVALID\n");
    }else{
        determineCard(no);
    }
}

void determineCard(long cno){
    while(cno > 100){
        cno = cno / 10;
    }
    if((cno / 10 == 3) && (cno % 10 == 4 || cno % 10 == 7)){
        printf("\nAMEX\n");
    }else if((cno / 10 == 5) && (cno % 10 == 1 || cno % 10 == 2 || cno % 10 == 3 || cno % 10 == 4 || cno % 10 == 5) ){
        printf("\nMASTERCARD\n");
    }else if(cno / 10 == 4){
        printf("\nVISA\n");
    }else{
        printf("\nINVALID !\n");
    }
}
