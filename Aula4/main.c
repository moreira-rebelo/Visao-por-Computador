
#include <stdio.h> 
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main(void)
{
    IVC* image;
    int i;


    image = vc_read_image("Aula4/flir-01.pgm");
    if (image == NULL) {
        printf("ERROR -> vc_read_image():\n\tFile not found! \n");
        getchar();
        return 0;
    }

    vc_gray_negative(image);

    vc_write_image("vc-0001.pgm", image);

    vc_image_free(image);

    printf("Press any key to exit... In");

    getchar();

    return 0;
}