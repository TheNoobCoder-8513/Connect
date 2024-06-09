int retrievedata ()
{
    FILE *fd;
    fd = fopen ("data/contactlist.txt", "r");
    fscanf (fd, "%3d\n", &saved);

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
return 0;
}
