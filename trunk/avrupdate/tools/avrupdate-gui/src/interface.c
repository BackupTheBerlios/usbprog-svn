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
create_window (void)
{
  GtkWidget *window;
  GtkWidget *hbox1;
  GtkWidget *vbox1;
  GtkWidget *frame1;
  GtkWidget *alignment1;
  GtkWidget *vbox3;
  GtkWidget *vbox6;
  GtkWidget *hbox12;
  GtkWidget *label25;
  GtkWidget *hbox11;
  GtkWidget *hbox19;
  GtkWidget *label28;
  GtkWidget *entryVID;
  GtkWidget *label29;
  GtkWidget *entryPID;
  GtkWidget *hbox16;
  GtkWidget *hbox20;
  GtkWidget *label31;
  GtkWidget *hbox15;
  GtkWidget *hbox21;
  GtkWidget *label32;
  GtkWidget *entryVIDa;
  GtkWidget *label33;
  GtkWidget *entryPIDa;
  GtkWidget *hbox14;
  GtkWidget *hbox22;
  GtkWidget *hseparator3;
  GtkWidget *hbox13;
  GtkWidget *label30;
  GtkWidget *entryFile;
  GtkWidget *hbox17;
  GtkWidget *hbox23;
  GtkWidget *hseparator4;
  GtkWidget *hbox10;
  GtkWidget *label18;
  GtkWidget *fixed1;
  GtkWidget *label21;
  GtkWidget *label20;
  GtkWidget *label19;
  GtkWidget *labelTitle;
  GtkWidget *labelSize;
  GtkWidget *labelVersion;
  GtkWidget *hbox24;
  GtkWidget *hseparator5;
  GtkWidget *vbuttonbox2;
  GtkWidget *buttonVersion;
  GtkWidget *buttonQuick;
  GtkWidget *buttonStartAU;
  GtkWidget *hbox25;
  GtkWidget *hseparator6;
  GtkWidget *hbox18;
  GtkWidget *label27;
  GtkWidget *label1;
  GtkWidget *frame3;
  GtkWidget *alignment3;
  GtkWidget *vbox2;
  GtkWidget *hbox4;
  GtkWidget *label15;
  GtkWidget *listVersions;
  GtkWidget *treeviewVersions;
  GtkWidget *hbox7;
  GtkWidget *label16;
  GtkWidget *scrolledwindow5;
  GtkWidget *textviewLog;
  GtkWidget *hbox8;
  GtkWidget *label17;
  GtkWidget *hbox3;
  GtkWidget *buttonDownload;
  GtkWidget *buttonFLash;
  GtkWidget *buttonStart;
  GtkWidget *label3;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), _("avrupdate - AVR Online Update"));
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (window), hbox1);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox1, TRUE, TRUE, 0);

  frame1 = gtk_frame_new (NULL);
  gtk_widget_show (frame1);
  gtk_box_pack_start (GTK_BOX (vbox1), frame1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame1), 3);
  gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_OUT);

  alignment1 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (frame1), alignment1);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment1), 10, 10, 10, 10);

  vbox3 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox3);
  gtk_container_add (GTK_CONTAINER (alignment1), vbox3);

  vbox6 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox6);
  gtk_box_pack_start (GTK_BOX (vbox3), vbox6, TRUE, TRUE, 0);

  hbox12 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox12);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox12, FALSE, FALSE, 0);

  label25 = gtk_label_new (_("<b>USB Device IDs:</b>"));
  gtk_widget_show (label25);
  gtk_box_pack_start (GTK_BOX (hbox12), label25, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label25), TRUE);

  hbox11 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox11);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox11, TRUE, TRUE, 0);

  hbox19 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox19);
  gtk_box_pack_start (GTK_BOX (hbox11), hbox19, TRUE, TRUE, 0);

  label28 = gtk_label_new (_("Vendor ID: "));
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (hbox19), label28, FALSE, FALSE, 0);

  entryVID = gtk_entry_new ();
  gtk_widget_show (entryVID);
  gtk_box_pack_start (GTK_BOX (hbox19), entryVID, TRUE, TRUE, 0);
  gtk_widget_set_size_request (entryVID, 40, -1);

  label29 = gtk_label_new (_("       Product ID: "));
  gtk_widget_show (label29);
  gtk_box_pack_start (GTK_BOX (hbox19), label29, FALSE, FALSE, 0);

  entryPID = gtk_entry_new ();
  gtk_widget_show (entryPID);
  gtk_box_pack_start (GTK_BOX (hbox19), entryPID, TRUE, TRUE, 0);
  gtk_widget_set_size_request (entryPID, 40, -1);

  hbox16 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox16);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox16, TRUE, TRUE, 0);

  hbox20 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox20);
  gtk_box_pack_start (GTK_BOX (hbox16), hbox20, TRUE, TRUE, 0);

  label31 = gtk_label_new (_("<b>USB avrupdate IDs:</b>"));
  gtk_widget_show (label31);
  gtk_box_pack_start (GTK_BOX (hbox20), label31, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label31), TRUE);

  hbox15 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox15);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox15, TRUE, TRUE, 0);

  hbox21 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox21);
  gtk_box_pack_start (GTK_BOX (hbox15), hbox21, TRUE, TRUE, 0);

  label32 = gtk_label_new (_("Vendor ID: "));
  gtk_widget_show (label32);
  gtk_box_pack_start (GTK_BOX (hbox21), label32, FALSE, FALSE, 0);

  entryVIDa = gtk_entry_new ();
  gtk_widget_show (entryVIDa);
  gtk_box_pack_start (GTK_BOX (hbox21), entryVIDa, TRUE, TRUE, 0);
  gtk_widget_set_size_request (entryVIDa, 40, -1);

  label33 = gtk_label_new (_("       Product ID: "));
  gtk_widget_show (label33);
  gtk_box_pack_start (GTK_BOX (hbox21), label33, FALSE, FALSE, 0);

  entryPIDa = gtk_entry_new ();
  gtk_widget_show (entryPIDa);
  gtk_box_pack_start (GTK_BOX (hbox21), entryPIDa, TRUE, TRUE, 0);
  gtk_widget_set_size_request (entryPIDa, 40, -1);

  hbox14 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox14);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox14, TRUE, TRUE, 0);

  hbox22 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox22);
  gtk_box_pack_start (GTK_BOX (hbox14), hbox22, TRUE, TRUE, 0);

  hseparator3 = gtk_hseparator_new ();
  gtk_widget_show (hseparator3);
  gtk_box_pack_start (GTK_BOX (hbox22), hseparator3, TRUE, TRUE, 0);

  hbox13 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox13);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox13, FALSE, TRUE, 0);

  label30 = gtk_label_new (_("<b>Version File</b> (http://www../version.conf)<b>:</b>"));
  gtk_widget_show (label30);
  gtk_box_pack_start (GTK_BOX (hbox13), label30, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label30), TRUE);

  entryFile = gtk_entry_new ();
  gtk_widget_show (entryFile);
  gtk_box_pack_start (GTK_BOX (vbox6), entryFile, FALSE, FALSE, 0);

  hbox17 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox17);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox17, TRUE, TRUE, 0);

  hbox23 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox23);
  gtk_box_pack_start (GTK_BOX (hbox17), hbox23, TRUE, TRUE, 0);

  hseparator4 = gtk_hseparator_new ();
  gtk_widget_show (hseparator4);
  gtk_box_pack_start (GTK_BOX (hbox23), hseparator4, TRUE, TRUE, 0);

  hbox10 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox10);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox10, FALSE, TRUE, 0);

  label18 = gtk_label_new (_("<b>Application Info:</b>"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox10), label18, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label18), TRUE);

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_box_pack_start (GTK_BOX (vbox6), fixed1, TRUE, TRUE, 0);

  label21 = gtk_label_new (_("Title:"));
  gtk_widget_show (label21);
  gtk_fixed_put (GTK_FIXED (fixed1), label21, 32, 24);
  gtk_widget_set_size_request (label21, 48, 17);

  label20 = gtk_label_new (_("Size:"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed1), label20, 24, 40);
  gtk_widget_set_size_request (label20, 62, 16);

  label19 = gtk_label_new (_("Version:"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed1), label19, 40, 56);
  gtk_widget_set_size_request (label19, 56, 16);

  labelTitle = gtk_label_new (_("usbprog"));
  gtk_widget_show (labelTitle);
  gtk_fixed_put (GTK_FIXED (fixed1), labelTitle, 88, 24);
  gtk_widget_set_size_request (labelTitle, 88, 17);

  labelSize = gtk_label_new (_("21234 Byte"));
  gtk_widget_show (labelSize);
  gtk_fixed_put (GTK_FIXED (fixed1), labelSize, 88, 40);
  gtk_widget_set_size_request (labelSize, 112, 16);

  labelVersion = gtk_label_new (_("9"));
  gtk_widget_show (labelVersion);
  gtk_fixed_put (GTK_FIXED (fixed1), labelVersion, 88, 56);
  gtk_widget_set_size_request (labelVersion, 46, 17);

  hbox24 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox24);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox24, TRUE, TRUE, 0);

  hseparator5 = gtk_hseparator_new ();
  gtk_widget_show (hseparator5);
  gtk_box_pack_start (GTK_BOX (hbox24), hseparator5, TRUE, TRUE, 0);

  vbuttonbox2 = gtk_vbutton_box_new ();
  gtk_widget_show (vbuttonbox2);
  gtk_box_pack_start (GTK_BOX (vbox6), vbuttonbox2, TRUE, TRUE, 0);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (vbuttonbox2), GTK_BUTTONBOX_SPREAD);

  buttonVersion = gtk_button_new_with_mnemonic (_("Read AVR Version"));
  gtk_widget_show (buttonVersion);
  gtk_container_add (GTK_CONTAINER (vbuttonbox2), buttonVersion);
  GTK_WIDGET_SET_FLAGS (buttonVersion, GTK_CAN_DEFAULT);

  buttonQuick = gtk_button_new_with_mnemonic (_("Quick Auto Update"));
  gtk_widget_show (buttonQuick);
  gtk_container_add (GTK_CONTAINER (vbuttonbox2), buttonQuick);
  GTK_WIDGET_SET_FLAGS (buttonQuick, GTK_CAN_DEFAULT);

  buttonStartAU = gtk_button_new_with_mnemonic (_("Start Update Mode (with Vendor Request)"));
  gtk_widget_show (buttonStartAU);
  gtk_container_add (GTK_CONTAINER (vbuttonbox2), buttonStartAU);
  GTK_WIDGET_SET_FLAGS (buttonStartAU, GTK_CAN_DEFAULT);

  hbox25 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox25);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox25, TRUE, TRUE, 0);

  hseparator6 = gtk_hseparator_new ();
  gtk_widget_show (hseparator6);
  gtk_box_pack_start (GTK_BOX (hbox25), hseparator6, TRUE, TRUE, 0);

  hbox18 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox18);
  gtk_box_pack_start (GTK_BOX (vbox6), hbox18, TRUE, TRUE, 0);

  label27 = gtk_label_new (_("Author: Benedikt Sauter <sauter@ixbat.de>\nHomepage: http://www.ixbat.de"));
  gtk_widget_show (label27);
  gtk_box_pack_start (GTK_BOX (hbox18), label27, FALSE, FALSE, 0);

  label1 = gtk_label_new (_("AVR Board"));
  gtk_widget_show (label1);
  gtk_frame_set_label_widget (GTK_FRAME (frame1), label1);

  frame3 = gtk_frame_new (NULL);
  gtk_widget_show (frame3);
  gtk_box_pack_start (GTK_BOX (hbox1), frame3, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame3), 3);
  gtk_frame_set_shadow_type (GTK_FRAME (frame3), GTK_SHADOW_OUT);

  alignment3 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (frame3), alignment3);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment3), 10, 10, 10, 10);

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox2);
  gtk_container_add (GTK_CONTAINER (alignment3), vbox2);

  hbox4 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox4);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox4, FALSE, TRUE, 0);

  label15 = gtk_label_new (_("<b>Online:</b>"));
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (hbox4), label15, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label15), TRUE);

  listVersions = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (listVersions);
  gtk_box_pack_start (GTK_BOX (vbox2), listVersions, TRUE, TRUE, 1);
  gtk_widget_set_size_request (listVersions, -1, 173);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (listVersions), GTK_SHADOW_IN);

  treeviewVersions = gtk_tree_view_new ();
  gtk_widget_show (treeviewVersions);
  gtk_container_add (GTK_CONTAINER (listVersions), treeviewVersions);
  gtk_tree_view_set_hover_expand (GTK_TREE_VIEW (treeviewVersions), TRUE);

  hbox7 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox7);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox7, FALSE, FALSE, 0);

  label16 = gtk_label_new (_("<b>Log:</b>"));
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox7), label16, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label16), TRUE);

  scrolledwindow5 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow5);
  gtk_box_pack_start (GTK_BOX (vbox2), scrolledwindow5, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_SHADOW_IN);

  textviewLog = gtk_text_view_new ();
  gtk_widget_show (textviewLog);
  gtk_container_add (GTK_CONTAINER (scrolledwindow5), textviewLog);
  gtk_widget_set_size_request (textviewLog, -1, 116);

  hbox8 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox8);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox8, TRUE, TRUE, 0);

  label17 = gtk_label_new (_("<b>Process:</b>"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox8), label17, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label17), TRUE);

  hbox3 = gtk_hbox_new (TRUE, 0);
  gtk_widget_show (hbox3);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox3, FALSE, TRUE, 0);

  buttonDownload = gtk_button_new_with_mnemonic (_("Download Version List"));
  gtk_widget_show (buttonDownload);
  gtk_box_pack_start (GTK_BOX (hbox3), buttonDownload, FALSE, FALSE, 0);

  buttonFLash = gtk_button_new_with_mnemonic (_("Flash selected File"));
  gtk_widget_show (buttonFLash);
  gtk_box_pack_start (GTK_BOX (hbox3), buttonFLash, FALSE, FALSE, 0);

  buttonStart = gtk_button_new_with_mnemonic (_("Start Application"));
  gtk_widget_show (buttonStart);
  gtk_box_pack_start (GTK_BOX (hbox3), buttonStart, FALSE, FALSE, 0);

  label3 = gtk_label_new (_("Online Versions"));
  gtk_widget_show (label3);
  gtk_frame_set_label_widget (GTK_FRAME (frame3), label3);

  g_signal_connect ((gpointer) buttonVersion, "clicked",
                    G_CALLBACK (on_buttonVersion_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonQuick, "clicked",
                    G_CALLBACK (on_buttonQuick_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonStartAU, "clicked",
                    G_CALLBACK (on_buttonStartAU_clicked),
                    NULL);
  g_signal_connect ((gpointer) treeviewVersions, "cursor_changed",
                    G_CALLBACK (on_treeviewVersions_cursor_changed),
                    NULL);
  g_signal_connect ((gpointer) treeviewVersions, "row_activated",
                    G_CALLBACK (on_treeviewVersions_row_activated),
                    NULL);
  g_signal_connect ((gpointer) buttonDownload, "clicked",
                    G_CALLBACK (on_buttonDownload_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonFLash, "clicked",
                    G_CALLBACK (on_buttonFLash_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonStart, "clicked",
                    G_CALLBACK (on_buttonStart_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window, window, "window");
  GLADE_HOOKUP_OBJECT (window, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (window, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (window, frame1, "frame1");
  GLADE_HOOKUP_OBJECT (window, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (window, vbox3, "vbox3");
  GLADE_HOOKUP_OBJECT (window, vbox6, "vbox6");
  GLADE_HOOKUP_OBJECT (window, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (window, label25, "label25");
  GLADE_HOOKUP_OBJECT (window, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (window, hbox19, "hbox19");
  GLADE_HOOKUP_OBJECT (window, label28, "label28");
  GLADE_HOOKUP_OBJECT (window, entryVID, "entryVID");
  GLADE_HOOKUP_OBJECT (window, label29, "label29");
  GLADE_HOOKUP_OBJECT (window, entryPID, "entryPID");
  GLADE_HOOKUP_OBJECT (window, hbox16, "hbox16");
  GLADE_HOOKUP_OBJECT (window, hbox20, "hbox20");
  GLADE_HOOKUP_OBJECT (window, label31, "label31");
  GLADE_HOOKUP_OBJECT (window, hbox15, "hbox15");
  GLADE_HOOKUP_OBJECT (window, hbox21, "hbox21");
  GLADE_HOOKUP_OBJECT (window, label32, "label32");
  GLADE_HOOKUP_OBJECT (window, entryVIDa, "entryVIDa");
  GLADE_HOOKUP_OBJECT (window, label33, "label33");
  GLADE_HOOKUP_OBJECT (window, entryPIDa, "entryPIDa");
  GLADE_HOOKUP_OBJECT (window, hbox14, "hbox14");
  GLADE_HOOKUP_OBJECT (window, hbox22, "hbox22");
  GLADE_HOOKUP_OBJECT (window, hseparator3, "hseparator3");
  GLADE_HOOKUP_OBJECT (window, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (window, label30, "label30");
  GLADE_HOOKUP_OBJECT (window, entryFile, "entryFile");
  GLADE_HOOKUP_OBJECT (window, hbox17, "hbox17");
  GLADE_HOOKUP_OBJECT (window, hbox23, "hbox23");
  GLADE_HOOKUP_OBJECT (window, hseparator4, "hseparator4");
  GLADE_HOOKUP_OBJECT (window, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (window, label18, "label18");
  GLADE_HOOKUP_OBJECT (window, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window, label21, "label21");
  GLADE_HOOKUP_OBJECT (window, label20, "label20");
  GLADE_HOOKUP_OBJECT (window, label19, "label19");
  GLADE_HOOKUP_OBJECT (window, labelTitle, "labelTitle");
  GLADE_HOOKUP_OBJECT (window, labelSize, "labelSize");
  GLADE_HOOKUP_OBJECT (window, labelVersion, "labelVersion");
  GLADE_HOOKUP_OBJECT (window, hbox24, "hbox24");
  GLADE_HOOKUP_OBJECT (window, hseparator5, "hseparator5");
  GLADE_HOOKUP_OBJECT (window, vbuttonbox2, "vbuttonbox2");
  GLADE_HOOKUP_OBJECT (window, buttonVersion, "buttonVersion");
  GLADE_HOOKUP_OBJECT (window, buttonQuick, "buttonQuick");
  GLADE_HOOKUP_OBJECT (window, buttonStartAU, "buttonStartAU");
  GLADE_HOOKUP_OBJECT (window, hbox25, "hbox25");
  GLADE_HOOKUP_OBJECT (window, hseparator6, "hseparator6");
  GLADE_HOOKUP_OBJECT (window, hbox18, "hbox18");
  GLADE_HOOKUP_OBJECT (window, label27, "label27");
  GLADE_HOOKUP_OBJECT (window, label1, "label1");
  GLADE_HOOKUP_OBJECT (window, frame3, "frame3");
  GLADE_HOOKUP_OBJECT (window, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (window, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (window, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (window, label15, "label15");
  GLADE_HOOKUP_OBJECT (window, listVersions, "listVersions");
  GLADE_HOOKUP_OBJECT (window, treeviewVersions, "treeviewVersions");
  GLADE_HOOKUP_OBJECT (window, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (window, label16, "label16");
  GLADE_HOOKUP_OBJECT (window, scrolledwindow5, "scrolledwindow5");
  GLADE_HOOKUP_OBJECT (window, textviewLog, "textviewLog");
  GLADE_HOOKUP_OBJECT (window, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (window, label17, "label17");
  GLADE_HOOKUP_OBJECT (window, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (window, buttonDownload, "buttonDownload");
  GLADE_HOOKUP_OBJECT (window, buttonFLash, "buttonFLash");
  GLADE_HOOKUP_OBJECT (window, buttonStart, "buttonStart");
  GLADE_HOOKUP_OBJECT (window, label3, "label3");

  return window;
}

