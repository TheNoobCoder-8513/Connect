int addcontact (contact details)
{
    FILE *fw;
    fw = fopen ("data/contactlistcache.txt", "a");

    fprintf
        (
            fw,
            "%s;%s;%s;%s;%s;%s;%s\n",
            details.name,
            details.phonenum,
            details.altphonenum,
            details.dob,
            details.mail,
            details.address,
            details.other
        );

    fclose (fw);

    saved ++;
    printf ("TEST\n");
    savedata ();
}