int removecontactfunc ()
{
    int index;
    printf ("\n\n--------------- Remove Contact -------------\n\n");
    
    displaycontact ();
    
    printf ("Enter Contact Index to remove: ");
    scanf ("%d", &index);
    return index;
}