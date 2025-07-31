#include <stdio.h>
#include <stdlib.h>

#define DOORS 3
#define RUNS 10000

int main()
{
    int num_win=0;
    char change_y_n;
    printf("Change? Y/N:");
    scanf("%c", &change_y_n);
   
    for (int i=0; i<RUNS; i++) {
        int car=rand()%DOORS;
        int initial_choice=rand()%DOORS;
        int final_choice=-1;
        int monte_choice=car;
       
        //Monte's choice ensure no conflict
        while ((monte_choice == initial_choice) || (monte_choice ==car))
            monte_choice=rand()%DOORS;
       
        if (change_y_n=='Y') {
            switch (initial_choice) {
                case 0:
                    final_choice=(monte_choice==1)?2:1;
                    break;
                case 1:
                    final_choice=(monte_choice==0)?2:0;
                    break;
                case 2:
                    final_choice=(monte_choice==0)?1:0;
                    break;
            }
        } else {
            final_choice=initial_choice;
        }
        //printf("%d, %d, %d, %d\n",car, initial_choice, monte_choice, final_choice);
        if (final_choice==car)
            num_win++;
    }
    printf ("Winning Percentage When Change is %c is %f", change_y_n, (double) num_win/RUNS);
   

    return 0;
}
