#include "headers.h"

#include "bin/savedata.c"

#include "bin/retrievecontact.c"
#include "bin/variablesfetcher.c"
#include "bin/generatecache.c"
#include "bin/displaycontact.c"
#include "bin/addcontact.c"
#include "bin/removecontact.c"

#include "bin/addcontactfunc.c"
#include "bin/removecontactfunc.c"


#include "UI/ui.c"

int main ()
{
    generatecache ();
    saved = variablesfetcher ("saved");

    displaycontact ();
    
    //addcontact (addcontactfunc ());

    //removecontact (removecontactfunc ());

    appui (0, NULL);


    savedata ();
}