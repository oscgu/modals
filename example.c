#include "notif.h"
#include <string.h>
#include <stdio.h>

int main()
{
    NotifGeometry notifGeometry = { .border = 2, .height = 50, .width = 400, .insideX = 10, .insideY = 27 };
    char msg[MAX_MESSAGE_LEN(2, 400, 10, 13)] = "Test 123asdfasdfasdfasdfasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    NotifColors notifColors = { .background = "#0f111b", .foreground = "#ecf0c1" };
    Notif *notif = create_notif(msg, &notifGeometry, &notifColors);

    NotifPosition notifPos = { .height = 0, .width = 1500 };
    show_notif(notif, &notifPos);

    return 0;
}
