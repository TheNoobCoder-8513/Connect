int retrievecontact ()
{
    FILE *fd;
    fd = fopen ("data/contactlistcache.txt", "r");

    for (int i = 0; i < saved; i++)
    {
        fscanf (fd, 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
            info[i].name,
            info[i].phonenum,
            info[i].altphonenum,
            info[i].dob,
            info[i].mail,
            info[i].address,
            info[i].other
            );
    }

    fclose (fd);

}