#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double curr_result = 0.0;
#define pi 3.14159

void main_interface();
void clear_screen();
void clear_input_buff();
void pause_Screen();



int main(){
    int choice;

    while(1){
        main_interface();
        printf(" Select Mode: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }
    

    switch(choice){
        case 1:
            printf(" Basic Operations Selected \n");
            break;
        case 2:
            printf(" Advanced Operations Selected \n");
            break;
        case 3:
            printf(" Trigonometric Functions Selected \n");
            break;
        case 4:
            printf(" Special Functions Selected \n");
            break;
        case 5:
            printf(" Exiting... \n");
            return 0;
        default:
            printf(" Invalid Choice! Please try again. \n");
            pause_Screen();
            break;
    }
    
}
    
    return 0;
}

void main_interface(){
    clear_screen();
    printf("\n");
    printf(" ------------------------------------------------------- \n");
    printf("|            ==== Scientific Calculator ====            |\n");
    printf("|-------------------------------------------------------|\n");
    printf("| [1] Basic Operations          [2] Advanced Operations |\n");
    printf("| [3] Trigonometric functions   [4] Special Functions   |\n");
    printf("| [5] Exit                                              |\n");
    printf(" ------------------------------------------------------- \n");
    printf("| Ans: %.2lf                                            |\n",curr_result);
    printf(" ------------------------------------------------------- \n");

}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void clear_input_buff(){
    int c;
    while((c=getchar())!='\n' && c !=EOF);
}

void pause_Screen(){
    printf("inter to continue...");
    getchar();
}