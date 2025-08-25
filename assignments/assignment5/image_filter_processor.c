#include <stdio.h>


int main( int argc, char *argv[] )  {
	
	if (argc != 10) {
        fprintf(stderr, "Usage: %s <Width> <Height> <Red Start Color> <Green Start Color> ",argv[0]);
        fprintf(stderr, "<Blue Start Color> <Red Target Color> <Green Target Color> <Blue Target Color> <Filename>.ppm\n");
        return -1;
    }

    int width, height, start_red, target_red, start_green, target_green, start_blue, target_blue;
    sscanf(argv[1], "%d", &width);
    sscanf(argv[2], "%d", &height);
    if(width < 1 || height < 1){
        fprintf(stderr, "Width and height must not be less than 1.\n");
        return -1;
    }

    sscanf(argv[3], "%d", &start_red);
    if(start_red < 0) start_red = 0;
    if(start_red > 255) start_red = 255;
    sscanf(argv[6], "%d", &target_red);
    if(target_red < 0) target_red = 0;
    if(target_red > 255) target_red = 255;

    sscanf(argv[4], "%d", &start_green);
    if(start_green < 0) start_green = 0;
    if(start_green > 255) start_green = 255;
    sscanf(argv[7], "%d", &target_green);
    if(target_green < 0) target_green = 0;
    if(target_green > 255) target_green = 255;

    sscanf(argv[5], "%d", &start_blue);
    if(start_blue < 0) start_blue = 0;
    if(start_blue > 255) start_blue = 255;
    sscanf(argv[8], "%d", &target_blue);
    if(target_blue < 0) target_blue = 0;
    if(target_blue > 255) target_blue = 255;

    char *file_path = argv[9];
    
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    fprintf(file, "P3 %d %d 255 ", width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float ratio = (float)x / (width - 1);
            int red = start_red + ratio * (target_red - start_red);
            int green = start_green + ratio * (target_green - start_green);
            int blue = start_blue + ratio * (target_blue - start_blue);
            fprintf(file, "%d %d %d ", red, green, blue);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    return 0;
}