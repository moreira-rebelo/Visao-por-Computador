#include <stdio.h> 
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main(void)
{
    IVC *image_src;
    IVC *image_dst;
    
    image_src = vc_read_image("C:\\Users\\morei\\Desktop\\VC\\Aulas\\pepper.ppm");
    if (image_src == NULL) {
        printf("ERROR -> vc_read_image():\n\tFile not found! \n");
        getchar();
        return 0;
    }
    image_dst = vc_image_new(image_src->width, image_src->height, 1, image_src->levels);

    vc_rgb_to_gray(image_src, image_dst);
    
    vc_write_image("C:\\Users\\morei\\Desktop\\VC\\Aulas\\Output.pgm", image_dst);

    system("cmd /c start C:\\Users\\morei\\Desktop\\VC\\Aulas\\FilterGear.exe C:\\Users\\morei\\Desktop\\VC\\Aulas\\pepper.ppm"); // Input
    system("C:\\Users\\morei\\Desktop\\VC\\Aulas\\FilterGear.exe C:\\Users\\morei\\Desktop\\VC\\Aulas\\Output.pgm"); // Output

    vc_image_free(image_src);
    vc_image_free(image_dst);
  
    printf("Press any key to exit... In");
    getchar();

    return 0;
}

