#include "gtkfiledialog.hpp"
#include "gtk/gtk.h"
#include <cstring>
#include <iostream>

GtkFileDialog::GtkFileDialog()
{
    gtk_init(0, NULL);
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    
    dialog = gtk_file_chooser_dialog_new("Open File",
                                         NULL,
                                         action,
                                         "Cancel",
                                         GTK_RESPONSE_CANCEL,
                                         "Open",
                                         GTK_RESPONSE_ACCEPT,
                                         NULL);
    
    res = -1;
}

GtkFileDialog::~GtkFileDialog()
{
    gtk_widget_destroy(dialog);
    
    // TODO: get rid of this horrible hack (the dialog window doesn't close without it)
    for (int i = 0; i < 10; ++i)
    {
        gtk_main_iteration_do(false);
    }
}


void GtkFileDialog::show()
{
    res = gtk_dialog_run(GTK_DIALOG(dialog));
}

void GtkFileDialog::show(string path)
{
    GtkFileChooser* chooser = GTK_FILE_CHOOSER(dialog);
    gtk_file_chooser_set_current_folder_uri(chooser, ("file://" + path).c_str());
    show();
}

FileDialog::Response GtkFileDialog::getResponse()
{
    if (res == GTK_RESPONSE_ACCEPT)
    {
        return FileDialog::Response::Accept;
    }
    else
    {
        return FileDialog::Response::Cancel;
    }
}

bool GtkFileDialog::getFilename(string& filename)
{
    if (res == GTK_RESPONSE_ACCEPT)
    {
        char buf[1024];
        gchar* chooserfilename;
        
        GtkFileChooser* chooser = GTK_FILE_CHOOSER(dialog);
        chooserfilename = gtk_file_chooser_get_filename(chooser);
        
        strncpy(buf, chooserfilename, 1023);
        buf[1023] = 0;
        
        g_free(chooserfilename);
        
        filename.clear();
        filename.append(buf);
        
        return true;
    }
    else
    {
        return false;
    }
}
