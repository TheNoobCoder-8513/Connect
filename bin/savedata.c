int savedata ()
{
    FILE *fdr;
    FILE *fdw;

    fdr = fopen ("data/contactlistcache.txt", "r");
    fdw = fopen ("data/contactlist.txt", "w");

    char reader;
    reader = fgetc (fdr);
    while (!(feof (fdr)))
    {
        fputc (reader, fdw);
        reader = fgetc (fdr);
    }

    fclose (fdr);
    fclose (fdw);

    FILE *fsaved;
    fsaved = fopen("variables.txt", "w");
    fprintf (fsaved, "saved=%d\n", saved);
    fclose (fsaved);
}