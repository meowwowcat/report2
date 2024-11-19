#include<stdio.h>
#include<math.h>

#define ndat 20
#define precision 0.5

float func(float y,float vy,float y0);
float calc_chi2(float t[],float y[],float s[],float a,float b);
int main(void)
{ 
        FILE*fp;
        float t[ndat],model_x,model_y[ndat],error_y[ndat],exp_y[ndat],err[ndat];
        int ih;
        if((fp=fopen("u.dat","r"))!=NULL)
        {
              for(ih=0;ih<ndat;ih++)
                  {
                        fscanf(fp,"%f %f %f %f %f",&t[ih],&model_x,model_y[ih],&error_y[ih],&exp_y[ih]);
                        err[ih]=precision;
                          }
                          fclose(fp);
                }
                else
                {
                  printf("file open error!\n");

                }

         float vy=6,y0=5,chi2;
         chi2=calc_chi2(t,exp_y,err,vy,y0);
         printf("chi square=%f at vy=%f v0=%f\n",chi2,vy,y0);
         printf("chi square/nu=%f\n",chi2/17);

         return 0;

}
float calc_chi2(float t[],float y[],float a,float b)
{float chi2=0;
 int i;
 for(i=0;i<ndat;i++){
          chi2 += (y[i]-func( t[i],a,b))*(y[i]-func( t[i],a,b)) / (s[i] * s[i]);
          printf("%f,%f,%f,%f,%f\n",chi2 ,t[i] ,y[i] ,func(t[i],a,b) ,s[i]);
         }
         return chi2;


}
float func(float t,float vy,float y0){
         float func;
         func=y0+vy*t-0.5*9.8*t*t;
         return func ;
        }
