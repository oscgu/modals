#include "modal.h"

int main()
{
    char *msg = "Test 123";
    ModalGeometry modalGeometry = { .border = 2, .height = 50, .width = 400, .insideX = 10, .insideY = 10 };
    Modal *modal = create_modal(msg, &modalGeometry);

    ModalPosition modalPos = { .height = 0, .width = 1920 };
    show_modal(modal, &modalPos);

    return 0;
}
