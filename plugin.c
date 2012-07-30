#include "geanyplugin.h"

GeanyPlugin* geany_plugin;
GeanyData* geany_data;
GeanyFunctions* geany_functions;

PLUGIN_VERSION_CHECK(147)
PLUGIN_SET_INFO("Geany Quick Open",
                "Quick open files dialog.",
                "0.0",
                "Razvan Constantin <razvanco13@gmail.com>");

void plugin_init(GeanyData* data) {
}

void plugin_cleanup(void) {
}

GtkWidget* plugin_configure(GtkDialog* dlg) {
  return NULL;
}

static void plugin_project_new(GObject* unused1, GtkWidget *notebook, gpointer unused2) {
}
static void plugin_project_open(GObject* unused1, gpointer unused2) {
}
static void plugin_project_close(GObject* unused1, gpointer unused2) {
}
PluginCallback plugin_callbacks[] = {
  { "project-dialog-confirmed", (GCallback) &plugin_project_new, TRUE, NULL },
  { "project-open", (GCallback) &plugin_project_open, TRUE, NULL },
  { "project-close", (GCallback) &plugin_project_close, FALSE, NULL },
  { NULL, NULL, FALSE, NULL }
};
