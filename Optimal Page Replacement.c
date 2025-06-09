#include <stdio.h>

int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[10], optcal[50], count = 0;

int optvictim(int index);

void main() {
    printf("\nOPTIMAL PAGE REPLACEMENT ALGORITHM\n");
    printf("-----------------------------------\n");

    printf("Enter the number of frames: ");
    scanf("%d", &nof);

    printf("Enter the number of Reference string elements: ");
    scanf("%d", &nor);

    printf("Enter the Reference string: ");
    for (i = 0; i < nor; i++) {
        scanf("%d", &ref[i]);
    }

    printf("\nThe given Reference string: ");
    for (i = 0; i < nor; i++) {
        printf("%d ", ref[i]);
    }

    for (i = 0; i < nof; i++)
        frm[i] = -1;

    for (i = 0; i < 10; i++)
        recent[i] = 0;

    for (i = 0; i < nor; i++) {
        flag = 0;
        printf("\nRef no. %d ->\t", ref[i]);

        for (j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            count++;
            if (count <= nof) {
                victim++;
            } else {
                victim = optvictim(i + 1);
                pf++;
            }
            frm[victim] = ref[i];
        }

        for (j = 0; j < nof; j++) {
            if (frm[j] == -1)
                printf("- ");
            else
                printf("%d ", frm[j]);
        }
    }

    printf("\n\nTotal number of page faults: %d\n", pf);
}

int optvictim(int index) {
    int i, j, temp, notfound;
    for (i = 0; i < nof; i++) {
        notfound = 1;
        for (j = index; j < nor; j++) {
            if (frm[i] == ref[j]) {
                notfound = 0;
                optcal[i] = j;
                break;
            }
        }
        if (notfound == 1)
            return i;
    }

    temp = optcal[0];
    for (i = 1; i < nof; i++) {
        if (temp < optcal[i])
            temp = optcal[i];
    }

    for (i = 0; i < nof; i++) {
        if (ref[temp] == frm[i])
            return i;
    }

    return 0;
}
/*
OPTIMAL PAGE REPLACEMENT ALGORITHM  
-----------------------------------  
Enter the number of frames: 3  
Enter the number of Ref string elements: 10  
Enter the Ref string: 1 2 3 4 1 2 5 1 2 3  

The given Ref string: 1 2 3 4 1 2 5 1 2 3  

Ref no. 1 ->    1 - -  
Ref no. 2 ->    1 2 -  
Ref no. 3 ->    1 2 3  
Ref no. 4 ->    1 2 4  
Ref no. 1 ->    1 2 4  
Ref no. 2 ->    1 2 4  
Ref no. 5 ->    1 2 5  
Ref no. 1 ->    1 2 5  
Ref no. 2 ->    1 2 5  
Ref no. 3 ->    1 2 3  

Total number of page faults: 5  */
