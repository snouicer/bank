#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    time_t  now = time(NULL);
   //system("COLOR F2"); 
    printf("==============================================================\n");
    printf("\t%s", ctime(&now));
    printf("\t-------------------------\n");
    printf("\tNous vous souhaitons la bienvenue / Welcome \n");
    printf("\t------------------------------------------------------\n");
    printf("\tVeuillez inserez votre carte / Please insert your card\n");
    int pin=1234, entrerPin, cpt=0, option, qt=1, multiple=10,continueTransaction=1;
    float solde=1000;
// Mot de pass-------------------------------------------------
    while (pin != entrerPin)
    {  
        printf("\n\tVeuillez composez votre code: ");
        printf("\e[0;37m");//blanc
        printf("\e[47m");  
        scanf("%d",&entrerPin);
       printf("\e[0m");
        if(entrerPin!=pin){
            printf("\a");// beep sur mac     
            printf("\tVotre code est erroné!!!\n");
        }
        cpt++;
        if(cpt==3 && pin !=entrerPin){
            printf("\n\tVeuillez contactez votre banque!!!\n");
            printf("------------------------------------------------------------\n");
            exit(EXIT_FAILURE);
        } 
    }
// Operation-------------------------------------------------
    while (continueTransaction==1)
    {
         /* code */
    printf("\x1b[0m");
    printf("\t============================================================\n");
    printf("\t-----------------Opérartion--------------------\n");
    printf("\t1: Info Solde \n");
    printf("\t2: Retrait \n");
    printf("\t3: Dépot \n");
    printf("\t4: Retirez ma carte\n");
    printf("\t----------------------------------------------------\n");
    printf("\tChoisissez une option: ");
    scanf(" %d",&option);
    printf("\n");
    switch (option)
    {
      case 1:
        printf("\tVotre solde de compte est de %.2f\n\n",solde);
      break;
      case 2:
        while (qt % multiple !=0)
        {
            printf("\tQuel montant voulez vous retirez: ");
            scanf(" %d",&qt);
            if(qt % multiple !=0){
                printf("\tle montant doit etre un multiple de %d \n\n", multiple);
                }   
        } 
          if(solde < qt){
            printf("\tVotre solde est insufisant. Vous disposé de %.2f sur votre compte\n\n",solde);
            qt=1;
            break;
          }else{
            solde=solde-qt;
            printf("\tVotre nouveau solde du compte est de %.2f\n\n", solde);
            break;
          }
      break;
      case 3:
        printf("\tQuelle montant voulez vous déposé: ");
        scanf("%d",&qt);
        solde=qt+solde;
        printf("\n\tVotre nouveau solde du compte est de %.2f\n\n",solde);
        break;

      case 4:
        printf("\tRetirez votre carte\n\n");
        printf("\tMerci de votre visite à bientôt\n");
        printf("\t============================================================\n");
        exit(EXIT_FAILURE);
        break;
      default:
        printf("\a");// beep sur mac
        printf("\tTransaction invalid\n\n");
    }
    printf("\t============================================================\n");
    printf("\tVoulez vous faire une autre opération? 1[Yes] 2[No]:");
    scanf("%d",&continueTransaction);
    printf("\n");
    }
    printf("\tMerci de votre visite à bientôt\n");
    printf("--------------------------------------------------------------\n");
}

