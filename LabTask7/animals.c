#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define LENGTH 128
#define INTIAL_SIZE 2
typedef char String[LENGTH];

typedef enum{
    mammal,
    insect,
    bird,
    fish,
    error
}AnimalType;

typedef struct{
    String name;
    AnimalType type;
    float size;
}SpeciesType;

AnimalType InputAnimalType(void){
    String type;
    scanf("%s", type);

    if(!strcmp(type,"mammal")){
        return (mammal);
    }
    if (!strcmp(type, "insect"))
    {
        return (insect);
    }
    if (!strcmp(type, "bird"))
    {
        return (bird);
    }
    if (!strcmp(type, "fish"))
    {
        return (fish);
    }
    return (error);
}

void outputStruct(SpeciesType * t,  int aSize){
    int i;
    printf("Size : %d", aSize);
    for(i = aSize-1; i >= 0; i-- ){
        printf("%s\n", t->name);
        printf("%f\n", t->size);
        printf("%u\n", t->type);
        t--;
    }
}

SpeciesType *createArray(){
    SpeciesType *species = (SpeciesType *)malloc(INTIAL_SIZE * sizeof(SpeciesType));
    return species; //return pointer to species
}


int main(void){

    String names, choice;
    AnimalType type;
    float size;
    SpeciesType * species = createArray();
    
    int lastIndex, Size;
    Size = INTIAL_SIZE;
    lastIndex = -1;
    printf("Intializing vars: Size = %d, lastIndex = %d", Size, lastIndex);
    
    for(;;lastIndex++, species++){
         
        if(lastIndex == Size){
            printf("Intializing vars: Size = %d, lastIndex = %d", Size, lastIndex);
            Size *= 2;
            species = (SpeciesType *)realloc(species, Size * sizeof(createArray()));
        
        }

        printf("\nEnter animal information (\"exit\") to exit) ");
        scanf("%s", choice);
        if(!strcmp(choice,"exit")){
            break;
        }
        printf("\nWhat is the name : ");
        scanf("%s", names);

        printf("\nWhat is the size : ");
        scanf("%f", &size);

        printf("\nWhat is the type : ");
        type = InputAnimalType();

        strcpy((*species).name,names);
        (*species).size = size;
        (*species).type = type;

        
        //outputStruct(species, Size);
    }
    outputStruct(species, Size);

    return 0;
}