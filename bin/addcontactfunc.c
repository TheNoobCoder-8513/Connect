contact addcontactfunc ()
{
    contact details;

    printf ("\n\n-------------- Add Contact -------------\n\n");

    printf ("Enter following details: \n");

    printf ("Enter Name: ");
    scanf ("%25[^\n]", details.name);
    getchar ();

    printf ("Enter Phone number: ");
    scanf ("%10[^\n]", details.phonenum);
    getchar ();

    printf ("Enter Alternate Phone number: ");
    scanf ("%10[^\n]", details.altphonenum);
    getchar ();

    printf ("Enter D.O.B: ");
    scanf ("%10[^\n]", details.dob);
    getchar ();

    printf ("Enter Mail ID: ");
    scanf ("%35[^\n]", details.mail);
    getchar ();

    printf ("Enter Address: ");
    scanf ("%50[^\n]", details.address);
    getchar ();

    printf ("Enter Other info: ");
    scanf ("%25[^\n]", details.other);
    getchar ();

    printf ("\n----------------------------------------\n");

    return details;
}