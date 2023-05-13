#include <iostream>
#include <cstdio>
#include <cerrno>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#define FILE_PATH "D:/Demo.txt"  // �ļ�·��
char Arithmetic_brackets[4] = {'(' , ' ' , ')' , ' '}; //����
char Arithmetic_operators[4] = {'+' , '-' , '*' , '/'}; //�����
const int Arithmetic_operation = 4; //������������
const int Arithmetic_bracket = 2; //�����������
int Arithmetic_number; //��Ŀ��Ŀ
int Arithmetic_max; //�����
int Arithmetic_iffile;   //ȷ���Ƿ��ӡ
int Arithmetic_ifdecimal;  //ȷ���Ƿ���С��
int Arithmetic_ifbrackets;  //ȷ���Ƿ�������
FILE *fp;   //�ļ���ַ

void showMenu();    //��ӭ����
void showExit();    //�˳�����
void Arithmetic_Output_Screen();//��Ļ�������
void Arithmetic_Output_File();  //�ı��������
void showMenu()
{
    system("title Сѧ���������Զ����ɳ���");
    cout << endl;
    cout << "����������������������������������������������������������������������������������������" << endl;
    cout << "��                                                                                    ��" << endl;
    cout << "��                ��ӭʹ��Сѧ���������Զ����ɳ���                                    ��" << endl;
    cout << "��                                                                                    ��" << endl;
    cout << "��                                                                                    ��" << endl;
    cout << "��                �������ղ�������������������ϰ�⣺                                  ��" << endl;
    cout << "��                                                                                    ��" << endl;
    cout << "��                ��1������������Ŀ���� <1-100>                                       ��" << endl;
    cout << "��                ��2��������������� <1-1000>                                        ��" << endl;
    cout << "��                ��3������ѡ���Ƿ���С��                                             ��" << endl;
    cout << "��                ��4������ѡ���Ƿ�������                                             ��" << endl;
    cout << "��                ��5������ѡ���Ƿ��ӡ���ļ�                                         ��" << endl;
    cout << "��                                                                                    ��" << endl;
    cout << "����������������������������������������������������������������������������������������" << endl;
    cout << endl;
}
 
void menu1()
{
    cout << endl;
    showMenu();
    cout << "��1������������Ŀ���� <1-100> ��" << endl;
    cin >> Arithmetic_number;
    while((Arithmetic_number > 100) || (Arithmetic_number < 1 ))
    {
        cout << "�����õ���Ŀ��Ŀ������Ҫ��(̫��/̫��)�� < 1 - 100 > " << endl;
        cout << endl;
        cout << "�밴ȷ�ϼ���������" << endl;
        cin >> Arithmetic_number;
    }
}
 
void menu2()
{
    cout << endl;
    cout << "��2��������������� <1-1000> ��" << endl;
    cin>>Arithmetic_max;
    while((Arithmetic_max > 1000) || (Arithmetic_max < 1 ))
    {
        cout << "�����õ������������Ҫ��(̫��/̫С)�� < 1 - 1000 > " << endl;
        cout << endl;
        cout << "�밴ȷ�ϼ���������" << endl;
        cin >> Arithmetic_max;
    }
}
 
void menu3()
{
    cout << endl;
    cout << "��3������ѡ���Ƿ���С����(���� <0> �������� , ���� <1> ����С��) "<<endl;
    cin>>Arithmetic_ifdecimal;
    while((Arithmetic_ifdecimal !=0 ) && (Arithmetic_ifdecimal != 1 ))
    {
        cout << "���������������Ҫ��(���� <0> �������� , ���� <1> ����С��) " << endl;
        cout << endl;
        cout << "�밴ȷ�ϼ���������" << endl;
        cin >> Arithmetic_ifdecimal;
    }
}
 
void menu4()
{
    cout << endl;
    cout << "��4������ѡ���Ƿ������ţ�(���� <0> ������ , ���� <1> ������)" << endl;
    cin>>Arithmetic_ifbrackets;
    while((Arithmetic_ifbrackets !=0 ) && (Arithmetic_ifbrackets != 1 ))
    {
        cout << "���������������Ҫ��(���� <0> ������ , ���� <1> ������) " << endl;
        cout << endl;
        cout << "�밴ȷ�ϼ���������" << endl;
        cin >> Arithmetic_ifbrackets;
    }
}
 
int menu5()
{
    cout << endl;
    cout << "��5������ѡ���Ƿ��ӡ���ļ���(���� <0> ����ӡ(��Ļ��ʾ) , ���� <1> ��ӡ)" << endl;
    cin>>Arithmetic_iffile;
    while((Arithmetic_iffile !=0 ) && (Arithmetic_iffile != 1 ))
    {
        cout << "���������������Ҫ��(���� <0> ����ӡ(��Ļ��ʾ) , ���� <1> ��ӡ) " << endl;
        cout << endl;
        cout << "�밴ȷ�ϼ���������" << endl;
        cin >> Arithmetic_iffile;
    }
    return Arithmetic_iffile;
}
 
 
void menu()
{
    menu1();
    menu2();
    menu3();
    menu4();
}

 
void Arithmetic_Output_Screen()
{
    cout <<"+----------------����Ϊ*Сѧ���������Զ����ɳ���*�����ɵ�����������ϰ��----------------+" << endl;
    for(int i=1; i<=Arithmetic_number; i++)
    {
        /*��������ĸ�����*/
        int number1 = rand() % Arithmetic_max;
        int number2 = rand() % Arithmetic_max;
        int number3 = rand() % Arithmetic_max;
        int number4 = rand() % Arithmetic_max;
        
        /*��������ĸ�С��*/
        float number5 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
        float number6 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
        float number7 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
        float number8 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
 
        /*����������������*/
        int operation1 = rand() % Arithmetic_operation;
        int operation2 = rand() % Arithmetic_operation;
        int operation3 = rand() % Arithmetic_operation;
        char cur_operation1 = Arithmetic_operators[operation1];
        char cur_operation2 = Arithmetic_operators[operation2];
        char cur_operation3 = Arithmetic_operators[operation3];
 
        /*�����������()*/
        int barcket1 = rand() % Arithmetic_bracket;
        char cur_barckets1 = Arithmetic_brackets[barcket1];
        char cur_barckets2 = Arithmetic_brackets[barcket1+2];
 
        if(Arithmetic_ifdecimal)
        {
            if(Arithmetic_ifbrackets)
            {
                cout << "NO." << i << " : "<< cur_barckets1 << fixed<< setprecision(2) <<number5 << " " << cur_operation1 << " " << number6 << cur_barckets2 << " " << cur_operation2 << " " <<number7 << " " << cur_operation3 << " " <<number8 << "=" << endl;
			}
            else
            {
                cout << "NO." << i << " : "<< fixed<< setprecision(2) << number5 << " " << cur_operation1 << " " << number6 << " " << cur_operation2 << " " << number7 << " " << cur_operation3 << " " << number8 << "=" << endl;
            }
        }
        else
        {
            if(Arithmetic_ifbrackets)
            {
                cout << "NO." << i << " : "<< cur_barckets1 << number1 << " " << cur_operation1 << " " << number2 << cur_barckets2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
            }
            else
            {
                cout << "NO." << i << " : "<< number1 << " " << cur_operation1 << " " << number2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
            }
        }
    }
    cout << "+--------------------------------------------------------------------------------------+" << endl;
}
   
void Arithmetic_Output_File()
{
    cout << Arithmetic_number <<endl;
    fp = fopen(FILE_PATH, "rt+");
    if (fp != NULL)
    {
        fprintf( fp ,"\n");
        fprintf( fp,"+----------------����Ϊ*Сѧ���������Զ����ɳ���*�����ɵ�����������ϰ��----------------+\n");
        for(int i = 1; i <= Arithmetic_number; i++)
        {
            /*��������ĸ�����*/
            int number1 = rand() % Arithmetic_max;
            int number2 = rand() % Arithmetic_max;
            int number3 = rand() % Arithmetic_max;
            int number4 = rand() % Arithmetic_max;
 
            /*��������ĸ�С��*/
            float number5 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
            float number6 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
            float number7 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
            float number8 = ((float)rand() / (RAND_MAX))*Arithmetic_max;
 
            /*����������������*/
            int operation1 = rand() % Arithmetic_operation;
            int operation2 = rand() % Arithmetic_operation;
            int operation3 = rand() % Arithmetic_operation;
            char cur_operation1 = Arithmetic_operators[operation1];
            char cur_operation2 = Arithmetic_operators[operation2];
            char cur_operation3 = Arithmetic_operators[operation3];
 
            /*�����������()*/
            int barcket1 = rand() % Arithmetic_bracket;
            char cur_barckets1 = Arithmetic_brackets[barcket1];
            char cur_barckets2 = Arithmetic_brackets[barcket1+2];
            if(Arithmetic_ifdecimal)  //�ж��Ƿ���С��
            {
                if(Arithmetic_ifbrackets)   //�ж��Ƿ�������
                {
                    fprintf( fp, "NO. %2d : %c %.2f %c %.2f %c %c %.2f %c %.2f = \n" ,i, cur_barckets1 , number5 , cur_operation1 , number6 , cur_barckets2 , cur_operation2 , number7 , cur_operation3 , number8 );
                }
                else
                {
                    fprintf( fp,"NO. %2d : %.2f %c %.2f %c %.2f %c %.2f = \n" ,i, number5 , cur_operation1 , number6, cur_operation2 , number7 , cur_operation3 , number8 );
                }
            }
            else
            {
                if(Arithmetic_ifbrackets)
                {
                    fprintf( fp,"NO. %2d : %c %d %c %d %c %c %d %c %d = \n" ,i, cur_barckets1 , number1 , cur_operation1 , number2 , cur_barckets2 , cur_operation2 , number3 , cur_operation3 , number4 );
                }
                else
                {
                    fprintf( fp,"NO. %2d : %d %c %d %c %d %c %d = \n" ,i, number1 , cur_operation1 , number2, cur_operation2 , number3 , cur_operation3 , number4 );
                }
            }
        }
    }
    else
    {
        perror(FILE_PATH);
        exit(-1);
    }
    fprintf( fp,"+--------------------------------------------------------------------------------------+\n");
    fprintf( fp, "\n");
}

void showExit()
{
    cout<<"����������������������������������������������������������������������������������������"<<endl;
    cout<<"��                                                                                    ��"<<endl;
    cout<<"��                      ��ϲ��������������ϰ���Ѿ��ɹ����ɣ�                          ��"<<endl;
    cout<<"��                                                                                    ��"<<endl;
    cout<<"��                          лл����ʹ�ã���ӭ���´�������                            ��"<<endl;
    cout<<"��                                                                                    ��"<<endl;
    cout<<"����������������������������������������������������������������������������������������"<<endl;
    cout << "�밴ȷ�ϼ��˳���" << endl;
}
int main()
{   
    srand((unsigned)time(NULL));
    fp = fopen(FILE_PATH, "rt+");
    int Arithmetic_iffile;
    menu();
    Arithmetic_iffile=menu5();
	showMenu();    //��ӭ����
	if(!Arithmetic_iffile)
		Arithmetic_Output_Screen();//��Ļ�������
    else
		Arithmetic_Output_File();  //�ı��������
	showExit();    //�˳�����
	return 0;
} 
