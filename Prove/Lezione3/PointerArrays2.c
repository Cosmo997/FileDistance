#include <stdio.h>

int main(void)
{
    // ! EQUIVALENT POINTER VALUES
    char letters[26];
    char *pc1 = letters;
    char *pc2 = &letters;
    char *pc3 = &letters[0];

    // ! EQUIVALENT INDEXES

    letters[4] = 'e';
    pc1[4] = 'e';
    *(letters + 4) = 'e';
    *(pc2 + 4) = 'e';

    // ! EQUIVALENT ADDRESSES

    pc3 = &letters[10];
    pc3 = &pc1[10];
    pc3 = letters + 10;
    pc3 = pc2 + 10;
}