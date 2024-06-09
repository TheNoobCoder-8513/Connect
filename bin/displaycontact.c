int displaycontact ()
{
    FILE *fd;
    fd = fopen ("data/contactlistcache.txt", "r");

    char name[26];
    char phonenum[11];
    char altphonenum[11];
    char dob[11];
    char mail[36];
    char address[51];
    char other[26];

    for (int i = 0; i < saved; i++)
    {
        fscanf 
        (
            fd, 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
            name, phonenum, altphonenum, dob, mail, address, other
        );
        
        printf
        (
            "%d.  %s -- %s -- %s -- %s -- %s -- %s -- %s\n",
            i+1, name, phonenum, altphonenum, dob, mail, address, other
        );
        
    }

    fclose (fd);
}