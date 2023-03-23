#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i, n,trigger, counter, warning, num_binary, num_decimal;
    char check[32];
    while(1) {// reading length of array with binary numbers
        printf("Enter number of digits: \n");
        scanf("%s", &check);
        for(i = 0; i < strlen(check); i++) {
            if ((int)check[i] < 48 || (int)check[i]>57) {
                warning = 1;
                break;
            }
        }
        if(warning!=1){
            n = atoi(check);
            break;
        }
        warning = 0;
    }
    int bin[n], dec[n];
    printf("Enter binary numbers: (one by one)\n");
    for(i = 0; i < n; i++){ // reading binary numbers and filling two arrays with decimal and binary numbers
        warning = 0;
        scanf("%s", &check); // reading binary number
        for(int j = 0; j < strlen(check) ; j++){ // checking binary number for errors
            trigger = check[j];
            if(trigger < 48 || trigger > 49)
                warning = 1;
        }
        if(warning != 1) {
            num_binary = atoi(check);
            bin[i] = num_binary; // adding binary number to array with binary numbers
            num_decimal = 0;
            counter = 0;
            while (num_binary > 0) { // converting binary number into decimal number
                num_decimal += pow(2, counter) * (num_binary % 2);
                counter += 1;
                num_binary /= 10;
            }
            dec[i] = num_decimal; // adding decimal number to array with decimal numbers
        }
        else {
            i -= 1;
            printf("Wrong number, try another.\n");
        }
    }

    printf("Binary numbers: \n");
    for(i = 0; i < n; i++) // printing array of binary numbers
        printf("%d ", bin[i]);
    printf("\nDecimal numbers: \n");
    for(i = 0; i < n; i++) // printing array of decimal numbers
        printf("%d ", dec[i]);
    return 0;
}
