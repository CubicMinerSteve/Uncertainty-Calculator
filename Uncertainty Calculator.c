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
    printf("��ӭ����������ҲҪ���в�ȷ���ȵļ����� 2023 - 4 - 19\n");
    printf("========================================\n");
    printf("���������ݸ�����\n");
    Count : scanf("%d", &Data_Count);
    if (Data_Count <= 0)
    {
        printf("���ݸ���������� 0�����������룺\n");
        goto Count;
    }
    fflush(stdin);

    printf("ָ�����ݸ���Ϊ %d �������������ݣ�\n", Data_Count);
    for (i = 0; i < Data_Count; i++)
    {
        scanf("%lf", &Data[i]);
    }
    fflush(stdin);

    printf("���������ݵļ������ ��i ��\n");
    scanf("%lf", &Delta_i);
    fflush(stdin);

    printf("�������������ķֲ����ͣ�����淶���£�\n");
    printf("���ȷֲ� Uniform Distribution - U\n");
    printf("��̬�ֲ� Normal Distribution - N\n");
    printf("�����ҷֲ� Arcsine Distribution - A\n");
    printf("���Ƿֲ� Triangular Distribution - T\n");
    Dis_Type : scanf("%c", &Distribution_Type);
    if (Distribution_Type == 'U' || Distribution_Type == 'u')
    {
        printf("��ѡ�����ֲ�����Ϊ���ȷֲ���\n\n");
        Uncertainty_B = Delta_i / sqrt(3);
    }
    else if (Distribution_Type == 'N' || Distribution_Type == 'n')
    {
        printf("��ѡ�����ֲ�����Ϊ��̬�ֲ���\n\n");
        Uncertainty_B = Delta_i / 3;
    }
    else if (Distribution_Type == 'A' || Distribution_Type == 'a')
    {
        printf("��ѡ�����ֲ�����Ϊ�����ҷֲ���\n\n");
        Uncertainty_B = Delta_i / sqrt(2);
    }
    else if (Distribution_Type == 'T' || Distribution_Type == 't')
    {
        printf("��ѡ�����ֲ�����Ϊ���Ƿֲ���\n\n");
        Uncertainty_B = Delta_i / sqrt(6);
    }
    else
    {
        printf("��⵽���淶�����룬���������룺\n");
        fflush(stdin);
        goto Dis_Type;
    }

    Average = 0;
    for (i = 0; i < Data_Count; i++)
    {
        Average += Data[i];
    }
    Average = Average / Data_Count;
    printf("����ƽ��ֵ Average X = %.8lf\n", Average);

    Bessel = 0;
    if (Data_Count != 1)
    {
        for (i = 0; i < Data_Count; i++)
        {
            Bessel += pow((Data[i] - Average), 2);
        }
        Bessel = sqrt(Bessel / (Data_Count - 1));
    }
    printf("Bessel ������׼�� �� = %.8lf\n\n", Bessel);

    Uncertainty_A = 0;
    if (Data_Count != 1)
    {
        for (i = 0; i < Data_Count; i++)
        {
            Uncertainty_A += pow((Data[i] - Average), 2);
        }
        Uncertainty_A = sqrt(Uncertainty_A / (Data_Count * (Data_Count - 1)));
    }
    printf("A �಻ȷ���� U_a = %.8lf\n", Uncertainty_A);
    printf("B �಻ȷ���� U_b = %.8lf\n", Uncertainty_B);
    Uncertainty_X = sqrt(pow(Uncertainty_A, 2) + pow(Uncertainty_B, 2));
    printf("�ϳɲ�ȷ���� U_x = %.8lf\n\n\n", Uncertainty_X);

    printf("�Ƿ�ʼ��һ�ֵ����ݼ��㣿 �� - 1  �� - 2\n");
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
        printf("��⵽���淶�����룬���������룺\n");
        goto Choice;
    }
    return 0;
}
