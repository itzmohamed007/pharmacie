#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define X 1

//la structure de temps
typedef struct
{
    int year;
    int mon;
    int days;
    int hours;
    int min;
    int sec;
}Time;

//la structure principale:
typedef struct
{
    char nom[15];
    long long code;
    int quantite;
    float prix;
    float prixTTC;
    Time achatdate;
    int vendue;
}Produit;


//les prototypes:
void ajouter(Produit *pointeur, int debut, int fin);
void afficher(Produit *pointeur, int fin);
void trier_prix(Produit *pointeur, int length);
void trier_alphabet(Produit *pointeur, int length);
void achat(Produit *pointeur, int fin);
void recherche(Produit *pointeur, int fin);
void alimenter(Produit *pointeur, int fin);
void etat(Produit *pointeur, int fin);
int supprimer(Produit *pointeur, int fin);
void statistics(Produit *pointeur, int fin);

int main()
{
    printf("CETTE APPLICATION VOUS AIDE A GERER VOTRE PHARMACIE\n\n");
    Sleep(3000);
    //les variables
    int option;//i will use this variable at the principal menu options
    int globale = 0;//this variable will contain the number of all the variables in the stock
    int locale;//and this one will store the number of products that the user want to add

    //les pointeurs
    Produit *tableau = NULL;

    tableau = (Produit*)malloc(sizeof(Produit));
    //when I use realloc later there will be an already created variable and simply I would over write it haha
    do
    {
        system("cls");
        option = 0;
        printf("LE MENU PRINCIPALE\n");
        printf("choisissez le service qui vous plais: \n");
        printf("1.ajouter un produit\n");
        Sleep(X);
        printf("2.ajouter des multiples produits\n");
        Sleep(X);
        printf("3.afficher les produits\n");
        Sleep(X);
        printf("4.acheter des produits\n");
        Sleep(X);
        printf("5.checher un produit\n");
        Sleep(X);
        printf("6.afficher le status de stock\n");
        Sleep(X);
        printf("7.ajouter des produits au stock\n");
        Sleep(X);
        printf("8.supprimer un produit\n");
        Sleep(X);
        printf("9.les statistique\n");
        Sleep(X);
        printf("10.sortir\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            {
                char condition;
                locale = 1;//because the user want to create just one product
                globale += locale;
                tableau = (Produit*)realloc(tableau, globale * sizeof(Produit));

                if(tableau == NULL)
                {
                    printf("erreur lors de l'allocation de la memoire\n");
                    exit(1);
                }

                ajouter(tableau, locale, globale);//fonction de creation

                printf("operation en cours...\n");
                Sleep(2000);

                printf("votre produit a ete ajoute avec succee\n");
                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;

        case 2:
            {
                char condition;
                printf("entrer le nombre des produits que vous voulez ajouter: ");
                scanf("%d", &locale);

                globale += locale;
                tableau = realloc(tableau, globale * sizeof(Produit));

                if(tableau == NULL)
                {
                    printf("error lors de l'allocation de la memoire");
                    exit(1);
                }

                ajouter(tableau, locale, globale);

                printf("operation en cours...\n");
                Sleep(3000);
                printf("vos produits sont ajoute avec succee\n");
                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        case 3:
            {
                printf("choisissez l'ordre d'affichage des produits: \n");
                printf("1.par ordre decroissant \n");
                printf("2.par ordre alphabetic \n");
                scanf("%d", &option);

                switch(option)
                {
                case 1:
                    {
                        char condition;//this variable is here because if i didn't create it the data will be shown and disappeared in no time

                        trier_prix(tableau, globale);//trier les produits
                        afficher(tableau, globale);//afficher les produits trie

                        printf("taper entrer pour revenir au menu principale: ");
                        scanf("%c", &condition);
                        scanf("%c", &condition);

                    break;
                    }
                case 2:
                    {
                        char condition;
                        trier_alphabet(tableau, globale);
                        afficher(tableau, globale);

                        printf("taper entrer pour revenir au menu principale: ");
                        scanf("%c", &condition);
                        scanf("%c", &condition);

                    break;
                    }
                default:
                    {
                        printf("choix invalide\n");
                        Sleep(1000);

                    break;
                    }
                }//end of switch
            }//end of case 3
            break;
        case 4:
            {
                int totale = 0;
                char condition;

                achat(tableau, globale);//fonction d'achat

                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        case 5:
            {
                char condition;

                recherche(tableau, globale);

                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        case 6:
            {
                char condition;
                etat(tableau, globale);
                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        case 7:
            {
                char condition;
                alimenter(tableau, globale);

                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        case 8:
            {
                char condition;
                int check;

                check = supprimer(tableau, globale);
                if(check == 1)
                {
                    globale--;
                    tableau = realloc(tableau, globale * sizeof(Produit));
                }

                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        case 9:
            {
                char condition;
                printf("vous voulez afficher les statistiques\n");

                statistics(tableau, globale);

                printf("taper entrer pour revenir au menu principale: ");
                scanf("%c", &condition);
                scanf("%c", &condition);

            }
            break;
        case 10:
            {
                printf("vous voulez sortir\n");
                free(tableau);//effacer le contenue de la memoire quand l'utilisateur sort de la maniere reguliere
                exit(1);
            }
            break;
        case 100://choix des developpeurs
            {
                printf("choix developpeur: \n");
                char condition;//this variable is here because if i didn't create it the data will be shown and disappeared in no time

                for(int i = 0; i < globale; i++)
                {
                    printf("Produit %d:\n", i + 1);
                    printf("   le nom: %s\n", tableau[i].nom);
                    printf("   le prix: %.2f\n", tableau[i].prix);
                    printf("   le prix TTC: %.2f\n", tableau[i].prixTTC);
                    printf("   la quantite: %d\n", tableau[i].quantite);
                    printf("   la quantite vendue: %d\n", tableau[i].vendue);
                    printf("   le code: %lld\n", tableau[i].code);

                }
                printf("YOU KNOW WHAT TO DO TO GO BACK: ");
                scanf("%c", &condition);
                scanf("%c", &condition);
            }
            break;
        default:
            printf("choix invalide");
            Sleep(1000);
        }//end of switch
    }//end of do...while statement
    while(1);

    return 0;
}


//les fonctions

void ajouter(Produit *pointeur, int debut, int fin)//fonction d'ajout des produits
{
    printf("Veuillez entrer les informations suivants: \n");
    for(int i = fin - debut; i < fin; i++)
    {
        printf("Produit numero %d\n", i + 1);

        printf("le nom: ");
        scanf("%s", &pointeur[i].nom);
        printf("le code: ");
        scanf("%lld", &pointeur[i].code);
        printf("le prix: ");
        scanf("%f", &pointeur[i].prix);
        printf("la quantite: ");
        scanf("%d", &pointeur[i].quantite);
        pointeur[i].prixTTC = pointeur[i].prix * 1.15;
        pointeur[i].vendue = 0;
    }
}

void afficher(Produit *pointeur, int fin)
{
    //loop d'affichage
    printf("affichage en cours...\n");
    Sleep(2000);
    for(int i = 0; i < fin; i++)
    {
        printf("Produit %d:\n", i + 1);
        printf("   le nom: %s\n", pointeur[i].nom);
        printf("   le prix: %.2f\n", pointeur[i].prix);
        printf("   le prix TTC: %.2f\n", pointeur[i].prixTTC);
    }
}

void trier_prix(Produit *pointeur, int length)
{
    if(length > 1)//if there were only one item in the array, there will be no need to sort it
    {
        int condition;//declaration du variable condition
        do
        {
            condition = 0;
            for(int i = 0; i < length - 1; i++)
            {
                if(pointeur[i].prix < pointeur[i + 1].prix)
                {
                    Produit temp;
                    temp = pointeur[i];
                    pointeur[i] = pointeur[i + 1];
                    pointeur[i + 1] = temp;
                    condition++;
                }
            }
        }
        while(condition > 0);
    }
}


void trier_alphabet(Produit *pointeur, int length)
{
    if(length > 1)//if there were only one item in the array, there will be no need to sort it
    {
        int condition;//declaration du variable condition
        do
        {
            condition = 0;
            for(int i = 0; i < length - 1; i++)
            {
                if(strcmp(pointeur[i].nom, pointeur[i + 1].nom) < 0)//une comparaison entre les chraracteres du nom
                {
                    Produit temp;
                    temp = pointeur[i];
                    pointeur[i] = pointeur[i + 1];
                    pointeur[i + 1] = temp;
                    condition++;
                }
            }
        }
        while(condition > 0);
    }
}



void achat(Produit *pointeur, int fin)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int quantite;
    int condition_code;
    int condition_quantite;
    long long code;
    printf("entrer le code du produit que vous voulez l'acheter: ");
    scanf("%lld", &code);

    printf("recherche en cours...\n");
    Sleep(2000);

    for(int i = 0; i < fin; i++)
    {
        condition_code = 0;
        condition_quantite = 0;
        /*
        //if the code that the user has entered is in the list of products
        and if the amount that he wants to buy is less than or equal to the number of products in the stock
        */
        if(pointeur[i].code == code)
        {


            printf("produit trouve !\n");
            condition_code++;
            printf("voici les informations du produits que vous voulez acheter: \n");
            printf("le nom: %s\n", pointeur[i].nom);
            printf("le prixTTC: %.2f\n", pointeur[i].prixTTC);
            printf("la quantite: %d\n", pointeur[i].quantite);
            printf("la quantite vendue: %d\n", pointeur[i].vendue);
            printf("Entrer la quantite que vous voulez acheter: ");
            scanf("%d", &quantite);

            if(quantite <= pointeur[i].quantite)
            {
                pointeur[i].quantite -= quantite;//diminuer la quantite vendue de la quantite initiale
                pointeur[i].vendue += quantite;//ajouter la quantite vendue au nombre des produits vendue

                //enregistrer la date d'achat
                pointeur[i].achatdate.year = tm.tm_year + 1900;
                pointeur[i].achatdate.mon = tm.tm_mon + 1;
                pointeur[i].achatdate.days = tm.tm_mday;
                pointeur[i].achatdate.hours = tm.tm_hour;
                pointeur[i].achatdate.min = tm.tm_min;
                pointeur[i].achatdate.sec = tm.tm_sec;
                printf("operation en cours...\n");
                Sleep(3000);
                printf("operation effectuee avec succee le %d/%.02d/%d", pointeur[i].achatdate.days, pointeur[i].achatdate.mon, pointeur[i].achatdate.year);
                printf(" a %d:%d:%d\n", pointeur[i].achatdate.hours, pointeur[i].achatdate.min, pointeur[i].achatdate.sec);
                condition_quantite++;

                break;
            }//end of if statement
        }//end of global if statement
    }//end of for loop

    if(condition_code == 0)
        printf("le code que vous avez saisie ne correspond a aucun de nos produits\n");
    else if (condition_quantite == 0)
        printf("le quantite que vous voulez acheter n'est pas valable pour le moment\n");
}//end of the function


void recherche(Produit *pointeur, int fin)
{
    int choix;
    long long code;
    int quantite;
    int code_condition;
    int quantite_condition;

    printf("choisir la methode de recherche: \n");
    printf("1.par code\n");
    printf("2.par quantite\n");
    scanf("%d", &choix);

    switch(choix)
    {
    case 1:
        {
            code_condition = 0;
            printf("entrer le code du produit que vous voulez chercher: ");
            scanf("%lld", &code);
            printf("recherche en cours...\n");
            Sleep(3000);

            for(int i = 0; i < fin; i++)
            {
                if(pointeur[i].code == code)
                {
                    printf("produit trouve !\n");
                    printf("voici les informations du produit que vous chercher: \n");
                    printf("le nom: %s\n", pointeur[i].nom);
                    printf("le prixTTC: %.2f\n", pointeur[i].prixTTC);
                    printf("la quantite: %d\n", pointeur[i].quantite);
                    code_condition++;
                    break;
                }
            }//end of if statement
            if(code_condition == 0)
                printf("le produit que vous chercher n'est pas present dans notre depot\n");
        break;
        }
    case 2:
        {
            quantite_condition = 0;
            printf("entrer la quantite que vous chercher: ");
            scanf("%d", &quantite);
            printf("recherche en cours...\n");
            Sleep(3000);

            for(int i = 0; i < fin; i++)
            {
                if(pointeur[i].quantite == quantite)
                {
                    printf("produit trouve !\n");
                    printf("voici les informations du produit que vous chercher: \n");
                    printf("le nom: %s\n", pointeur[i].nom);
                    printf("le prixTTC: %.2f\n", pointeur[i].prixTTC);
                    printf("le code: %lld\n", pointeur[i].code);
                    quantite_condition++;
                    break;
                }
            }//end of if statement
            if(quantite_condition == 0)
                printf("le produit que vous chercher n'est pas present dans notre depot\n");

        break;
        }
    default:
        {
            printf("methode invalide\n");
            break;
        }
    }//end of switch statement
}//end of the function


void alimenter(Produit *pointeur, int fin)
{
    long long code;
    int quantite;
    int condition;

    printf("entrer le code du produit que vous voulez alimenter: ");
    scanf("%lld", &code);
    printf("recherche en cours...\n");
    Sleep(2000);

    for(int i = 0; i < fin; i++)
    {
        condition = 0;
        if(pointeur[i].code == code)
            {
                printf("produit trouve !\n");
                printf("voici les informations du produits que vous voulez alimenter: \n");
                printf("le nom: %s\n", pointeur[i].nom);
                printf("le prixTTC: %.2f\n", pointeur[i].prixTTC);
                printf("la quantite: %d\n", pointeur[i].quantite);
                printf("Entrer la quantite que vous voulez ajouter: ");
                scanf("%d", &quantite);

                pointeur[i].quantite += quantite;
                printf("votre operation est en cours de processus...\n");
                Sleep(2000);
                printf("operation effectuee avec succee\n");
                condition++;
                break;
            }//end of if statement
    }//end of loop
    if(condition == 0)
        printf("le code que vous aver saisie ne correspond a aucun de nos produits\n");
}//end of the function


void etat(Produit *pointeur, int fin)
{
    int condition;
    printf("recherche en cours...\n");
    Sleep(2000);
            for(int i = 0; i < fin; i++)
            {
                condition = 0;
                if(pointeur[i].quantite < 3)
                {
                    printf("produit trouve !\n");
                    printf("le produit numero %d: \n", i + 1);
                    printf("le nom: %s\n", pointeur[i].nom);
                    printf("le prixTTC: %.2f\n", pointeur[i].prixTTC);
                    printf("la quantite: %d\n", pointeur[i].quantite);
                    condition++;
                    break;
                }
            }//end of if statement
            if(condition == 0)
                printf("il ne se trouve aucun produit dont sa quantite est inferieur a 3\n");
}



int supprimer(Produit *pointeur, int fin)
{
    int confirm;
    long long target;
    int condition_recherche;
    printf("entrer le code du produit que vous voulez supprimer: ");
    scanf("%lld", &target);

    printf("recherche en cours...\n");
    Sleep(3000);

    for(int i = 0; i < fin; i++)
    {
        condition_recherche = 0;
        if(pointeur[i].code == target)
            {
                condition_recherche++;
                printf("produit trouve !\n");
                printf("voici les informations du produits que vous voulez supprimer: \n");
                printf("le nom: %s\n", pointeur[i].nom);
                printf("le prixTTC: %.2f\n", pointeur[i].prixTTC);
                printf("la quantite: %d\n", pointeur[i].quantite);

                printf("ATTENTION  la suppression sera definitive est vous ne pourrais pas recuperez ce produit\n");
                printf("pour confirmer l'operation tapez 1: \n");
                printf("pour annuler l'operation tapez 0: \n");
                scanf("%d", &confirm);

                if(confirm == 0)
                {
                    printf("annulation en cours...\n");
                    Sleep(2000);
                    printf("annulation effectuee avec succee\n");
                    break;
                }

                printf("supression en cours... \n");
                Sleep(2000);
                printf("operation affectuee avec succee\n");

                    //cette boucle deplace le produit a supprimer a la fin du tableau
                    for(int indice = i; indice < fin - 1; indice++)
                    {
                        Produit temp;
                        temp = pointeur[indice];
                        pointeur[indice] = pointeur[indice + 1];
                        pointeur[indice + 1] = temp;
                    }
                    return 1;
                break;
            }//end of if statement
    }//end of loop
    if(condition_recherche == 0)
    {
        printf("le produit que vous cherchez n'est pas present dans notre depot pour le moment \n");
        return 0;
    }
}



void statistics(Produit *pointeur, int fin)
{
    int choix;
    int condition;
    float total = 0;
    float moyenne;
    float max;
    float min;

    printf("choisissez l'information que vous voulez savoir a propos des prix des produits vendues cette journee: \n");

    printf("1.le total \n");
    printf("2.la moyenne \n");
    printf("3.le Max \n");
    printf("4.le Min \n");
    scanf("%d", &choix);

    switch(choix)
    {
    case 1:
        {
            printf("operation en cours...\n");
            Sleep(2000);
            for(int i = 0; i < fin; i++)
            {
                condition = 0;
                if(pointeur[i].vendue != 0)//if in this product there were already some pieces that have been sold
                {
                    total += (float)pointeur[i].vendue * pointeur[i].prixTTC;
                    condition++;
                }
            }
            printf("operation effectuee !\n");
            printf("le total des prix des produits vendue cette journee est: %.2f\n", total);

            if(condition == 0)
                 printf("aucun produit est vendue pou le moment\n");
         break;
         }
    case 2:
        {
            float somme_prix = 0;
            float somme_vendue = 0;
            for(int i = 0; i < fin; i++)
            {
                condition = 0;
                if(pointeur[i].vendue != 0)//if in this product there were already some pieces that have been sold
                {
                    somme_prix += (float)pointeur[i].vendue * pointeur[i].prixTTC;
                    somme_vendue += (float)pointeur[i].vendue;
                    condition++;
                }
            }
            moyenne = somme_prix / somme_vendue;
            printf("la moyenne des prix des produits vendue cette journee est: %.2f\n", moyenne);
            if(condition == 0)
                printf("aucun produit est vendue pou le moment\n");

        break;
        }
    case 3:
        {
            printf("operation ne cours...\n");
            Sleep(2000);

            float max = 0;
            for(int i = 0; i < fin; i++)
            {
                if(pointeur[i].vendue > 0)
                {
                    if(pointeur[i].prixTTC > max)
                        max = pointeur[i].prixTTC;
                }
            }
            printf("le produit le plus cher vendue cette journee est: %.2f DH\n", max);
        break;
        }
    case 4:
        {
            printf("operation ne cours...\n");
            Sleep(2000);

            //sorting the product so the smallest price is the first
            int condition;//declaration du variable condition
            do
            {
                condition = 0;
                for(int i = 0; i < fin - 1; i++)
                {
                    if(pointeur[i].prix > pointeur[i + 1].prix)
                    {
                        Produit temp;
                        temp = pointeur[i];
                        pointeur[i] = pointeur[i + 1];
                        pointeur[i + 1] = temp;
                        condition++;
                    }
                }
            }
            while(condition > 0);

            for(int i = 0; i < fin; i++)
            {
                if(pointeur[i].vendue > 0)
                {
                    printf("le prix le plus bas des produits vendue cette journee est: %.2f DH\n", pointeur[i].prixTTC);
                    break;
                }
            }
        break;
        }
    default:
        {
            printf("choix invalide\n");
        break;
        }
    }
}
