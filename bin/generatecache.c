int generatecache ()
{
    FILE *fdr;
    FILE *fdw;

    fdr = fopen ("data/contactlist.txt", "r");
    fdw = fopen ("data/contactlistcache.txt", "w");

    char reader;
    reader = fgetc (fdr);
    while (!(feof (fdr)))
    {
        fputc (reader, fdw);
        reader = fgetc (fdr);
    }

    fclose (fdr);
    fclose (fdw);
}