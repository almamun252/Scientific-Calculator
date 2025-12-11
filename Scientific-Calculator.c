#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define pi 3.14159
#define max_history 5

double curr_result = 0.0;
char history[max_history][100];
int history_count = 0;

void history_add(char *entry);
void view_history();


void main_interface();
void clear_screen();
void clear_input_buff();
void pause_Screen();
void basic_operations();
void advanced_operations();
void logarithm_functions();
void trigonometric_functions();
void special_functions();



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
            trigonometric_functions();
            break;

        case 4:
            special_functions();
            break;

        case 5:
        view_history();
            break;

        case 6:
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

// <<--Main Interface Function-->>

void main_interface(){
    clear_screen();
    printf("\n");
    printf(" ------------------------------------------------------- \n");
    printf("|            ==== Scientific Calculator ====            |\n");
    printf("|-------------------------------------------------------|\n");
    printf("| [1] Basic Operations          [2] Advanced Operations |\n");
    printf("| [3] Trigonometric functions   [4] Special Functions   |\n");
    printf("| [5] View History              [6] Exit                |\n");
    printf(" ------------------------------------------------------- \n");
    printf("  Ans: %.2lf                                             \n",curr_result);
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


// <<--History Functions-->>

void history_add(char *entry){
    if(history_count < max_history){
        strcpy(history[history_count++], entry);
    } else {
        for(int i=1; i<max_history; i++){
            strcpy(history[i-1], history[i]);
        }
        strcpy(history[max_history-1], entry);
    }
}

void view_history(){
    clear_screen();
    printf(" ----------------------------------------------------- \n");
    printf("|            ==== Calculation History ====            |\n");
    printf(" ----------------------------------------------------- \n");

    if(history_count == 0){
        printf("|            No history available.                    |\n");
    }else{
        for(int i=0; i<history_count; i++){
            printf(" %-53s \n", history[i]);
        }
    }

    printf(" ----------------------------------------------------- \n");
    clear_input_buff();
    pause_Screen();
}



// <<--Basic Operations Function-->>

void basic_operations(){
    int choice;
    double num1, num2;
    char entry[100];

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
        printf("  Ans: %.2lf                                             \n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }

        if(choice == 5){
            break;
        }

        if(choice < 1 || choice > 4){
            printf(" Invalid Choice! Please try again. \n");
            clear_input_buff();
            pause_Screen();
            continue;
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
                sprintf(entry, "%.2lf + %.2lf = %.2lf", num1, num2, curr_result);
                history_add(entry);
                break;

            case 2:
                curr_result = num1 - num2;
                sprintf(entry, "%.2lf - %.2lf = %.2lf", num1, num2, curr_result);
                history_add(entry);
                break;

            case 3:
                curr_result = num1 * num2;
                sprintf(entry, "%.2lf * %.2lf = %.2lf", num1, num2, curr_result);
                history_add(entry);
                break;

            case 4:
                if(num2 != 0){
                    curr_result = num1 / num2;
                    sprintf(entry, "%.2lf / %.2lf = %.2lf", num1, num2, curr_result);
                    history_add(entry);
                } else {
                    printf(" Error: Division by zero! \n");
                    clear_input_buff();
                    pause_Screen();
                }
                break;

            default:
                printf(" Invalid Choice! Please try again. \n");
                clear_input_buff();
                pause_Screen();
                break;
        }
    }
}


// <<--Advanced Operations Function-->>

void advanced_operations(){
    int choice;
    double num, base, power;
    char entry[100];
    
    while(1){
        clear_screen();
        printf("\n");
        printf(" ------------------------------------------------------- \n");
        printf("|             ==== Advanced Operations ====             |\n");
        printf("|-------------------------------------------------------|\n");
        printf("| [1] Power(x^y)             [2] Square Root            |\n");
        printf("| [3] Cubic root             [4] Logarithm              |\n");
        printf("| [5] Exponential(e^x)       [6] Back to Main Menu      |\n");
        printf(" ------------------------------------------------------- \n");
        printf("  Ans: %.2lf                                             \n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }

        if(choice == 6){
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
                sprintf(entry, "%.2lf ^ %.2lf = %.2lf", base, power, curr_result);
                history_add(entry);
                break;

            case 2:
                printf(" Enter number: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }
                if(num >= 0){
                    curr_result = sqrt(num);
                    sprintf(entry, "sqrt(%.2lf) = %.2lf", num, curr_result);
                    history_add(entry);
                } else {
                    printf(" Error: Square root of negative number! \n");
                    clear_input_buff();
                    pause_Screen();
                }
                break;

            case 3:
                printf(" Enter number: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }          
                curr_result = cbrt(num);
                sprintf(entry, "cbrt(%.2lf) = %.2lf", num, curr_result);
                history_add(entry);
                break;

            case 4:
                logarithm_functions();
                break;

            case 5:
                printf(" Enter exponent: ");
                if(scanf("%lf",&num)!=1){
                    clear_input_buff();
                    continue;
                }
                curr_result = exp(num);
                sprintf(entry, "e ^ %.2lf = %.2lf", num, curr_result);
                history_add(entry);
                break;

            default:
                printf(" Invalid Choice! Please try again. \n");
                clear_input_buff();
                pause_Screen();
                break;
        }
    }
}

//<<--Logarithm Functions-->>

void logarithm_functions(){
    int choice;
    double num, base;
    char entry[100];

    while(1){
        clear_screen();
        printf("\n");
        printf(" ------------------------------------------------------- \n");
        printf("|              ==== Logarithm Functions ====            |\n");
        printf("|-------------------------------------------------------|\n");
        printf("| [1] Natural Logarithm (ln)   [2] Logarithm Base 10    |\n");
        printf("| [3] Lograithm (base b)       [4] Advanced Menu        |\n");
        printf(" ------------------------------------------------------- \n");
        printf("  Ans: %.2lf                                             \n",curr_result);
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
                    sprintf(entry, "ln(%.2lf) = %.2lf", num, curr_result);
                    history_add(entry);
                } else {
                    printf(" Error: Logarithm of non-positive number! \n");
                    clear_input_buff();
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
                    sprintf(entry, "log10(%.2lf) = %.2lf", num, curr_result);
                    history_add(entry);
                } else {
                    printf(" Error: Logarithm of non-positive number! \n");
                    clear_input_buff();
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
                    sprintf(entry, "log base %.2lf of %.2lf = %.2lf", base, num, curr_result);
                    history_add(entry);
                } else {
                    printf(" Error: Invalid base or number for logarithm! \n");
                    clear_input_buff();
                    pause_Screen();
                }
                break;

            default:
                printf(" Invalid Choice! Please try again. \n");
                clear_input_buff();
                pause_Screen();
                break;
        }
    }
}

//<<--Trigonometric Functions-->>

void trigonometric_functions(){
    int choice;
    double angle, radians;
    char entry[100];

    while(1){
        clear_screen();
        printf("\n");
        printf(" ------------------------------------------------------- \n");
        printf("|            ==== Trigonometric Functions ====          |\n");
        printf("|-------------------------------------------------------|\n");
        printf("| [1] Sin        [2] Cos        [3] Tan                 |\n");
        printf("| [4] A Sin      [5] A Cos      [6] A Tan               |\n");
        printf("| [7] Sin h      [8] Cos h      [9] Tan h               |\n");
        printf("| [0] Back to Main Menu                                 |\n");
        printf(" ------------------------------------------------------- \n");
        printf("  Ans: %.2lf                                            \n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }
        if(choice == 0){
            break;
        }

        if(choice >=1 && choice <=3){
            printf(" Enter angle in degrees: ");
            if(scanf("%lf",&angle)!=1){
                clear_input_buff();
                continue;
            }
            radians = angle * (pi / 180.0);

            switch(choice){
                case 1:
                    curr_result = sin(radians);
                    sprintf(entry, "sin(%.2lf) = %.2lf", angle, curr_result);
                    history_add(entry);
                    break;

                case 2:
                    curr_result = cos(radians);
                    sprintf(entry, "cos(%.2lf) = %.2lf", angle, curr_result);
                    history_add(entry);
                    break;

                case 3:
                    if(fabs(cos(radians)) > 1e-10){
                        curr_result = tan(radians);
                        sprintf(entry, "tan(%.2lf) = %.2lf", angle, curr_result);
                        history_add(entry);
                    } else {
                        printf(" Error: Tangent undefined for this angle! \n");
                        clear_input_buff();
                        pause_Screen();
                        continue;
                    }
                    break;
            }
        } else if(choice >=4 && choice <=6){
            printf(" Enter value: ");
            if(scanf("%lf",&angle)!=1){
                clear_input_buff();
                continue;
            }

            switch(choice){
                case 4:
                    if(angle >= -1 && angle <= 1){
                        curr_result = asin(angle) * (180.0 / pi);
                        sprintf(entry, "arcsin(%.2lf) = %.2lf", angle, curr_result);
                        history_add(entry);
                    } else {
                        printf(" Error: Invalid input for arcsin! \n");
                        clear_input_buff();
                        pause_Screen();
                    }
                    break;

                case 5:
                    if(angle >= -1 && angle <= 1){
                        curr_result = acos(angle) * (180.0 / pi);
                        sprintf(entry, "arccos(%.2lf) = %.2lf", angle, curr_result);
                        history_add(entry);
                    } else {
                        printf(" Error: Invalid input for arccos! \n");
                        pause_Screen();
                    }
                    break;

                case 6:
                    curr_result = atan(angle) * (180.0 / pi);
                    sprintf(entry, "arctan(%.2lf) = %.2lf", angle, curr_result);
                    history_add(entry);
                    break;
            }
        } else if(choice >=7 && choice <=9){
            printf(" Enter value: ");
            if(scanf("%lf",&angle)!=1){
                clear_input_buff();
                continue;
            }

            switch(choice){
                case 7:
                    curr_result = sinh(angle);
                    sprintf(entry, "sinh(%.2lf) = %.2lf", angle, curr_result);
                    history_add(entry);
                    break;

                case 8:
                    curr_result = cosh(angle);
                    sprintf(entry, "cosh(%.2lf) = %.2lf", angle, curr_result);
                    history_add(entry);
                    break;

                case 9:
                    curr_result = tanh(angle);
                    sprintf(entry, "tanh(%.2lf) = %.2lf", angle, curr_result);
                    history_add(entry);
                    break;
            }
        } else {
            printf(" Invalid Choice! Please try again. \n");
            clear_input_buff();
            pause_Screen();
        }

       
    }
}

//<<--Special Functions-->>

void special_functions(){
    int choice;
    double num1, num2;
    int n;
    char entry[100];

    while(1){
        clear_screen();
        printf(" ------------------------------------------------------- \n");
        printf("|               ==== Special Functions ====             |\n");
        printf(" ------------------------------------------------------- \n");
        printf("| [1] Factorial(n!)            [2] Modulo(a %% b)        |\n");
        printf("| [3] Absolute Value(|x|)      [4] Back to Main Menu    |\n");
        printf(" ------------------------------------------------------- \n");
        printf("  Ans: %.2lf                                             \n",curr_result);
        printf(" ------------------------------------------------------- \n");
        printf(" Select Operation: ");

        if(scanf("%d",&choice)!=1){
            clear_input_buff();
            continue;
        }

        if(choice ==4){
            break;
        }

        switch(choice){
            case 1:
                printf(" Enter a non-negative integer: ");
                if(scanf("%d",&n)!=1 || n < 0){
                    clear_input_buff();
                    printf(" Error: Invalid input for factorial! \n");
                    pause_Screen();
                    continue;
                }else if(n > 20){
                    printf(" Error: Factorial result too large to compute! \n");
                    clear_input_buff();
                    pause_Screen();
                    continue;
                }
                else{
                    unsigned long long fact = 1;
                    for(int i=1; i<=n; i++){
                        fact *= i;
                    }
                    curr_result = (double)fact;
                    sprintf(entry, "%d! = %.0lf", n, curr_result);
                    history_add(entry);
                }
                break;

            case 2:
                printf(" Enter first number (a): ");
                if(scanf("%lf",&num1)!=1){
                    clear_input_buff();
                    continue;
                }
                printf(" Enter second number (b): ");
                if(scanf("%lf",&num2)!=1 || num2 == 0){
                    clear_input_buff();
                    printf(" Error: Invalid input for modulo! \n");
                    clear_input_buff();
                    pause_Screen();
                    continue;
                }
                curr_result = fmod(num1, num2);
                sprintf(entry, "fmod(%.2lf, %.2lf) = %.2lf", num1, num2, curr_result);
                history_add(entry);
                break;

            case 3:
                printf(" Enter number: ");
                if(scanf("%lf",&num1)!=1){
                    clear_input_buff();
                    continue;
                }
                curr_result = fabs(num1);
                sprintf(entry, "|%.2lf| = %.2lf", num1, curr_result);
                history_add(entry);
                break;

            default:
                printf(" Invalid Choice! Please try again. \n");
                clear_input_buff();
                pause_Screen();
                break;
        }
    }

}