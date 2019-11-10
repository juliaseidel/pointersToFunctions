#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include <string.h>
#include <stdbool.h>


void display_people(person array[NUM_OF_PEOPLE]){
    for (int i = 0; i < NUM_OF_PEOPLE; ++i) {
        printf("This is data for person no. %d: name - %s, height - %lf, weight - %lf\n", i+1, array[i].name, array[i].height, array[i].weight);
    }
}

int compareHeight(void * person1, void * person2){
    person *human1;
    human1 = (person *)person1;

    person *human2;
    human2 = (person *)person2;

    return human1 -> height > human2 -> height ? 1 : human1 ->height < human2 -> height ? -1 : 0;
}

int compareWeight(void * person1, void * person2){
    person *human1;
    human1 = (person *)person1;

    person *human2;
    human2 = (person *)person2;

    return human1 -> weight > human2 -> weight ? 1 : human1 ->weight < human2 -> weight ? -1 : 0;
}

int compareName(void * person1, void * person2){

    person *human1;
    human1 = (person *)person1;

    person *human2;
    human2 = (person *)person2;

    int answer =  strcmp(human1 -> name, human2 -> name);

    return answer > 0 ? 1 : answer < 0 ? -1 : 0;
}


int main() {
    struct person people[NUM_OF_PEOPLE];
    char name_read[20];
    double height_read;
    double weight_read;

    printf("Please enter filename ");
    char filename[20];
    scanf(" %[^\n]", filename);
    FILE * fp = fopen(filename, "r");

    if (fp != NULL){
        int i=0;
        while (!feof(fp)){
            fscanf(fp, "%s %lf %lf", name_read, &height_read, &weight_read);
            strcpy(people[i].name, name_read);
            people[i].height = height_read;
            people[i].weight = weight_read;

            i++;
        }
        bool answer = true;
        while (answer) {
            printf("What do you want to do?\n"
                   "1 - display people data\n"
                   "2 – display people sorted by height\n"
                   "3 - display people sorted by weight\n"
                   "4 - display people sorted by name\n"
                   "5 - exit the program\n");
            int c;
            scanf("%d", &c);
            switch (c) {
                case 1:
                    display_people(people);
                    break;
                case 2:
                    qsort((void *) &people[0], 50, sizeof(people[0]), compareHeight);
                    display_people(people);
                    break;
                case 3:
                    qsort((void *) &people[0], 50, sizeof(people[0]), compareWeight);
                    display_people(people);
                    break;
                case 4:
                    qsort((void *) &people[0], 50, sizeof(people[0]), compareName);
                    display_people(people);
                    break;
                case 5:
                    answer = false;
                    break;
            }
        }
    }
}