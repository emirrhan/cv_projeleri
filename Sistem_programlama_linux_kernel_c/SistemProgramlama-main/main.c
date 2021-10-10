#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jrb.h"
#include "fields.h"
#define Max_Kelime 100

typedef struct {
  char *kod;
  char *kelime;
}Kelime;

int main(int argc, char **argv)
{

    Kelime *klm;//kelime ve kod için Kelime türünden struct
    int nsize;
    IS is;
    char *ilk,*son; //tırnakların adreslerini tutar
    JRB tree,temp_tree;
    tree = make_jrb();
    if (argc != 4) { fprintf(stderr, "paramatre eksik girildi  (./kripto -e girisdosyası cikisdosyasi) seklinde giriniz\n"); exit(1); }
    is = new_inputstruct(".kilit"); 
    if (is == NULL) 
      {
        printf("Kilit dosyası yok..\n");
        exit(1);
      }
    char *hata;
    char *temp_kelime;
    char temp_kelime1[Max_Kelime];  
    while(get_line(is) >= 0) {  
    if(is->NF >1)
      { 
         hata=strstr(is->text1,":");
          if(!hata){ 
               printf("Json format hatası.Kilit dosyasını kontrol ediniz.\n");
               exit(1);
           }  
      klm=malloc(sizeof(Kelime));  
      int sayac=0;
      for (int i = 0; i < is->NF; i++) {
          temp_kelime=is->fields[i];
          nsize = strlen(is->fields[0]);
          son=strrchr(temp_kelime,'\"');//son tırnağın adresi
          ilk=strchr(temp_kelime,'\"');//ilk tırnağin adresi
          if(son==ilk) {
          printf(" kilit dosyasında eksik tırnak hatası\n") ;
          exit(1);
          }
          int c=0;
          for(int a=(ilk-temp_kelime)+1;a<(son-temp_kelime);a++){//pointer aritmetiği kullanılarak gezme yapıldı
            temp_kelime1[c]=temp_kelime[a];
            c++;
           }
           temp_kelime1[c]='\0';//ayıklalan kelimenin sonuna \0 eklendi
               if(sayac==0) {
                   klm->kelime = (char *) malloc(sizeof(char) * (nsize)); //dinamik alan ayrımı
                   strcpy(klm->kelime,temp_kelime1);
                 }
              if(sayac==1) {
                  klm->kod = (char *) malloc(sizeof(char) * (nsize));
                  strcpy(klm->kod,temp_kelime1);
                  }
           sayac++; 
           }
        if(strcmp(argv[1],"-e")==0) (void) jrb_insert_str(tree, klm->kelime, new_jval_s((void *) klm));
        if(strcmp(argv[1],"-d")==0) (void) jrb_insert_str(tree, klm->kod, new_jval_s((void *) klm));
        // if(strcmp(argv[1],"-d")==0) (void) jrb_insert_str(tree, strdup(klm->kod), new_jval_s(strdup(klm->kelime));//bu şekilde de calismakta
       }
    }
    if(jrb_empty(tree)>0) {
      printf(".kilit dosyanız boş \n Ağacınız bos..\n Yine de çıkış dosyası oluşturuldu.\n ");
      //exit(1);
    }
    is = new_inputstruct(argv[2]);
     if (is == NULL) {
         perror(argv[2]);
         exit(1);
    }
    int sayac=1;
    FILE *fptr = fopen(argv[3], "w");
    while(get_line(is) >= 0) {
       for (int i = 0; i < is->NF; i++) {
          char *aranan=is->fields[i];// daha rahat görünsün diye bir degiskene atama yapıldı
          //printf("%s \n",aranan);
          JRB tmp = jrb_find_str(tree, aranan);//jrb tipinde işaretci dönüyor.Bunu da tmp de sakladık
	    if (tmp == NULL) 
	    {
		    fprintf(fptr,"%s ",aranan);	
		    //printf("%s ----\n",aranan);
	    }
            else {
            Kelime *y_kelime = (Kelime *) tmp->val.s; //y_kelime: yedek kelime isminde bir struct
	    if(strcmp(argv[1],"-e")==0) fprintf(fptr,"%s ",y_kelime->kod);
	    if(strcmp(argv[1],"-d")==0) fprintf(fptr,"%s ",y_kelime->kelime);
	    //if(strcmp(argv[1],"-e")==0) printf("%s - %s \n",y_kelime->kod,y_kelime->kelime);
	    //if(strcmp(argv[1],"-d")==0) printf("%s - %s \n",y_kelime->kelime,y_kelime->kod);
	   //if((sayac++)%100==0) fprintf(fptr,"\n");
	    }
         }
      }
     
   fclose(fptr);
  jettison_inputstruct(is
   free(klm);
  return 0;
}
