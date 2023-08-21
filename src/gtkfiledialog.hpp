#ifndef HAVE_GTKFILEDIALOG_H
#define HAVE_GTKFILEDIALOG_H

#include "filedialog.hpp"
#include "gtk/gtk.h"
#include <string>

using namespace std;

/**
 * GtkFileDialog - implementation of FileDialog using GTK3
 *
 */
class GtkFileDialog : public FileDialog
{
public:
    /**
     * Initialize a new GtkFileDialog
     */
    GtkFileDialog();
    ~GtkFileDialog();
    
    /**
     * Show the dialog using whatever path the dialog feels like
     */
    void show();
    
    /**
     * Show the dialog starting at a specific given path
     */
    void show(string path);
    
    /**
     * Response indicates whether the user clicked on "OK" or "Cancel"
     */
    FileDialog::Response getResponse();
    
    /**
     * If a file was selected and the user clicked on "OK", stores filename in parameter and returns True
     * otherwise, returns false
     */
    bool getFilename(string& filename);

private:
    GtkWidget* dialog;
    
    /**
     * Response from GTK ends up here
     */
    gint res;
};

#endif
