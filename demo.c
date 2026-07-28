#include <stdio.h>

void add(int a, int b)
{
    printf("Addition of two numbers is %d\n", a + b);
}

void sub(int a, int b)
{
    printf("Subtraction of two numbers is %d\n", a - b);
}

void mul(int a, int b)
{
    printf("Multiplication of two numbers is %d\n", a * b);
}

void divide(int a, int b)
{
    if(b != 0)
    {
        printf("Division of two numbers is %.2f\n", (float)a / b);
    }
    else
    {
        printf("Any number cannot be divided by 0\n");
    }
}

void mod(int a, int b)
{
    if(b != 0)
    {
        printf("Modulus of two numbers is %d\n", a % b);
    }
    else
    {
        printf("Any number cannot be divided by 0\n");
    }
}

int main()
{
    int a, b, ch;

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    do
    {
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Modulus");
        printf("\n6. Exit");

        printf("\nEnter the value of ch: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                add(a, b);
                break;

            case 2:
                sub(a, b);
                break;

            case 3:
                mul(a, b);
                break;

            case 4:
                divide(a, b);
                break;

            case 5:
                mod(a, b);
                break;

            case 6:
                printf("No choices left\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(ch != 6);

    return 0;
}
    
    
    

