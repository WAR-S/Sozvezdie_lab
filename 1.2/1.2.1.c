#include <stdio.h>
//#include <stdbool.h>
 
struct card
{
    enum {spades, clubs, diamonds, hearts} suit;
    enum {six, seven, eight, nine, ten, jack, queen, king, ace} value;
} c1, c2;
 
int enter_card_suite()
{
    int suit;
    int wrongSuit;
 
    do
    {
        char suitSymbol;
        printf("Please enter suit symbol for a trump (s, c, d or h): ");
        scanf("%c", &suitSymbol);
        getchar();
        wrongSuit = 0;
 
        switch (suitSymbol)
        {
            case 's':  suit = spades; break;
            case 'c':  suit = clubs; break;
            case 'd':  suit = diamonds; break;
            case 'h':  suit = hearts; break;
            default:
                printf("Wrong suit symbol '%c'.\n", suitSymbol);
                wrongSuit = 1;
        }
    }
    while (wrongSuit);
 
    return suit;
}
 
int enter_card_value()
{
    int value;
    int wrongSuit;
 
    do
    {
        char suitSymbol;
        printf("Please enter value symbol for a trump (6, 7, e, n, t, j, q, k, a): ");
        scanf("%c", &suitSymbol);
        getchar();
        wrongSuit = 0;
 
        switch (suitSymbol)
        {
            case '6':  value = six; break;
            case '7': value  = seven; break;
            case 'e':  value = eight; break;
            case 'n':  value = nine; break;
            case 't':  value = ten; break;
            case 'j':  value = jack; break;
            case 'q':  value = queen; break;
            case 'k':  value = king; break;
            case 'a':  value = ace; break;
            default:
                printf("Wrong suit symbol '%c'.\n", suitSymbol);
                wrongSuit = 1;
        }
    }
    while (wrongSuit);
 
    return value;
}
 
 
int kick (struct card c1,struct card c2, int cs)
{
    if (((c1.suit==c2.suit)&&(c1.value>c2.value)) || ((c1.suit==cs)&&(c2.suit!=cs)))
    return 1;
     else return 0;     
}
 
int main()
{
 
    printf("Suit card 1 - ");
    c1.suit = enter_card_suite();
 
    printf("Value card 1 - ");
    c1.value = enter_card_value();
 
    printf("Suit card 2 - ");
    c2.suit = enter_card_suite();
 
    printf("Value card 2 - ");
    c2.value = enter_card_value();
 
 
    int cs = enter_card_suite();
 
    printf("Trump suit (as integer): %d\n", cs);
 
    if (c1.suit == cs) puts("First card is a trump.");
    if (c2.suit == cs) puts("Second card is a trump.");
    if ((c1.suit!=cs)&&(c2.suit!=cs)) puts("No trunp card.");
    printf("Gets card 1 card 2?\n" );
    if (kick == 0) printf("No."); 
    else printf ("Yes.");
}
