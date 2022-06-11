#include "modal.h"

int main()
{
    char *msg = "Test 123asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasfas";
    ModalGeometry modalGeometry = { .border = 2, .height = 50, .width = 400, .insideX = 10, .insideY = 27 };
    ModalColors modalColors = { .background = "#0f111b", .foreground = "#ecf0c1" };
    Modal *modal = create_modal(msg, &modalGeometry, &modalColors);

    ModalPosition modalPos = { .height = 0, .width = 1500 };
    show_modal(modal, &modalPos);

    return 0;
}
