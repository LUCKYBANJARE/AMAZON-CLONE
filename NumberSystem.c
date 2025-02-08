#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decimalToBinary(int decimal, char *binary) {
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';
    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}


int binaryToDecimal(char *binary) {
    return (int)strtol(binary, NULL, 2);
}

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    sprintf(hexadecimal, "%X", decimal);
}

int hexadecimalToDecimal(char *hexadecimal) {
    return (int)strtol(hexadecimal, NULL, 16);
}

void decimalToOctal(int decimal, char *octal) {
    sprintf(octal, "%o", decimal);
}

int octalToDecimal(char *octal) {
    return (int)strtol(octal, NULL, 8);
}


int main() {
    int choice;
    char input[65];
    int decimal;
    int hex;
    char output[65];
    // scanf(" Enter your choice %d",&choice);
    
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal, output);
        printf("Binary: %s\n", output);
        
        printf("Enter an octal number: ");
        scanf("%s", input);
        decimal = octalToDecimal(input);
        printf("Decimal: %d\n", decimal);
        
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        decimalToOctal(decimal, output);
        printf("Octal: %s\n", output);
        
   
        printf("Enter a binary number: ");
        scanf("%s", input);
        decimal = binaryToDecimal(input);
        printf("Decimal: %d\n", decimal);
        
        
        
        printf("Enter a hexadecimal number: ");
        scanf("%s", input);
        decimal = hexadecimalToDecimal(input);
        printf("Decimal: %d\n", decimal);
        
        
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        decimalToHexadecimal(decimal, output);
        printf("Hexadecimal: %s\n", output);
        
        
        printf("Enter a octal number: ");
        scanf("%s",input);
        hex=octalTohexadecimal();
        printf("")
     
        
        printf("Enter an octal number: ");
        scanf("%s", input);
        decimal = octalToDecimal(input);
        decimalToHexadecimal(decimal, output);
        printf("Hexadecimal: %s\n", output);
    
    return 0;
}