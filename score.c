#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    FILE *fp,*mfp, *efp;
    int i,mscore,msum = 0,mave,mdiff,escore,esum = 0,eave,ediff;
    srand((unsigned)time(NULL));

    fp = fopen("score.txt","w+");

    if(fp == NULL)
    {
        printf("ファイルを開けませんでした\n");
        exit(-1);
    }

    for(i = 0; i < 40; i++)
    {
        fprintf(fp,"%d\t%d\n", (int)(rand()/(double)RAND_MAX*100), (int)(rand()/(double)RAND_MAX*100));
    }

    rewind(fp);

    for(i = 0; i < 40; i++)
    {
        fscanf(fp,"%d\t%d\n", &mscore, &escore);
        msum += mscore;
        esum += escore;
    }

    mave = msum / 40;
    eave = esum / 40;

    fprintf(fp, "%d\t%d\n", mave, eave);

    rewind(fp);

    mfp = fopen("Mathematics.txt","w");
    efp = fopen("English.txt","w");

    if(mfp == NULL || efp == NULL)
    {
        printf("ファイルを開けませんでした\n");
        exit(-1);
    }

    for(i = 0; i < 40; i++)
    {
        fscanf(fp,"%d\t%d\n", &mscore, &escore);
        mdiff = mscore - mave;
        ediff = escore - eave;
        fprintf(mfp,"%d\t%d\n", mscore, mdiff);
        fprintf(efp,"%d\t%d\n", escore, ediff);
    }

    fclose(fp);
    fclose(mfp);
    fclose(efp);

    return 0;
}
