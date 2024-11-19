#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ndat 20
#define presicion 0.1
#define dv 0.001

float func(float t,float vx,float x0);
float calc_chi2(float t[],float x[],float s[],float a,float b);
float dcdv(float t[],float x[],float s[],float a,float b);

int main(void){
        FILE*fp;
        FILE*fp2;
        FILE*fp3;

        float t[ndat],model_x[ndat],model_y[ndat],error_y[ndat],exp_y[ndat],err[ndat];
        int ih;

        if((fp=fopen("u.dat","r"))!= NULL){
                for(ih=0;ih<ndat;ih++){
                        fscanf(fp,"%f %f %f %f %f",&t[ih],&model_x[ih],model_y[ih],&error_y[ih],&exp_y[ih]);
                        err[ih]=presicion;
                        }        
                }
                else{
                        printf("file open error!\n");        
                        }
                        fclose(fp);

        float x0=10, vx;
        float chi2,dcdvx;

        fp2=fopen("1.dat","w");
        fp3=fopen("2.dat","w");

        for(vx=2;vx<8;vx+=0.01){
                 chi2=calc_chi2(t,model_x,err,vx,x0);
                 dcdvx=dcdv(t,model_x,err,vx,x0);
                 fprintf(fp2,"%f %f\n",vx,chi2);
                 fprintf(fp3,"%f %f\n",vx,dcdvx);
                }
         fclose(fp2);
         fclose(fp3);


         double vx1,vx2,dcdv1,dcdv2,mid_vx,mid_dcdv;
         int step;
         vx1=2;vx2=8;

         for(step=0;step<100;step++){
                 printf("%20.12e %20.12e %20.12e\n",vx1,vx2,mid_dcdv);
                 dcdv1=dcdv(t,model_x,err,vx1,x0);
                 dcdv2=dcdv(t,model_x,err,vx2,x0);
                 mid_vx=(vx1+vx2) / 2;
                 mid_dcdv=dcdv(t,model_x,err,mid_vx,x0);
                 if(mid_dcdv * dcdv1 >0){
                         vx1=mid_vx;
                         }
                 else{
                         vx2=mid_vx;
                         }
                 if(fabs(vx1-vx2)<dv)break;
                 }
        return 0;         
        }
float calc_chi2(float t[],float x[],float s[],float a,float b){
        float chi2=0;
        int i;

        for(i=0;i<ndat;i++){
                chi2 +=(x[i]-func(t[i],a,b)) * (x[i]-func(t[i],a,b)) / (s[i]* s[i]);   
                }
                return chi2;
        }
float func(float t,float vx,float x0){
        float func;
        func=vx * t +x0;
        return func;
        } 

float dcdv(float t[],float x[],float s[],float a,float b){
        float func2;
        func2 = (calc_chi2(t,x,s,a+dv,b) - calc_chi2(t,x,s,a,b)) / dv;
        return func2;
        }
