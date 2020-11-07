#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 128
#define INTIAL_SIZE 2
typedef char String[LENGTH];

typedef struct itemTag{
    String name; 
    float price;
    int quantity;
}Item;


int main(void){

    Item * item = (Item *)malloc(sizeof(Item));
    String choice;
    float price;
    int quant;
    int size = 1;
    int i, j;
    int index = -1;
    for(i = 0;;i++){

        if (size == index)
        {
            size *= 2;
            item = (Item *)realloc(item, size * sizeof(Item));
        }

        index++;
        printf("Enter item information (\" exit \" to exit) \n" )  ;
        printf("Item %d : ", i+1);
        scanf("%s", choice);
        if(strcmp(choice,"exit") == 0){
            break;
        }
        printf("Price : ");
        scanf("%f", &price);

        printf("Quantity : ");
        scanf("%d", &quant);
        strcpy((item+index)->name,choice);
        (item + index)-> price = price;
        (item + index)->quantity = quant;

       
    }
    
    float sum = 0;
    
    for(j = 0; j < index; j++){

        printf("%s \t %d %f\n", (item + j)->name , (item + j)->quantity, (item + j)->price);
        sum += ((item + j)->quantity) * ((item + j)->price);
    }
    printf("-----------------------------------------\n");
    printf("Total \t %.2f\n",sum);
    free(item);
    
    return 0;
}