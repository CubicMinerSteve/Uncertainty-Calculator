# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <windows.h>

# define N 50

int main(void)
{
    system("mode con: cols=60 lines=35");

    int i = 0, Data_Count = 0, Continue = 0;
    char Distribution_Type = ' ';

    double Average = 0, Bessel = 0, Delta_i = 0;
    double Uncertainty_A = 0, Uncertainty_B = 0, Uncertainty_X = 0;

    double Data[N] = {0};

    Initialize : printf("========================================\n");
    printf("欢迎回来！今天也要进行不确定度的计算吗？ 2023 - 4 - 19\n");
    printf("========================================\n");
    printf("请输入数据个数：\n");
    Count : scanf("%d", &Data_Count);
    if (Data_Count <= 0)
    {
        printf("数据个数必须大于 0，请重新输入：\n");
        goto Count;
    }
    fflush(stdin);

    printf("指定数据个数为 %d 个，请输入数据：\n", Data_Count);
    for (i = 0; i < Data_Count; i++)
    {
        scanf("%lf", &Data[i]);
    }
    fflush(stdin);

    printf("请输入数据的极限误差 Δi ：\n");
    scanf("%lf", &Delta_i);
    fflush(stdin);

    printf("请输入数据误差的分布类型，输入规范见下：\n");
    printf("均匀分布 Uniform Distribution - U\n");
    printf("正态分布 Normal Distribution - N\n");
    printf("反正弦分布 Arcsine Distribution - A\n");
    printf("三角分布 Triangular Distribution - T\n");
    Dis_Type : scanf("%c", &Distribution_Type);
    if (Distribution_Type == 'U' || Distribution_Type == 'u')
    {
        printf("已选定误差分布类型为均匀分布！\n\n");
        Uncertainty_B = Delta_i / sqrt(3);
    }
    else if (Distribution_Type == 'N' || Distribution_Type == 'n')
    {
        printf("已选定误差分布类型为正态分布！\n\n");
        Uncertainty_B = Delta_i / 3;
    }
    else if (Distribution_Type == 'A' || Distribution_Type == 'a')
    {
        printf("已选定误差分布类型为反正弦分布！\n\n");
        Uncertainty_B = Delta_i / sqrt(2);
    }
    else if (Distribution_Type == 'T' || Distribution_Type == 't')
    {
        printf("已选定误差分布类型为三角分布！\n\n");
        Uncertainty_B = Delta_i / sqrt(6);
    }
    else
    {
        printf("检测到不规范的输入，请重新输入：\n");
        fflush(stdin);
        goto Dis_Type;
    }

    Average = 0;
    for (i = 0; i < Data_Count; i++)
    {
        Average += Data[i];
    }
    Average = Average / Data_Count;
    printf("样本平均值 Average X = %.8lf\n", Average);

    Bessel = 0;
    if (Data_Count != 1)
    {
        for (i = 0; i < Data_Count; i++)
        {
            Bessel += pow((Data[i] - Average), 2);
        }
        Bessel = sqrt(Bessel / (Data_Count - 1));
    }
    printf("Bessel 样本标准差 σ = %.8lf\n\n", Bessel);

    Uncertainty_A = 0;
    if (Data_Count != 1)
    {
        for (i = 0; i < Data_Count; i++)
        {
            Uncertainty_A += pow((Data[i] - Average), 2);
        }
        Uncertainty_A = sqrt(Uncertainty_A / (Data_Count * (Data_Count - 1)));
    }
    printf("A 类不确定度 U_a = %.8lf\n", Uncertainty_A);
    printf("B 类不确定度 U_b = %.8lf\n", Uncertainty_B);
    Uncertainty_X = sqrt(pow(Uncertainty_A, 2) + pow(Uncertainty_B, 2));
    printf("合成不确定度 U_x = %.8lf\n\n\n", Uncertainty_X);

    printf("是否开始新一轮的数据计算？ 是 - 1  否 - 2\n");
    Choice : fflush(stdin);
    scanf("%d", &Continue);
    if (Continue == 1)
    {
        system("cls");
        goto Initialize;
    }
    else if (Continue == 2)
    {
        return 0;
    }
    else
    {
        printf("检测到不规范的输入，请重新输入：\n");
        goto Choice;
    }
    return 0;
}
