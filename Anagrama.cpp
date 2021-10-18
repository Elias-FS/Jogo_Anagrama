#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>


using namespace std;

///Prototipar funções aqui
void Cabecalho();
void Banco_de_Palavras();
void Quadro_Letras();
void Verifica_Palavra();



///Código principal
int main ()
{
  int acertos = 0, erros = 0, opcao;
  string SimNao;
  char palavra[10];



  Cabecalho();
  do
  {
    cout << "Digite uma opcao: ";
    cin >> opcao;

    switch (opcao)
    {
      case 1:
        
        Cabecalho();
        Verifica_Palavra();
        system("clear||cls");
        Cabecalho();
        break;
        
      case 2:
        system("clear||cls");
        Cabecalho();
        Banco_de_Palavras();
        break;
    }
  }while (opcao != 0);
  system("clear||cls");
  cout<<"=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#";
  cout << "\n\n\n\n\t\t\tFIM DE JOGO!\n\n\n\n";
  cout<<"=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#";
  
}


///Cabeçalho do programa
void Cabecalho()
{
    cout<<"=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#";
    cout<<"\n J O G O   A N A G R A M A";
    
    cout<<"\n\n\t Regras: ";
    cout<<"\n\t\t> 1 - Forme palavras com as letras do quadro.";
    cout<<"\n\t\t> 2 - Total de 30 palavras.";
    cout<<"\n\t\t> 3 - 6 tentativas erradas o jogo termina.";
    cout<<"\n\t\t> 4 - Ignore a acentuacao e palavras no plural.\n";

    cout << "\n\t\tJogue e veja em qual nivel voce esta!";
    cout << "\n\t\tINICIANTE / INTERMEDIARIO / AVANÇADO / LENDARIO";
    
    cout<<"\n\n B O A    S O R T E ! ! !";
    cout<<"\n=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n";
        cout << "\nM E N U   D E   O P C O E S\n\n";
        cout << "\t\t(1) - Iniciar jogo\n";
        cout << "\t\t(2) - Mostrar banco de palavras\n";
        cout << "\t\t(0) - Sair do programa\n";
    cout<<"\n=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#\n";
}


///Quadro de letras
void Quadro_Letras()
{
    int i,j;
    cout<<"\n\t\t\t    QUADRO DE LETRAS\n\n";
    char quadro[6][4] = {{'P','O','G','T'},
                         {'R','E','T','A'},
                         {'B','U','N','V'},
                         {'L','I','D','J'},
                         {'D','A','S','C'},
                         {'C','M','B','E'}};
    for(i = 0; i<6; i++)
    {
      cout<<"\t\t";
      for(j = 0; j<4; j++)
      {
        cout <<"\t"<<quadro[i][j];
      }
      cout<<"\n";
    }
}

///Banco de palavras
void Banco_de_Palavras()
{
    
    int i, j, vet[6][5];
    char palavras[6][30][10] = {{"BOTA", "DADO","LARANJA", "SACO","DEDO"},
                                {"BOLA","CASA","CASCO","VASO","OBRA"},
                                {"ARTE","UVA","CAO","SAPO","SABAO"},
                                {"TATU","COR","SOL","LUA","PAVE"},
                                {"BOIA","BALAO","LADRAO","JOIA","VOLEI"},
                                {"RATO","DARDO","GATO","PATO","MAO"}};
    cout<<"\n\t\t\t   BANCO DE PALAVRAS\n\n";
    for(i = 0; i<6; i++)
    {
      cout<<"\t ";
      
      for(j = 0; j<10; j++)
      {
        cout << setiosflags(ios::left) << setw(10) << palavras[i][j];
      }
      cout<<"\n\n";
    }
}

///Verificacao de acertos
void Verifica_Palavra()
{
  char digitado[10];
  bool vd;
  int erros = 0, acertos = 0, i;
  string palavrasAc[30];
  string palavras[30] = {"BOTA", "DADO","LARANJA", "SACO","DEDO",
                         "BOLA","CASA","CASCO","VASO","OBRA",
                         "ARTE","UVA","CAO","SAPO","SABAO",
                         "TATU","COR","SOL","LUA","PAVE",
                         "BOIA","BALAO","LADRAO","JOIA","VOLEI",
                         "RATO","DARDO","GATO","PATO","MAO"};

                     
  while (erros <= 5 && acertos <= 29)
  {
    system("clear||cls");
    cout << "\n\n";
    Quadro_Letras();
    vd = false;
    cout<<"\n\t>>> Acertos (" << acertos << " de 30) e Erros (" << erros << " de 5)\n";
    cout << "\n\tDigite a palavra encontrada: ";
    cin >> digitado;
    
    for (i = 0; i < 30; i++)
    {
        digitado[i] = toupper(digitado[i]);
    }

    for(i=0; i<30; i++)
    {
      if (digitado == palavras[i] && digitado != palavrasAc[i])
      {
        acertos++;
        cout << ">>>Acertou a palavra " << palavras[i] << "<<<";
        palavrasAc[i] = palavras[i];
        vd = true;

        if (acertos == 5)
        {
          cout << "\t5 ACERTOS!! Voce atingiu o nivel: INICIANTE";
        }
        if (acertos == 10)
        {
          cout << "\t10 ACERTOS!! Voce atingiu o nivel: INTERMEDIARIO";
        }
        if (acertos == 20)
        {
          cout << "\t20 ACERTOS!! Voce atingiu o nivel: AVANÇADO";
        }
        if (acertos == 29)
        {
          cout << "\t>>> LENDÁRIO !! SE ACERTAR A ULTIMA PALAVRA, VOCÊ VENCERA O JOGO E SERA REDIRECIONADO PARA O INÍCIO, PODENDO VER TAMBEM O BANCO DE PALAVRAS DO JOGO <<<";
        }
      }
    } 
    if (vd == false)
    {
      erros++; 
      vd = false;
      if (erros == 5)
        {
          cout << "\n!!! SE ERRAR MAIS UMA VEZ, VOCE PERDERA E SERA REDIRECIONADO PARA O INICIO !!!";
        }
    }
  }
}