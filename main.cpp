#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;
double poczatek;
double koniec;
char zera;
void SetWindow(int Width, int Height);

main ()
{
    SetWindow(100,25);
    printf("*********Txt number creator by Roballo*********\nVer. 1.4.6.2 \n\nUwaga! Po utworzeniu pliku zostanie on automatycznie otworzony w celu weryfikacji zawartosci.\nPlik jest generowany w tym samym miejscu gdzie znajduje sie program.\n\n");

    do{
    printf("Zakres liczb od ");
    scanf("%lf",&poczatek);
    printf("Do ");
    scanf("%lf",&koniec);
    if (koniec <= poczatek){
    printf("Podany zakres jest nieprawidlowy!\nSprobuj ponownie.\n\n");
        }
    }
    while (koniec <= poczatek);
    string skokl;
    int skok;
    printf("Podaj skok liczbowy(Domyslnie 1):");
    cin.ignore(256,'\n');
    getline(cin, skokl);
    if(skokl.empty())
        skok = 1;
    else{
        skok = atoi(skokl.c_str());
        if(skok==0)
            skok=1;
    }
    printf("Wprowadzic zera wiodace? [N/T] ");
    scanf("%c",&zera);
    if(zera != 'n' and
        zera != 'N' and
        zera != 't' and
        zera != 'T')
        {
            do{
        printf("Nie, nie, nie... To nie sa prawidlowe wartosci...\nMoze naucz sie pisac na klawiaturze a potem sprobujemy jeszcze raz.\n\nWprowadzic zera wiodace? [N/T]\n");
        scanf("%c",&zera);
            }
            while(zera != 'n' and
                zera != 'N' and
                zera != 't' and
                zera != 'T');
        }
    ofstream outfile ("Liczby.txt");
    outfile.precision(0);
    outfile << fixed << "Liczby wygenerowne w zakresie od " << poczatek << " do " << koniec;

    if(zera == 'n' or
       zera == 'N')
       {
    koniec++;
    for(poczatek;poczatek<koniec;)
        {
            outfile << fixed << "\n" << poczatek;
            poczatek=poczatek+skok;
        }
       }
    if(zera == 't' or
       zera == 'T')
        {
            int ilosc_z;
            string ilosc;
            printf("Ilosc dodatkowych zer poprzedzajacych(Domyslnie 0):");
            cin.ignore(256,'\n');
            getline(cin, ilosc);
            if(ilosc.empty())
                ilosc_z = 0;
            else{
                ilosc_z = atoi(ilosc.c_str());
            }
        double koniec2 = koniec;
        int koniec3 = koniec;
        double length = 1;
        while ( koniec3 /= 10 )
            length++;
        length=length+ilosc_z;
        koniec2++;
        for(poczatek;poczatek<koniec2;)
        {
            outfile << fixed << "\n" << setfill('0') << setw(length) << poczatek;
            poczatek=poczatek+skok;
        }
        }
    outfile.close();
    int i;
	printf ("Sprawdzanie gotowosci procesora...");
	if (system(NULL)) puts (" Ok");
	else exit (1);
	printf ("Otwieranie txt...\n");
	i = system ("Liczby.txt");
    return 0;

}
void SetWindow(int Width, int Height)
    {
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
    }

// 1.4.6.2
// -drobne poprawki,
// 1.4.6
// -zmieniono polecenia z iosteream na cstdio,
// -ustawiono wielkość okna,
//
// 1.4.5
// - dodano otwieranie txt po utworzeniu,
// 1.4.4
// Zapomniałem napisać,
