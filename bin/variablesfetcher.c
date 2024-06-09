int variablesfetcher (char varname[])
{
    FILE *fd;
    fd = fopen ("variables.txt", "r");

    char varid[16];
    int val;
    for (int i = 0; i < 1; i++)
    {
        fscanf (fd, "%[^=]=%d", varid, &val);
        if ((strcmp (varid, varname) == 0))
        {
            return val;
        }
    }
}