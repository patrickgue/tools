#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <libtools.h>

int main(int argc, char **argv)
{
    int i, c, decode = 0, not_stdin = 0, len;
    FILE *input_file;
    char input_file_buffer[1024] = "", chr_buff[7], b64_buff[9];
    if (argc > 1) {
        for (i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-d") == 0)
            {
                decode = 1;
            }
            else
            {
                strcpy(input_file_buffer, argv[i]);
                not_stdin = 1;
            }
        }
    }
    if (not_stdin)
    {
        input_file = fopen(input_file_buffer, "r");
        if (input_file == NULL)
        {
            fprintf(stderr, "Unable to open file \"%s\"\n", input_file_buffer);
            exit(1);
        }
    }
    else
    {
        input_file = stdin;
    }

    fflush(stdin);
    if (decode == 0)
    {
        while ((len = fread(chr_buff, 1, 6, input_file)) != 0)
        {
            memset(b64_buff, 0, 9);
            base64_encode(b64_buff, 8, chr_buff, len);
            printf("%s", b64_buff);
        }
        printf("\n");
    }
    else
    {
        i = 0;
        do
        {
            c = fgetc(input_file);
            if (base64_is_base64_char(c))
            {
                b64_buff[i++] = c;
            }

            if (i == 8 || c == EOF)
            {
                memset(chr_buff, 0, 7);
                base64_decode(chr_buff, 6, b64_buff, i);
                printf("%s", chr_buff);
                memset(b64_buff, 0, 9);
                i = 0;
            }
        }
        while (c != EOF);
    }


    if (not_stdin)
    {
        fclose(input_file);
    }
    return 0;
}
