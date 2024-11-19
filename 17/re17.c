#include<stdio.h>
#include<math.h>

#define ndat 20
#define precision 0.5

// 関数のプロトタイプ宣言
float func(float t, float vy, float y0);
float calc_chi2(float t[], float y[], float s[], float a, float b);

int main(void) {
    FILE *fp;
    float t[ndat], model_x, model_y[ndat], error_y[ndat], exp_y[ndat], err[ndat];
    int ih;

    // ファイルを開く
    if ((fp = fopen("u.dat", "r")) != NULL) {
        for (ih = 0; ih < ndat; ih++) {
            if (fscanf(fp, "%f %f %f %f %f", &t[ih], &model_x, &model_y[ih], &error_y[ih], &exp_y[ih]) != 5) {
                printf("Error reading data at line %d\n", ih + 1);
                fclose(fp);
                return 1; // 読み取りエラーがあれば終了
            }
            err[ih] = precision; // 定数誤差の設定
        }
        fclose(fp); // ファイルを閉じる
    } else {
        printf("File open error!\n");
        return 1; // ファイルが開けなければ終了
    }

    // 計算部分
    float vy = 6, y0 = 5, chi2;
    chi2 = calc_chi2(t, exp_y, err, vy, y0);
    printf("Chi square = %f at vy = %f, y0 = %f\n", chi2, vy, y0);
    printf("Chi square / nu = %f\n", chi2 / (ndat - 3)); // 自由度を考慮

    return 0;
}

// χ²値の計算
float calc_chi2(float t[], float y[], float s[], float a, float b) {
    float chi2 = 0;
    int i;

    for (i = 0; i < ndat; i++) {
        float diff = y[i] - func(t[i], a, b);
        chi2 += diff * diff / (s[i] * s[i]);
        printf("%f, %f, %f, %f, %f\n", chi2, t[i], y[i], func(t[i], a, b), s[i]);
    }
    return chi2;
}

// モデル関数
float func(float t, float vy, float y0) {
    return y0 + vy * t - 0.5 * 9.8 * t * t;
}

