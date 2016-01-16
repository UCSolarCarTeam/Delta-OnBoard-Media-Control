#include "backup_camera.h"

int main()
{
    BackupCamera backup_camera;

    if (!backup_camera.init())
    {
        fprintf(stderr, "Could not initialize!\n");
        return -1;
    }

    while (1)
    {
        backup_camera.update();

        if (!back_camera.quit)
        {
            break;
        }
    }

    backup_camera.close();
}
