#include <stdio.h>
#include <string.h>

void forward(char string[]);
void backward(char string[]);
void vertical(char string[]);
void triangle(char string[]);

int main(){
    int shape_choice = 0;
    char str[255] = {0};
    int on = 1;
    
    printf("Welcome to playing with strings\n\n");
    
    while(on == 1){
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // remove trailing newline
        
        printf("String received: '%s' (length: %zu)\n", str, strlen(str));
        
        printf("Choose a shape to display the string:\n");
        printf("1. Forward\n");
        printf("2. Backward\n");
        printf("3. Vertical\n");
        printf("4. Triangle\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        scanf("%d", &shape_choice);
        getchar(); // consume leftover newline
        
        switch(shape_choice){
            case 1:
                forward(str);
                break;
            case 2:
                backward(str);
                break;
            case 3:
                vertical(str);
                break;
            case 4:
                triangle(str);
                break;
            case 5:
                on = 0;
                break;
            default:
                printf("Invalid choice. Please select a number between 1 and 5.\n");
        }
        printf("\n"); // spacing between iterations
    }
    
    printf("Thank you for using the string pattern program!\n");
    return 0;
}

void forward(char string[]){
    for(int i = 0; string[i] != '\0'; i++){
        printf("%c", string[i]);
    }
    printf("\n"); // add newline after printing
}

void backward(char string[]){
    int len = strlen(string);
    for(int i = len - 1; i >= 0; i--){
        printf("%c", string[i]);
    }
    printf("\n");
}

void vertical(char string[]){
    printf("Vertical display:\n");
    for(int i = 0; string[i] != '\0'; i++){
        printf("%c\n", string[i]);
    }
}

void triangle(char string[]){
    printf("Triangle display:\n");
    int len = strlen(string);
    for(int i = 0; i < len; i++){
        for(int j = 0; j <= i; j++){
            printf("%c", string[j]);
        }
        printf("\n");
    }
}
