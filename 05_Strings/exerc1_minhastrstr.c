#include <stdio.h>
#include <string.h>

char* minha_strstr(char* string, char* substring);
char* minha_strstr_ptr(char* string, char* substring);

int main()
{
    char s1[] = "Minha string legleglegalllegal";
    char s2[] = "legal";

    char* ptr = minha_strstr_ptr(s1, s2);
    if(ptr != NULL) {
        printf("Encontrei no endereço: %p\n", ptr);
    }
    else {
        printf("Substring não encontrada!\n");
    }
}

char* minha_strstr(char* string, char* substring)
{
    int pos1; // pos na string
    int pos2; // pos na substring
    pos1 = 0;
    while(string[pos1] != '\0') {
        pos2 = 0; // começa no início da substring
        while(substring[pos2] != '\0' && string[pos1+pos2] != '\0') {
            printf("%c <-> %c\n", string[pos1+pos2], substring[pos2]);
            if(string[pos1+pos2] == substring[pos2]) {
                printf("Achei!\n");
                pos2++;
            }
            else break;
        }
        if(substring[pos2] == '\0') { // cheguei no final?
            return &string[pos1];
        }
        pos1++;
    }
    return NULL;
}

char* minha_strstr_ptr(char* string, char* substring)
{
    char* ptr1;
    char* ptr2;
    ptr1 = string; //aponta para o início da string
    while(*ptr1 != '\0') {
        ptr2 = substring; // aponta para o início da substring
        char* aux = ptr1;
        while(*ptr2 != '\0' && *aux != '\0') {
            printf("%c <-> %c\n", *aux, *ptr2);
            if(*aux == *ptr2) {
                printf("Achei!\n");
                ptr2++;
                aux++;
            }
            else break;
        }
        if(*ptr2 == '\0') { // cheguei no final?
            return ptr1; // corresponde ao início
        }
        ptr1++;
    }
    return NULL;
}
