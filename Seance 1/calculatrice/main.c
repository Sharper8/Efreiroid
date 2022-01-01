#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Calculatrice");
    while (1)
    {
        int choice = 0, a = 0, b = 0;
        printf("\n\nSélectionnez l'opération :\n1 - addition\n2 - soustraction\n");
        scanf("%d", &choice);
        printf("Entrez les operateurs :\na = ");
        scanf("%d", &a);
        printf("b = ");
        scanf("%d", &b);

        switch (choice)
        {
        case 1:
            printf("%d + %d = %d", a, b, a+b);
            break;
        case 2:
            printf("%d - %d = %d", a, b, a-b);
            break;
                    
        default:
            break;
        }
    }
    return 0;
}
