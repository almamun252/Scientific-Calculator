#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double curr_result = 0.0;
#define pi 3.14159

void main_interface();
void clear_screen();
void clear_input_buff();
void pause_Screen();
void basic_operations();
void advanced_operations();
void logarithm_functions();



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
            basic_operations();
            break;
        case 2:
            advanced_operations();
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
    printf("| Ans: %.2lf                                             |\n",curr_result);
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




// <<--Basic Operations Function-->>

void basic_operations(){
    int choice;
    double num1, num2;

    while(1){
        clear_screen();
        printf("\n");
        printf(" ------------------------------------------------------- \n");
        printf("|               ==== Basic Operations ====              |\n");
        printf("|-------------------------------------------------------|\n");
        printf("| [1] Addition                [2] Subtraction           |\n");
        printf("| [3] Multiplication          [4] Division              |\n");
        printf("| [5] Back to Main Menu                                 |\n");
        printf(" ------------------------------------------------------- \n");
        printf("| Ans: %.2lf                                             |\n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }

        if(choice == 5){
            break;
        }

        printf(" Enter first number: ");
        if(scanf("%lf",&num1)!=1){
            clear_input_buff();
            continue;
        }

        printf(" Enter second number: ");
        if(scanf("%lf",&num2)!=1){
            clear_input_buff();
            continue;
        }

        switch(choice){
            case 1:
                curr_result = num1 + num2;
                break;
            case 2:
                curr_result = num1 - num2;
                break;
            case 3:
                curr_result = num1 * num2;
                break;
            case 4:
                if(num2 != 0){
                    curr_result = num1 / num2;
                } else {
                    printf(" Error: Division by zero! \n");
                    pause_Screen();
                }
                break;
            default:
                printf(" Invalid Choice! Please try again. \n");
                pause_Screen();
                break;
        }
    }
}


// <<--Advanced Operations Function-->>

void advanced_operations(){
    int choice;
    double num, base, power;
    while(1){
        clear_screen();
        printf("\n");
        printf(" ------------------------------------------------------- \n");
        printf("|             ==== Advanced Operations ====             |\n");
        printf("|-------------------------------------------------------|\n");
        printf("| [1] Power(x^y)             [2] Square Root            |\n");
        printf("| [3] Logarithm              [4] Back to Main Menu      |\n");
        printf(" ------------------------------------------------------- \n");
        printf("| Ans: %.2lf                                             |\n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }

        if(choice == 4){
            break;
        }

        switch(choice){
            case 1:
                printf(" Enter base: ");
                if(scanf("%lf",&base)!=1){
                    clear_input_buff();
                    continue;
                }
                printf(" Enter power: ");
                if(scanf("%lf",&power)!=1){
                    clear_input_buff();
                    continue;
                }
                curr_result = pow(base, power);
                break;
            case 2:
                printf(" Enter number: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }
                if(num >= 0){
                    curr_result = sqrt(num);
                } else {
                    printf(" Error: Square root of negative number! \n");
                    pause_Screen();
                }
                break;
            case 3:
                logarithm_functions();
                break;
            default:
                printf(" Invalid Choice! Please try again. \n");
                pause_Screen();
                break;
        }
    }
}

//<<--Logarithm Functions-->>

void logarithm_functions(){
    int choice;
    double num, base;

    while(1){
        clear_screen();
        printf("\n");
        printf(" ------------------------------------------------------- \n");
        printf("|              ==== Logarithm Functions ====            |\n");
        printf("|-------------------------------------------------------|\n");
        printf("| [1] Natural Logarithm (ln)   [2] Logarithm Base 10    |\n");
        printf("| [3] Lograithm (base b)       [4] Advanced Menu        |\n");
        printf(" ------------------------------------------------------- \n");
        printf("| Ans: %.2lf                                             |\n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");
        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }

        if(choice == 4){
            break;
        }

        switch(choice){
            case 1:
                printf(" Enter number: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }
                if(num > 0){
                    curr_result = log(num);
                } else {
                    printf(" Error: Logarithm of non-positive number! \n");
                    pause_Screen();
                }
                break;
            case 2:
                printf(" Enter number: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }
                if(num > 0){
                    curr_result = log10(num);
                } else {
                    printf(" Error: Logarithm of non-positive number! \n");
                    pause_Screen();
                }
                break;
            case 3:
                printf(" Enter base: ");
                if(scanf("%lf",&base)!=1){
                    clear_input_buff();
                    continue;
                }
                printf(" Enter number: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }
                if(base > 0 && base != 1 && num > 0){
                    curr_result = log(num) / log(base);
                } else {
                    printf(" Error: Invalid base or number for logarithm! \n");
                    pause_Screen();
                }
                break;
            default:
                printf(" Invalid Choice! Please try again. \n");
                pause_Screen();
                break;
        }
    }
}