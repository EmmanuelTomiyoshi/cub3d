#include <stdio.h>

int main(void)
{
    int window_width = 1080;
    int window_height = 720;
    int button_x = 80;
    int button_y = 240;

    int new_window_width = 1440;
    int new_window_height = 1080;

    float width_ratio = (float)new_window_width / window_width;
    float height_ratio = (float)new_window_height / window_height;

    int new_button_x = (int)(button_x * width_ratio);
    int new_button_y = (int)(button_y * height_ratio);
    new_window_width = (int)(window_width * width_ratio);
    new_window_height = (int)(window_height * height_ratio);

    printf("OLD win_width: %d | win_height: %d | btn_x: %d | btn_y: %d\n",
        window_width, window_height, button_x, button_y);
    printf("NEW win_width: %d | win_height: %d | btn_x: %d | btn_y: %d\n",
        new_window_width, new_window_height, new_button_x, new_button_y);
    printf("width_ratio: %f | height_ratio: %f\n", width_ratio, height_ratio);
}