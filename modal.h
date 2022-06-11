#include <X11/Xlib.h>

/* structs */
typedef struct {
    unsigned int width;
    unsigned int height;
} ModalPosition;

typedef struct {
    char *foreground;
    char *background;
} ModalColors;

typedef struct {
    unsigned short int width;
    unsigned short int height;
    unsigned short int border;

    unsigned short int insideX;
    unsigned short int insideY;
} ModalGeometry;

typedef struct {
    char         *message;
    ModalGeometry modalGeometry;
    ModalColors   modalColors;
    Display      *display;
    unsigned short int default_screen;
} Modal;

/* function definitions */
Modal *create_modal(char *message, ModalGeometry *modalGeometry, ModalColors *modalColors);
void show_modal(Modal *modal, const ModalPosition *displayDimensions);
