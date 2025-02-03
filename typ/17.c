#include<stdio.h>
#include<math.h>

#define ndat 20
#define range 0.5
#define vy0 6.0
#define y0 5.0
#define g 9.8

float func(float t){
        float y = y0 + vy0 * t - 0.5 * g * t * t ;
        return y;
}


float calc_chi2(float t[], float y[], float s[]){
        float chi2 = 0.0;
        int i;
        for(i = 0; i < ndat; i++){
                float diff = y[i] - func(t[i]);
                chi2 += diff * diff /(s[i] * s[i]);
                printf("%f\n",chi2);
        }
        return chi2;
}

int main() { 
        FILE*fp;
        float t[ndat],x[ndat],y[ndat],exp_y[ndat],error_y,s[ndat];
        int ih;
        fp = fopen("u1.dat","r");
        for(ih = 0;ih < ndat;ih++){
                fscanf(fp,"%f, %f, %f, %f, %f\n",&t[ih],&x[ih],&y[ih],&exp_y[ih],&s[ih]);
                s[ih] = range;
        }
        fclose(fp);

        float chi2;

        chi2 = calc_chi2(t, exp_y, s);
        printf("chi2 = %f\n",chi2); 

        return 0;
}
