#include <stdio.h>
#include <stdlib.h>

struct registro {
           char  nome[15];
           char  sobrenome[15];
           char  rua[25];
           int numero;
};

struct registro separa_campos(char *entrada){
   char aux[10];
   int pos = 0, i;
   struct registro saida;
   // carrega nome
   i = 0;
   while (entrada[pos] != 0x7C) {
         saida.nome[i] = entrada[pos];
         i++; pos++;
   }
   saida.nome[i] = '\0';
   // carrega sobrenome
   i = 0;
   pos++;
   while (entrada[pos] != 0x7C) {
         saida.sobrenome[i] = entrada[pos];
         i++; pos++;
   }
   saida.sobrenome[i] = '\0';
   // carrega rua
   i = 0;
   pos++;
   while (entrada[pos] != 0x7C) {
         saida.rua[i] = entrada[pos];
         i++; pos++;
   }
   saida.rua[i] = '\0';
   // carrega numero
   i = 0;
   pos++;
   while (entrada[pos] != 0x7C) {
         aux[i] = entrada[pos];
         i++; pos++;
   }
   aux[i] = '\0';
   saida.numero = atoi(aux);
   return saida; 
}

int main(void) {
    FILE *fd;
    char buffer_np[1000];
    struct registro buffer;
    
    //grava fixo no codigo
    fd = fopen("campo_var_reg_fixo.dad", "rb");
    
    //lê
    fseek(fd,0,0);
    while(fread(buffer_np,sizeof(struct registro),1,fd)) {
       buffer = separa_campos(buffer_np);                                 
       printf("%s %s %s %d\n", buffer.nome, 
                            buffer.sobrenome,
                            buffer.rua,
                            buffer.numero);
    }
                  
    fclose(fd);
    fflush(stdin);            
    getchar();
    return 0;  
} 
