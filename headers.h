#include <stdio.h>
#include <string.h>

#define SUCCESS 111
#define FAIL 000
#define ERROR 101


typedef struct contact 
{
    char name[26];
    char phonenum[11];
    char altphonenum[11];
    char dob[11];
    char mail[36];
    char address[101];
    char other[51];
} contact;
contact info[3];

int saved = 0;

// ------------------------------------ //


// ------------------------------------ //

typedef struct UIdata
{

} UIdata;
UIdata *ui; 