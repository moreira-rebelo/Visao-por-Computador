#include <stdio.h> 
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main(void)
{
    IVC* image;
    int i;


    image = vc_read_image("C:\\Users\\morei\\Desktop\\VC\\Aula4\\pepper.ppm");
    if (image == NULL) {
        printf("ERROR -> vc_read_image():\n\tFile not found! \n");
        getchar();
        return 0;
    }

    vc_rgb_negative(image);
    vc_write_image("C:\\Users\\morei\\Desktop\\VC\\Aula4\\Negative.ppm", image);
    vc_image_free(image);
  

    printf("Press any key to exit... In");

    getchar();

    return 0;
}

