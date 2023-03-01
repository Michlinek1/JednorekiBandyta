#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

void zasady();
int losowanie(int monety);

int main() {
    int wybor;
    int monety = 11;
    cout << "Chcesz zobaczyc zasady? (1 = tak , 2 = nie)" << endl;
    cin >> wybor;
    if (wybor == 1) {
        system("cls");
        zasady();
    }
    else {
        cout << "Zaczynamy!" << endl;
        wybor = 0;
        losowanie(monety);
    }
}

void zasady() {
    cout << "Zasady sa proste, jesli wszystkie 3 liczby beda sobie rowne, wygrywasz, inaczej przegrywasz" << endl;
    Sleep(3000);
    system("cls");
    main();
}

int losowanie(int monety) {
    unsigned int czas = unsigned int(time(NULL));
    srand(czas);
    int tab[3] = {};
    int wybor;
    cout << "Masz aktualnie " << monety << " " << ((monety == 1) ? "monete" : "monet") << endl;
    cout << "Wrzuc monete aby zagrac! (1 aby wrzucic)" << endl;
    monety--;
    cin >> wybor;
    if (wybor == 1) {
        for (int i = 0; i <= 2; i++) {
            tab[i] = rand() % 9 + 1;
            cout << tab[i];
        }
        if (tab[0] == tab[1] == tab[2]) {
            cout << "Wygrales, chcesz zagrac jeszcze raz (1 aby zagrac, 2 aby wyjsc do menu, 3 aby wyjsc z gry)";
            cin >> wybor;
            if (wybor == 1) {
                return monety + 1;
            }
            else if (wybor == 2) {
                main();
                //Monety sa ciagle rowne 11
            }
            else if (wybor == 3) {
                exit(1);
            }
        }
        else {
            cout << "Przegrales, chcesz zagrac jeszcze raz (1 aby zagrac, 2 aby wyjsc do menu, 3 aby wyjsc z gry)";
            cin >> wybor;
            if (wybor == 1) {
                return monety;
            }
            else if (wybor == 2) {
                main();
                //Monety sa ciagle rowne 11
            }
            else if (wybor == 3) {
                exit(1);
            }
        }
    }
    else if (monety == 0) {
        cout << "Nie mozesz zagrac";
        return 0;
    }
    return monety;
}


