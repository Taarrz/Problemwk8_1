#include <stdio.h>
struct numberin {
    int num;
    bool isred;
};
numberin numpoint[100][100];
int checknumpoint(int i, int j);
int checknextnumber(int i, int j);
int main()
{
    int n;
    int sum = 0;
    int checknum1 = 0, checknum2 = 0;
   

    printf("Enter the number of rows \n");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
        {
            scanf_s("%d", &numpoint[i][j].num, sizeof(numpoint));
            numpoint[i][j].isred = false;
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0) {
                numpoint[0][0].isred = true;
                sum = numpoint[0][0].num;
            }
            else {
                if (j < i) {
                    checknum1 = checknumpoint(i, j);
                    checknum2 = checknumpoint(i, j + 1);
                    if (checknum1 != 0 &&checknum2 != 0) {
                    sum=sum+checknextnumber(i, j);
                    checknum1 = 0;
                    checknum2 = 0;
                    }
                }
                
                
            }
        }

    }
    printf("%d", sum);
    return 0;
}

int checknextnumber(int i, int j) {
    if (numpoint[i][j].num > numpoint[i][j+1].num) {
        numpoint[i][j].isred = true;
        return numpoint[i][j].num;
    }
    else {
        numpoint[i][j+1].isred = true;
        return numpoint[i][j+1].num;
    }
}

int checknumpoint(int i, int j) {
    if (numpoint[i-1][j-1].isred == true || numpoint[i-1][j].isred == true) {
        return  numpoint[i][j].num;
    }
    else {
        return 0;
    }
}