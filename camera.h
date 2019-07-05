#include <Movement.h>
#define camera get_object_count
#define red 0 //make sure red is set to channel 0
void camera_red()
{
    camera_update();
    while (camera(red) < 0) //while camera doesn't read red
    {
        //insert code for: do until red
        camera_update();
        msleep(100);
    }
    msleep(200);

    camera_close();
}
