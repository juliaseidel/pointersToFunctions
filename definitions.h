//
// Created by Julia Seidel on 08/11/2019.
//

#define NUM_OF_PEOPLE 50

typedef struct person person;

typedef struct person {
    char name[21];
    double height;
    double weight;
};

void display_people(person array[NUM_OF_PEOPLE]);

int compareHeight(void * person1, void * person2);

int compareWeight(void * person1, void * person2);

int compareName(void * person1, void * person2);