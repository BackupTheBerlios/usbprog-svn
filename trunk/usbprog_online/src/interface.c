/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_mainwindow (void)
{
  GtkWidget *mainwindow;
  GtkWidget *mainframe;
  GtkWidget *alignment1;
  GtkWidget *vbox1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *vbox2;
  GtkWidget *hbox2;
  GtkWidget *labelport;
  GtkWidget *hbox6;
  GtkWidget *label8;
  GtkWidget *entry2;
  GtkWidget *label9;
  GtkWidget *entry3;
  GtkWidget *hbox3;
  GtkWidget *label4;
  GtkWidget *hbox7;
  GtkWidget *entry4;
  GtkWidget *fixed1;
  GtkWidget *button1;
  GtkWidget *hbox4;
  GtkWidget *label7;
  GtkWidget *vbox3;
  GtkWidget *combo1;
  GtkWidget *combo_entry1;
  GtkWidget *hbox5;
  GtkWidget *label6;
  GtkWidget *hbox8;
  GtkWidget *entry5;
  GtkWidget *fixed2;
  GtkWidget *button2;
  GtkWidget *progressbar1;
  GtkWidget *hbuttonbox1;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *entry6;
  GtkWidget *footer;
  GtkWidget *label1;

  mainwindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (mainwindow), _("usbprog Online"));

  mainframe = gtk_frame_new (NULL);
  gtk_widget_show (mainframe);
  gtk_container_add (GTK_CONTAINER (mainwindow), mainframe);
  gtk_container_set_border_width (GTK_CONTAINER (mainframe), 7);
  gtk_frame_set_shadow_type (GTK_FRAME (mainframe), GTK_SHADOW_IN);

  alignment1 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (mainframe), alignment1);
  gtk_container_set_border_width (GTK_CONTAINER (alignment1), 12);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment1), 0, 0, 12, 0);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), vbox1);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, TRUE, TRUE, 0);

  image1 = create_pixmap (mainwindow, "usbprog.jpg");
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, TRUE, TRUE, 11);

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox2);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox2, TRUE, TRUE, 0);

  hbox2 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox2);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox2, TRUE, TRUE, 0);

  labelport = gtk_label_new (_("Port"));
  gtk_widget_show (labelport);
  gtk_box_pack_start (GTK_BOX (hbox2), labelport, FALSE, FALSE, 0);
  gtk_widget_set_size_request (labelport, 70, -1);
  gtk_label_set_line_wrap (GTK_LABEL (labelport), TRUE);
  gtk_misc_set_padding (GTK_MISC (labelport), 3, 0);

  hbox6 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox6);
  gtk_box_pack_start (GTK_BOX (hbox2), hbox6, FALSE, FALSE, 0);

  label8 = gtk_label_new (_("VID "));
  gtk_widget_show (label8);
  gtk_box_pack_start (GTK_BOX (hbox6), label8, FALSE, FALSE, 0);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_box_pack_start (GTK_BOX (hbox6), entry2, TRUE, TRUE, 0);
  gtk_widget_set_size_request (entry2, 40, -1);

  label9 = gtk_label_new (_("PID"));
  gtk_widget_show (label9);
  gtk_box_pack_start (GTK_BOX (hbox6), label9, FALSE, FALSE, 0);
  gtk_misc_set_padding (GTK_MISC (label9), 2, 0);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_box_pack_start (GTK_BOX (hbox6), entry3, TRUE, TRUE, 0);
  gtk_widget_set_size_request (entry3, 40, -1);

  hbox3 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox3);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox3, TRUE, TRUE, 0);

  label4 = gtk_label_new (_("URL"));
  gtk_widget_show (label4);
  gtk_box_pack_start (GTK_BOX (hbox3), label4, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label4, 70, -1);
  gtk_label_set_line_wrap (GTK_LABEL (label4), TRUE);
  gtk_misc_set_padding (GTK_MISC (label4), 3, 0);

  hbox7 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox7);
  gtk_box_pack_start (GTK_BOX (hbox3), hbox7, TRUE, TRUE, 0);

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_box_pack_start (GTK_BOX (hbox7), entry4, FALSE, FALSE, 0);
  gtk_entry_set_text (GTK_ENTRY (entry4), _("http://www.ixbat.de/usbprog/versions.conf"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_box_pack_end (GTK_BOX (hbox7), fixed1, FALSE, FALSE, 0);

  button1 = gtk_button_new_with_mnemonic (_("Download"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 0, 8);
  gtk_widget_set_size_request (button1, 76, 29);

  hbox4 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox4);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox4, TRUE, TRUE, 0);

  label7 = gtk_label_new (_("Online"));
  gtk_widget_show (label7);
  gtk_box_pack_start (GTK_BOX (hbox4), label7, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label7, 70, -1);
  gtk_label_set_line_wrap (GTK_LABEL (label7), TRUE);
  gtk_misc_set_padding (GTK_MISC (label7), 3, 0);

  vbox3 = gtk_vbox_new (TRUE, 0);
  gtk_widget_show (vbox3);
  gtk_box_pack_start (GTK_BOX (hbox4), vbox3, FALSE, FALSE, 0);

  combo1 = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO (combo1)->popwin),
                     "GladeParentKey", combo1);
  gtk_widget_show (combo1);
  gtk_box_pack_start (GTK_BOX (vbox3), combo1, FALSE, FALSE, 0);

  combo_entry1 = GTK_COMBO (combo1)->entry;
  gtk_widget_show (combo_entry1);
  gtk_entry_set_text (GTK_ENTRY (combo_entry1), _("001_blink_demo"));

  hbox5 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox5);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox5, TRUE, TRUE, 0);

  label6 = gtk_label_new (_("Custom"));
  gtk_widget_show (label6);
  gtk_box_pack_start (GTK_BOX (hbox5), label6, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label6, 70, -1);
  gtk_label_set_line_wrap (GTK_LABEL (label6), TRUE);
  gtk_misc_set_padding (GTK_MISC (label6), 3, 0);

  hbox8 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox8);
  gtk_box_pack_start (GTK_BOX (hbox5), hbox8, TRUE, TRUE, 0);

  entry5 = gtk_entry_new ();
  gtk_widget_show (entry5);
  gtk_box_pack_start (GTK_BOX (hbox8), entry5, FALSE, FALSE, 0);

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_box_pack_end (GTK_BOX (hbox8), fixed2, FALSE, FALSE, 0);

  button2 = gtk_button_new_with_mnemonic (_("Browse ..."));
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed2), button2, 0, 8);
  gtk_widget_set_size_request (button2, 76, 29);

  progressbar1 = gtk_progress_bar_new ();
  gtk_widget_show (progressbar1);
  gtk_box_pack_start (GTK_BOX (vbox2), progressbar1, FALSE, FALSE, 0);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (vbox2), hbuttonbox1, TRUE, TRUE, 0);

  button3 = gtk_button_new_with_mnemonic (_("Cancel"));
  gtk_widget_show (button3);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button3);
  GTK_WIDGET_SET_FLAGS (button3, GTK_CAN_DEFAULT);

  button4 = gtk_button_new_with_mnemonic (_("Quit"));
  gtk_widget_show (button4);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button4);
  GTK_WIDGET_SET_FLAGS (button4, GTK_CAN_DEFAULT);

  button5 = gtk_button_new_with_mnemonic (_("OK"));
  gtk_widget_show (button5);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), button5);
  GTK_WIDGET_SET_FLAGS (button5, GTK_CAN_DEFAULT);

  entry6 = gtk_entry_new ();
  gtk_widget_show (entry6);
  gtk_box_pack_start (GTK_BOX (vbox2), entry6, TRUE, FALSE, 0);

  footer = gtk_label_new (_("Created by Benedikt Sauter (sauter@ixbat.de)\nhttp://www.embedded-projects.net/usbprog"));
  gtk_widget_show (footer);
  gtk_box_pack_start (GTK_BOX (vbox1), footer, FALSE, FALSE, 0);

  label1 = gtk_label_new (_("<b>usbprog Online Programmer v 0.1</b>"));
  gtk_widget_show (label1);
  gtk_frame_set_label_widget (GTK_FRAME (mainframe), label1);
  gtk_label_set_use_markup (GTK_LABEL (label1), TRUE);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (mainwindow, mainwindow, "mainwindow");
  GLADE_HOOKUP_OBJECT (mainwindow, mainframe, "mainframe");
  GLADE_HOOKUP_OBJECT (mainwindow, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (mainwindow, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (mainwindow, image1, "image1");
  GLADE_HOOKUP_OBJECT (mainwindow, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (mainwindow, labelport, "labelport");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (mainwindow, label8, "label8");
  GLADE_HOOKUP_OBJECT (mainwindow, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (mainwindow, label9, "label9");
  GLADE_HOOKUP_OBJECT (mainwindow, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (mainwindow, label4, "label4");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (mainwindow, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (mainwindow, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (mainwindow, button1, "button1");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (mainwindow, label7, "label7");
  GLADE_HOOKUP_OBJECT (mainwindow, vbox3, "vbox3");
  GLADE_HOOKUP_OBJECT (mainwindow, combo1, "combo1");
  GLADE_HOOKUP_OBJECT (mainwindow, combo_entry1, "combo_entry1");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (mainwindow, label6, "label6");
  GLADE_HOOKUP_OBJECT (mainwindow, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (mainwindow, entry5, "entry5");
  GLADE_HOOKUP_OBJECT (mainwindow, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (mainwindow, button2, "button2");
  GLADE_HOOKUP_OBJECT (mainwindow, progressbar1, "progressbar1");
  GLADE_HOOKUP_OBJECT (mainwindow, hbuttonbox1, "hbuttonbox1");
  GLADE_HOOKUP_OBJECT (mainwindow, button3, "button3");
  GLADE_HOOKUP_OBJECT (mainwindow, button4, "button4");
  GLADE_HOOKUP_OBJECT (mainwindow, button5, "button5");
  GLADE_HOOKUP_OBJECT (mainwindow, entry6, "entry6");
  GLADE_HOOKUP_OBJECT (mainwindow, footer, "footer");
  GLADE_HOOKUP_OBJECT (mainwindow, label1, "label1");

  return mainwindow;
}

GtkWidget*
create_fileselection (void)
{
  GtkWidget *fileselection;
  GtkWidget *ok_button1;
  GtkWidget *cancel_button1;

  fileselection = gtk_file_selection_new (_("Select File"));
  gtk_container_set_border_width (GTK_CONTAINER (fileselection), 10);
  gtk_window_set_type_hint (GTK_WINDOW (fileselection), GDK_WINDOW_TYPE_HINT_DIALOG);

  ok_button1 = GTK_FILE_SELECTION (fileselection)->ok_button;
  gtk_widget_show (ok_button1);
  GTK_WIDGET_SET_FLAGS (ok_button1, GTK_CAN_DEFAULT);

  cancel_button1 = GTK_FILE_SELECTION (fileselection)->cancel_button;
  gtk_widget_show (cancel_button1);
  GTK_WIDGET_SET_FLAGS (cancel_button1, GTK_CAN_DEFAULT);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (fileselection, fileselection, "fileselection");
  GLADE_HOOKUP_OBJECT_NO_REF (fileselection, ok_button1, "ok_button1");
  GLADE_HOOKUP_OBJECT_NO_REF (fileselection, cancel_button1, "cancel_button1");

  return fileselection;
}

