#include<stdio.h>

#define ndat 20
#define precision 0.1
int main(void)
{
     FILE*fp;
     float t[ndat],x[ndat],s[ndat],y[ndat],exp_y[ndat];
     float para_v,para_x0;
     int ih;

     if((fp=fopen("u.dat","r"))!=NULL){
             for(ih=0;ih<ndat;ih++){
                     fscanf(fp,"%f %f %f %f %f",&t[ih],&x[ih],&y[ih],&exp_y[ih],&s[ih]);
                     s[ih]=precision;
                     }
              fclose(fp);

             }
             else{
                  printf("file open error!\n");
                  return -1;
                  }
             float SUM_T2=0,SUM_T=0,SUM_X=0,SUM_TX=0,SUM_1=0;
             int i;
             for()
}
