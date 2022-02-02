#include <iostream>
#include <locale.h>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int mod[4][4] = {3,6,8,1,1,4,5,7,2,4,6,8,7,3,5,2};//Base matrix
    int verify[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//Verification matrix
    int resta, shot, i1,j1,i2,j2;//Elements of matrix positions
    int type, origem[4][4],option;//Type variables, clean matrix origin of overturned cards and choice of menu
    bool run = true;

    //Game menu
    while(run)
    {
        system("cls");
        system("color 03");
        cout<<string(3,' ')<<"MENU\n\n";
        cout<<"1 - Jogar\n";
        cout<<"2 - Sobre\n";
        cout<<"3 - Sair\n\n";

        cout<<"Digite sua escolha: ";
        cin>>option;
        cout<<endl;

        switch (option)
        {
            case 1:
            system("color 03");
            cout<<"Game Start" << endl;
            srand(time(NULL));
            type=rand()% 3 + 2;
            cout<<"Tipo = "<<type<<endl;
            Sleep(1000);
            system("cls");

            //Transformation of the origin matrix
            switch(type)
            {
                case 2://Origin matrix*
                for(int i=0; i < 4; i++)
                {
                    for(int j=0; j < 4; j++)
                    {
                        origem[i][j]= mod[i][j];
                    }
                }
                break;
                case 3://First modified matrix
                for(int i=0; i < 4; i++)
                {
                    for(int j=0; j < 4; j++)
                    {
                        origem[i][j] = mod[3-i][j];
                    }
                }
                break;
                case 4://Second modified matrix
                for(int j=0;j < 4; j++)
                {
                    for(int i=0; i < 4; i++)
                    {
                        origem[i][j] = mod[i][3-j];
                    }
                }
                break;
            }
            for(int i=0; i < 4; i++)
            {
                for(int j=0; j < 4; j++)
                {
                    cout<<origem[i][j]<<" ";
                }
                cout<<"\n";
            }
            Sleep(2500);
            system("cls");

            //Game start
            resta = 0; shot = 0;
            while (resta !=24 && shot < 8 )
            {
                resta = resta + 1;
                if(shot < 8)
                {
                    cout<<string(3, ' ')<<"CARTAS\n\n"<< endl;
                    for(int i=0; i < 4; i++)
                    {
                        for(int j=0; j < 4; j++)
                        {
                            if(verify[i][j] == 0)
                            {
                                cout<<"[X]";
                            }else
                            {
                                cout<<" "<<origem[i][j]<<"  ";
                            }
                        }
                        cout<<"\n\n";
                    }
                }
                //First position entry
                cout<<"Digite a primeira carta que você quer abrir, número da linha [0-3] espaço e da coluna [0-3]: ";
                cin>>i1>>j1;

                //Validation of the positions of the existing lines
                while( i1 < 0 || i1 > 3)
                {
                    cout<<"Valor da coluna OK. \n";
                    cout<<"Valor inválido de linha, digite um valor válido de linhas no intervalo de [0-3]: ";
                    cin>>i1;
                }

                //Validation of existing column positions
                while( j1 < 0 || j1 > 3)
                {
                    cout<<"Valor de linha OK. \n";
                    cout<<"Valor inválido de coluna, digite um valor válido de colunas no intervalo de [0-3]: ";
                    cin>>j1;
                }

                //Display of the matrix after entering the value of the positions
                //Checking the displayed characters variable
                for(int i=0; i < 4; i++)
                {
                    if(i != i1)
                    {
                        cout<<"\n[X]  [X]  [X]  [X]\n";
                    }else
                    {
                        cout<<"\n";
                        for(int j=0; j < 4; j++)
                        {
                            if(j != j1)
                            {
                                cout<<"[X] ";
                            }else
                            {
                                cout<<" "<< origem[i][j]<<"  ";
                            }
                        }
                        cout<<"\n";
                    }
                }
                //Second position entry
                cout<<"\nDigite a segunda carta que você quer abrir. número da linha [0-3] espaço da coluna [0-3]: ";
                cin>>i2>>j2;

                //Validation of the position of existing lines
                while(i2 < 0 || i2 > 3)
                {
                    cout<<"Valor da coluna OK.\n";
                    cout<<"Valor inválido de linha, digite um valor válido de linhas no intervalo de [0-3]: ";
                    cin>>i2;
                }

                //Validation of the position of existing columns
                while( j2 < 0 || j2 > 3)
                {
                    cout<< "Valor de linha OK.\n";
                    cout<< "Valor inválido de coluna, digite um valor válido de colunas no intervalo de [0-3]: ";
                    cin>>j2;
                }

                //Verifying if the positions entered are the same as the first letter
                while(i1 == i2 && j1 == j2)
                {
                    cout << "\n\aEsta carta já está aberta. Abra outra carta. número da linha [0-3] espaço da coluna [0-3]: ";
                    cin>>i2>>j2;
                }

                //Display of the matrix after inserting the positions
                //Checking the displayed characters variable
                for(int i=0; i < 4; i++)
                {
                    if(i != i2)
                    {
                        cout<<"\n[X]  [X]  [X]  [X]\n";
                    }else
                    {
                        cout<<"\n";
                        for(int j=0; j < 4; j++)
                        {
                            if(j != j2)
                            {
                                cout<<"[X]";
                            }else
                            {
                                cout<<" "<<origem[i][j]<<"  ";
                            }
                        }
                        cout<<"\n";
                    }
                }
                //Hit and Cheat Verification
                if(shot == 0)
                {
                    if(origem[i1][j1] == origem[i2][j2])
                    {
                        cout<<"\n\nJogada OK \n\n";
                        shot = shot + 1;
                        verify[i1][j1] = 1;
                        verify[i2][j2] = 1;
                    }else
                    {
                        cout<<"\n\aNão desista, tente novamente!\n\n";
                    }

                }else if(origem[i1][j1] == origem[i2][j2])
                {
                    if(verify[i1][j1] == 1 && verify[i2][j2] == 1)
                    {
                        system("cls");
                        cout<<"\nJogada Inválida!";
                        cout<<"\nNão desista, tente novamente!\n\n";
                    }else
                    {
                        cout<<"\n\nJogada OK \n\n";
                        shot = shot + 1;
                        verify[i1][j1] = 1;
                        verify[i2][j2] = 1;
                    }
                }
                cout<<"\nVocê acertou "<<shot<<" pares.\n";
                if(shot < 8)
                {
                    cout<<"\nVocê tem mais " << 24-resta << " jogadas para tentar ganhar o jogo.\n";
                }
                system("pause");
                system("cls");
                }
                if(resta >= 24)
                {
                    cout<<"\n\aVocê Perdeu!!!\a\n";
                    system("pause");
                    system("cls");
                }else
                {
                    cout<<"\n\aParabéns, você venceu!\n";
                    system("pause");
                    system("cls");
                }
                break;
                case 2: //About and rules
                system("cls");
                system("color 03");
                cout<<"SOBRE"<<endl;
                cout<<"\n\nAluno: André Hillesheim Meyer.\n"<<endl;
                cout<<"Desenvolvido: Novembro de 2021.\n"<<endl;
                cout<<"Professora: Cristina Ono Horita.\n"<<endl;
                cout<<"Disciplina: Algoritmos e Programação.\n\n"<<endl;
                cout<<"REGRAS"<<endl;
                cout<<"\n\n- Você tem 24 tentativas para acertar todos os pares das 16 cartas do jogo;\n- Pode-se usar somente o número de linhas de 0 à 3 e de colunas de 0 à 3;\n\n" << endl;
                system("pause");
                system("cls");
                break;
                case 3: //Exit
                system("cls");
                system("color 04");
                cout<<"Saindo..."<<endl;
                run = false;
                break;
            }
        }
    return 0;
}
