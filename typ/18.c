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
             for(i=0;i<ndat;i++){
                        SUM_T2  += t[i] * t[i]/(s[i] * s[i]);
                        SUM_T   += t[i] / ( s[i] * s[i]);
                        SUM_X   += x[i] / ( s[i] * s[i]);
                        SUM_TX  += t[i] * x[i] / ( s[i] * s[i]);
                        SUM_1   += 1.0 / ( s[i] * s[i]);
                     }
              para_v = (SUM_TX * SUM_1 - SUM_T * SUM_X) / (SUM_T2 * SUM_1 - SUM_T * SUM_T);
              para_x0 = (SUM_T2 * SUM_X - SUM_TX * SUM_T) / (SUM_T2 * SUM_1 - SUM_T * SUM_T);

              fp=fopen("output.txt","w");
              if( fp != NULL){
                      fprintf(fp,"v=%f , x0=%f\n",para_v,para_x0);
                      fclose(fp);
                      printf("書き込みおｋ\n");
                      }
             else{
                      printf("書き込みだめ\n");
                      return -1;
                     } 

             return 0;
}
