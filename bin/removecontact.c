int removecontact (int index)
{
    FILE *fdr;
    FILE *fdw;

    fdr = fopen ("data/contactlistcache.txt", "r");
    fdw = fopen ("data/contactlist.txt", "w");

    char reader;
    int contactindex = 1;

    reader = fgetc (fdr);
    if (reader == '\n') index++;

    while (!(feof (fdr)))
    {
        if (contactindex != index) fputc (reader, fdw);
        reader = fgetc (fdr);
        if (reader == '\n') contactindex++;
    }

    fclose (fdr);
    fclose (fdw);

    saved--;
    generatecache ();

    savedata ();
}