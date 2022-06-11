#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "modal.h"

/* function implementations */
static unsigned long get_color_from_hex(char *hexcol, Display *display)
{
    XColor xcol;
    XParseColor(display, DefaultColormap(display, 0), hexcol, &xcol);
    XAllocColor(display, DefaultColormap(display, 0), &xcol);

    return xcol.pixel;
}

static void destroy_modal(Modal *modal)
{
    XFlush(modal->display);
    XCloseDisplay(modal->display);
    free(modal);
}

void show_modal(Modal *modal, const ModalPosition *modalpos)
{
    XEvent event;

    printf("X: %d, Y: %d\n", modalpos->width, modalpos->height);

    Window window = XCreateSimpleWindow(modal->display, RootWindow(modal->display, modal->default_screen), modalpos->width, modalpos->height, modal->modalGeometry.width, modal->modalGeometry.height, modal->modalGeometry.border, get_color_from_hex(modal->modalColors.foreground, modal->display), get_color_from_hex(modal->modalColors.background, modal->display));
    XSetForeground(modal->display, DefaultGC(modal->display, modal->default_screen), get_color_from_hex(modal->modalColors.foreground, modal->display));
    XSelectInput(modal->display, window, ExposureMask | KeyPressMask);
    XSetTransientForHint(modal->display, window, RootWindow(modal->display, modal->default_screen));
    XMapWindow(modal->display, window);

    for (;;)
    {
        XNextEvent(modal->display, &event);

        if(event.type == Expose)
        {
            XDrawString(modal->display, window, DefaultGC(modal->display, modal->default_screen), modal->modalGeometry.insideX, modal->modalGeometry.insideY, modal->message, strlen(modal->message));
        }

        if (event.type == KeyPress && event.xkey.keycode == 24) 
        {
            printf("User pressed Q(uit)\n");
            break;
        }
    }

    destroy_modal(modal);
}


Modal *create_modal(char *message, ModalGeometry *modalGeometry, ModalColors *modalColors)
{
    Display *display = XOpenDisplay(NULL);

    if (display == NULL) 
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    int default_screen = DefaultScreen(display);

    Modal *modal = malloc(sizeof(Modal));
    modal->default_screen = default_screen;
    modal->display = display;
    modal->modalColors = *modalColors;
    modal->modalGeometry = *modalGeometry;
    modal->message = message;

    return modal;
}
