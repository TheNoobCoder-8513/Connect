#include <gtk/gtk.h>


typedef struct uiinfo
{
    GtkCssProvider *cssprovider;
    GdkDisplay *display;


    GtkWidget *mainwindow;
        GtkWidget *mainpane;
            GtkWidget *leftbox;
                GtkWidget *titlebox;
                    GtkWidget *titlelabel;
                    GtkWidget *addbutton;
                        GtkWidget *addbuttonimage;
                GtkWidget *contactlistdisplaybox;
                    GtkWidget *listbox;
            GtkWidget *rightbox;

                GtkWidget *displaypane;
                    GtkWidget *homepage;
                        GtkWidget *homeimg;

                    GtkWidget *addpage;
                        GtkEntryBuffer *nameentrydata;
                        GtkEntryBuffer *phonenumentrydata;
                        GtkEntryBuffer *altphonenumentrydata;
                        GtkEntryBuffer *dobentrydata;
                        GtkEntryBuffer *mailentrydata;
                        GtkEntryBuffer *addrentrydata;
                        GtkEntryBuffer *otherentrydata;

                        GtkWidget *savenewcontactbutton;


                    GtkWidget *detailbox;
                        GtkWidget *username;

                        GtkWidget *namedata;
                        GtkWidget *phonenumdata;
                        GtkWidget *altphonenumdata;
                        GtkWidget *dobdata;
                        GtkWidget *maildata;
                        GtkWidget *addrdata;
                        GtkWidget *otherdata;

                        GtkWidget *removecontact;

} uiinfo;
uiinfo uidata;

int contactindex = 0;
char buffer[150];


void activate (GtkApplication *app, void *data);
void buttonhandler (GtkWidget *button, void *data);
int addbuttonhandler (GtkWidget *button, void *data);
int savenewcontactbuttonfunc (GtkWidget *button, void *data);
int removecontactbuttonhandler (GtkWidget *button, int *index);


int generatelistdisplay ();
int infodisplaygenerator (GtkWidget **uiwidget, char str[]);
int addpageentrygenerator (GtkEntryBuffer **entrytext, char str[]);




int appui (int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("connect.contact", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    
    status = g_application_run (G_APPLICATION (app), argc, argv);

    g_object_unref (app);
    return status;
}

void activate (GtkApplication *app, void *data)
{
    uidata.cssprovider = gtk_css_provider_new ();
    uidata.display = gdk_display_get_default ();
    gtk_css_provider_load_from_path (uidata.cssprovider, "UI/stylesheet.css");
    gtk_style_context_add_provider_for_display (uidata.display, GTK_STYLE_PROVIDER (uidata.cssprovider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    

    uidata.mainwindow = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (uidata.mainwindow), "Connect");
    gtk_window_set_default_size (GTK_WINDOW (uidata.mainwindow), 800, 600);
    gtk_window_set_resizable (GTK_WINDOW (uidata.mainwindow), FALSE);


        uidata.mainpane = gtk_paned_new (GTK_ORIENTATION_HORIZONTAL);
        gtk_paned_set_position (GTK_PANED (uidata.mainpane), 300);
        gtk_paned_set_wide_handle (GTK_PANED (uidata.mainpane), TRUE);

            uidata.leftbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
            gtk_widget_add_css_class (uidata.leftbox, "leftbox");

                uidata.titlebox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
                gtk_widget_set_hexpand (uidata.titlebox, TRUE);
                gtk_widget_add_css_class (uidata.titlebox, "titlebox");

                    uidata.titlelabel = gtk_label_new ("Connect");
                    gtk_widget_set_hexpand (uidata.titlelabel, TRUE);
                    gtk_widget_set_halign (uidata.titlelabel, GTK_ALIGN_START);
                    gtk_widget_add_css_class (uidata.titlelabel, "titlelabel");
                    gtk_box_append (GTK_BOX (uidata.titlebox), uidata.titlelabel);

                    uidata.addbutton = gtk_button_new ();
                    gtk_widget_add_css_class (uidata.addbutton, "addbutton");
                    g_signal_connect (uidata.addbutton, "clicked", G_CALLBACK (addbuttonhandler), NULL);
                        
                        uidata.addbuttonimage = gtk_image_new_from_file ("resources/addbuttonimage.png");
                        gtk_image_set_pixel_size (GTK_IMAGE (uidata.addbuttonimage), 32);
                        gtk_button_set_child (GTK_BUTTON (uidata.addbutton), uidata.addbuttonimage);

                    gtk_box_append (GTK_BOX (uidata.titlebox), uidata.addbutton);

                gtk_box_append (GTK_BOX (uidata.leftbox), uidata.titlebox);

                // ---------------------------------------------------------- //

                uidata.contactlistdisplaybox = gtk_scrolled_window_new ();
                gtk_widget_set_vexpand (uidata.contactlistdisplaybox, TRUE);
                gtk_widget_set_hexpand (uidata.contactlistdisplaybox, TRUE);
                    

                    generatelistdisplay ();


                gtk_box_append (GTK_BOX (uidata.leftbox), uidata.contactlistdisplaybox);

            gtk_paned_set_start_child (GTK_PANED (uidata.mainpane), uidata.leftbox);


            
            uidata.rightbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

                uidata.displaypane = gtk_stack_new ();
                gtk_widget_add_css_class (uidata.displaypane, "homepage");


                // ---------------------- Home Page ------------------------------//

                    uidata.homepage = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
                    //gtk_widget_add_css_class (uidata.homepage, "homepage");
                    gtk_widget_set_hexpand (uidata.homepage, TRUE);
                    gtk_widget_set_vexpand (uidata.homepage, TRUE);
                        
                        uidata.homeimg = gtk_image_new_from_file ("resources/homeimage.png");
                        gtk_image_set_pixel_size (GTK_IMAGE (uidata.homeimg), 256);
                        gtk_widget_set_halign (uidata.homeimg, GTK_ALIGN_CENTER);
                        gtk_widget_set_valign (uidata.homeimg, GTK_ALIGN_CENTER);
                        gtk_widget_set_hexpand (uidata.homeimg, TRUE);
                        gtk_widget_set_vexpand (uidata.homeimg, TRUE);
                        gtk_box_append (GTK_BOX (uidata.homepage), uidata.homeimg);

                    gtk_stack_add_named (GTK_STACK (uidata.displaypane), uidata.homepage, "homepage");


                // ---------------------- Detail Page ----------------------------//
                
                    uidata.detailbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
                    gtk_widget_set_hexpand (uidata.detailbox, TRUE);
                    gtk_widget_set_vexpand (uidata.detailbox, TRUE);

                        GtkWidget *headerinfo;
                        headerinfo = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
                        gtk_widget_add_css_class (headerinfo, "headerinfo");

                            GtkWidget *userimage;
                            userimage = gtk_image_new ();
                            gtk_image_set_from_file (GTK_IMAGE (userimage), "resources/lookout.png");
                            gtk_image_set_pixel_size (GTK_IMAGE (userimage), 120);
                            gtk_widget_set_margin_start (userimage, 16);
                            gtk_box_append (GTK_BOX (headerinfo), userimage);

                            uidata.username = gtk_label_new ("");
                            gtk_widget_add_css_class (uidata.username, "headername");
                            gtk_box_append (GTK_BOX (headerinfo), uidata.username);

                        gtk_box_append (GTK_BOX (uidata.detailbox), headerinfo);

                        infodisplaygenerator (&uidata.namedata, "Full Name : ");
                        infodisplaygenerator (&uidata.phonenumdata, "Phone no. : ");
                        infodisplaygenerator (&uidata.altphonenumdata, "Alternative Phone no. : ");
                        infodisplaygenerator (&uidata.dobdata, "D.O.B. : ");
                        infodisplaygenerator (&uidata.maildata, "Mail ID : ");
                        infodisplaygenerator (&uidata.addrdata, "Address : ");
                        infodisplaygenerator (&uidata.otherdata, "Other Info : ");

                        uidata.removecontact = gtk_button_new_with_label ("Remove");
                        gtk_widget_add_css_class (uidata.removecontact, "removecontactbutton");
                        gtk_widget_set_hexpand (uidata.removecontact, TRUE);
                        gtk_widget_set_vexpand (uidata.removecontact, TRUE);
                        gtk_widget_set_halign (uidata.removecontact, GTK_ALIGN_END);
                        gtk_widget_set_valign (uidata.removecontact, GTK_ALIGN_END);
                        g_signal_connect (uidata.removecontact, "clicked", G_CALLBACK (removecontactbuttonhandler), &contactindex);
                        gtk_box_append (GTK_BOX (uidata.detailbox), uidata.removecontact);

                    gtk_stack_add_named (GTK_STACK (uidata.displaypane), uidata.detailbox, "detailpage");


                    // ------------------------------- ADD Contact Page ---------------------------- //

                    uidata.addpage = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);


                        GtkWidget *addpageheaderbox;
                        addpageheaderbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
                        gtk_widget_add_css_class (addpageheaderbox, "addcontactbox");

                            GtkWidget *addicon;
                            addicon = gtk_image_new_from_file ("resources/addicon.png");
                            gtk_image_set_pixel_size (GTK_IMAGE (addicon), 120);
                            gtk_box_append (GTK_BOX (addpageheaderbox), addicon);

                            GtkWidget *addcontactheadertitle;
                            addcontactheadertitle = gtk_label_new ("Add Contact");
                            gtk_widget_add_css_class (addcontactheadertitle, "addcontactheader");
                            gtk_widget_set_hexpand (addcontactheadertitle, TRUE);
                            gtk_widget_set_halign (addcontactheadertitle, GTK_ALIGN_END);
                            gtk_box_append (GTK_BOX (addpageheaderbox), addcontactheadertitle);

                        gtk_box_append (GTK_BOX (uidata.addpage), addpageheaderbox);


                        addpageentrygenerator (&uidata.nameentrydata, "Full Name : ");
                        addpageentrygenerator (&uidata.phonenumentrydata, "Phone no. : ");
                        addpageentrygenerator (&uidata.altphonenumentrydata, "Alternative Phone no. : ");
                        addpageentrygenerator (&uidata.dobentrydata, "D.O.B. : ");
                        addpageentrygenerator (&uidata.mailentrydata, "Mail ID : ");
                        addpageentrygenerator (&uidata.addrentrydata, "Address : ");
                        addpageentrygenerator (&uidata.otherentrydata, "Other Info : ");

                        uidata.savenewcontactbutton = gtk_button_new_with_label ("SAVE");
                        gtk_widget_add_css_class (uidata.savenewcontactbutton, "savenewcontactbutton");
                        gtk_widget_set_hexpand (uidata.savenewcontactbutton, TRUE);
                        gtk_widget_set_vexpand (uidata.savenewcontactbutton, TRUE);
                        gtk_widget_set_halign (uidata.savenewcontactbutton, GTK_ALIGN_END);
                        gtk_widget_set_valign (uidata.savenewcontactbutton, GTK_ALIGN_END);
                        g_signal_connect (uidata.savenewcontactbutton, "clicked", G_CALLBACK (savenewcontactbuttonfunc), NULL);
                        gtk_box_append (GTK_BOX (uidata.addpage), uidata.savenewcontactbutton);

                    gtk_stack_add_named (GTK_STACK (uidata.displaypane), uidata.addpage, "addpage");

                gtk_box_append (GTK_BOX (uidata.rightbox), uidata.displaypane);

            gtk_paned_set_end_child (GTK_PANED (uidata.mainpane), uidata.rightbox);
    
    gtk_window_set_child (GTK_WINDOW (uidata.mainwindow), uidata.mainpane);

    gtk_window_present (GTK_WINDOW (uidata.mainwindow));
}


int addpageentrygenerator (GtkEntryBuffer **entrytext, char str[])
{
    GtkWidget *addinfobox;
    addinfobox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_add_css_class (addinfobox, "addinfobox");

        GtkWidget *entrylabel;
        entrylabel = gtk_label_new (str);
        gtk_widget_add_css_class (entrylabel, "entrylabel");
        gtk_box_append (GTK_BOX (addinfobox), entrylabel);

        GtkWidget *entrywidget;
        *entrytext = gtk_entry_buffer_new (NULL, -1);
        entrywidget = gtk_entry_new_with_buffer (*entrytext);
        gtk_widget_set_hexpand (entrywidget, TRUE);
        gtk_widget_set_halign (entrywidget, GTK_ALIGN_END);
        gtk_widget_add_css_class (entrywidget, "entrywidget");
        gtk_box_append (GTK_BOX (addinfobox), entrywidget);

    gtk_box_append (GTK_BOX (uidata.addpage), addinfobox);
}


int generatelistdisplay ()
{

    
    uidata.listbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_add_css_class (uidata.listbox, "listbox");

        FILE *fr;
        fr = fopen ("data/contactlistcache.txt", "r");


        for (int i = 0; i < saved; i++)
        {
            char contactname[26];
            fscanf (fr, "%26[^;]%[^\n]\n", contactname, buffer);

            GtkWidget *contactbutton;
            contactbutton = gtk_button_new ();
            gtk_widget_set_name (contactbutton, contactname);
            g_signal_connect (contactbutton, "clicked", G_CALLBACK (buttonhandler), NULL);
            gtk_widget_add_css_class (contactbutton, "contactbutton");

                GtkWidget *contactbox;
                contactbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
                gtk_widget_set_hexpand (contactbox, TRUE);

                    GtkWidget *contactimage;
                    contactimage = gtk_image_new ();
                    gtk_image_set_from_file (GTK_IMAGE (contactimage), "resources/user.png");
                    gtk_image_set_pixel_size (GTK_IMAGE (contactimage), 24);
                    gtk_box_append (GTK_BOX (contactbox), contactimage);

                    GtkWidget *contacttitle;
                    contacttitle = gtk_label_new (contactname);
                    gtk_widget_add_css_class (contacttitle, "contacttitle");
                    gtk_box_append (GTK_BOX (contactbox), contacttitle);

                gtk_button_set_child (GTK_BUTTON (contactbutton), contactbox);

            gtk_box_append (GTK_BOX (uidata.listbox), contactbutton);
            
        }

        fclose (fr);

    gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (uidata.contactlistdisplaybox), uidata.listbox);

}


int infodisplaygenerator (GtkWidget **uiwidget, char str[])
{
    GtkWidget *infobox;
    infobox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_add_css_class (infobox, "infobox");

        GtkWidget *infolabel;
        infolabel = gtk_label_new (str);
        gtk_widget_add_css_class (infolabel, "infolabel");
        gtk_box_append (GTK_BOX (infobox), infolabel);

        *uiwidget = gtk_label_new (NULL);
        gtk_label_set_wrap (GTK_LABEL (*uiwidget), TRUE);
        gtk_label_set_lines (GTK_LABEL (*uiwidget), 5);
        gtk_widget_add_css_class (*uiwidget, "infodata");
        gtk_box_append (GTK_BOX (infobox), *uiwidget);

    gtk_box_append (GTK_BOX (uidata.detailbox), infobox);
}


void buttonhandler (GtkWidget *button, void *data)
{
    char string[26];
    strcpy (string, gtk_widget_get_name (button));

    FILE *fd;
    fd = fopen ("data/contactlistcache.txt", "r");

    contactindex = 1;

    for (int i = 0; i < saved; i++)
    {
        fscanf (fd, "%[^;];", info[0].name);
        
        if (strcmp (string, info[0].name) == 0)
        {
            fscanf (fd, 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
            info[0].phonenum,
            info[0].altphonenum,
            info[0].dob,
            info[0].mail,
            info[0].address,
            info[0].other
            );


            char firstname[26] = {'\0'};
            for (int i = 0; i < strlen (info[0].name); i++)
            {
                if (info[0].name[i] == ' ') break;
                firstname[i] = info[0].name[i];
            }

            gtk_label_set_text (GTK_LABEL (uidata.username), firstname);
            gtk_label_set_text (GTK_LABEL (uidata.namedata), info[0].name);
            gtk_label_set_text (GTK_LABEL (uidata.phonenumdata), info[0].phonenum);
            gtk_label_set_text (GTK_LABEL (uidata.altphonenumdata), info[0].altphonenum);
            gtk_label_set_text (GTK_LABEL (uidata.dobdata), info[0].dob);
            gtk_label_set_text (GTK_LABEL (uidata.maildata), info[0].mail);
            gtk_label_set_text (GTK_LABEL (uidata.addrdata), info[0].address);
            gtk_label_set_text (GTK_LABEL (uidata.otherdata), info[0].other);

            
            fclose (fd);
            gtk_stack_set_visible_child_name (GTK_STACK (uidata.displaypane), "detailpage");
            printf ("%d\n", contactindex);
            return;
        }
        else
        {
            fscanf (fd, "%[^\n]\n", buffer);
        }

        contactindex++;

    }
    

    fclose (fd);
}

int addbuttonhandler (GtkWidget *button, void *data)
{
    /*
    GtkWidget *addcontactwindow;
    addcontactwindow = gtk_window_new ();
    gtk_window_set_title (GTK_WINDOW (addcontactwindow), "Add Contact");
    gtk_window_set_default_size (GTK_WINDOW (addcontactwindow), 400, 400);

        GtkWidget *addcontactbox;
        addcontactbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

            

        gtk_window_set_child (GTK_WINDOW (addcontactwindow), addcontactbox);

    gtk_window_present (GTK_WINDOW (addcontactwindow));
    */

   gtk_stack_set_visible_child_name (GTK_STACK (uidata.displaypane), "addpage");
}

int savenewcontactbuttonfunc (GtkWidget *button, void *data)
{
    contact details;

    strcpy (details.name, gtk_entry_buffer_get_text (uidata.nameentrydata));
    strcpy (details.phonenum, gtk_entry_buffer_get_text (uidata.phonenumentrydata));
    strcpy (details.altphonenum, gtk_entry_buffer_get_text (uidata.altphonenumentrydata));
    strcpy (details.dob, gtk_entry_buffer_get_text (uidata.dobentrydata));
    strcpy (details.mail, gtk_entry_buffer_get_text (uidata.mailentrydata));
    strcpy (details.address, gtk_entry_buffer_get_text (uidata.addrentrydata));
    strcpy (details.other, gtk_entry_buffer_get_text (uidata.otherentrydata));

    addcontact(details);
    gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (uidata.contactlistdisplaybox), NULL);
    generatelistdisplay ();
}

int removecontactbuttonhandler (GtkWidget *button, int *index)
{
    FILE *fdr;
    FILE *fdw;

    fdr = fopen ("data/contactlistcache.txt", "r");
    fdw = fopen ("data/contactlist.txt", "w");

    
    char reader;
    int currindex = 1;

    reader = fgetc (fdr);
    if (reader == '\n') (*index)++;

    while (!(feof (fdr)))
    {
        if (currindex != (*index)) fputc (reader, fdw);
        reader = fgetc (fdr);
        if (reader == '\n') currindex++;
    }

    fclose (fdr);
    fclose (fdw);

    saved--;
    generatecache ();

    savedata ();

    gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (uidata.contactlistdisplaybox), NULL);
    generatelistdisplay ();
}