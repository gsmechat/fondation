# fondation
Project C Fondation TIC

Prélude à la fondation
Après plus d'une décennie à errer dans les confins de l'espace vous atterrissez sur une planète bien singulière : Trantor
Votre mission consistera à faire vos premiers pas sur cette planète pauvre en ressource et dirigée par des scientifiques
suivant aveuglement un principe instauré par leur chef spirituel Hari Seldon, la psychohistoire !


Langage à utiliser : C

Nom du binaire à rendre : fondation

Makefile : Obligatoire

Libraries autorisées : Ncurses, Gtk+, SFML, SDL (pour la partie graphique uniquement)

Fonctions autorisées : malloc, free, read, open, write, perror, close, htons, inet_addr, fonctions de création et de manipulation des sockets TCP (socket, connect) à l'exception de send et recv

Toutes les fonctions qui ne sont pas explicitement autorisées sont interdites. Utilisez le forum si vous avez des doutes.
Votre programme doit compiler et fonctionner sans erreurs sous Debian Wheezy.
Break, switch case, exit() interdits.
Vous devez coder impérativement à la norme
Votre projet doit compiler avec les flags -W -Wall -Werror
Si vous utilisez votre libmy, elle doit être complilée séparément et présente dans votre répertoire de rendu
Consignes
Vous devez créer un programme capable de communiquer avec un serveur via les sockets TCP.
Le serveur vous est fourni. Vous devrez respecter le shéma de conversation suivant : 

Description commande	Commande	Réponse	Description réponse
Authentification	/auth [prénom]:[nom]\n	/ok\n	Authentification réussie
Liste des habitants	/list\n		Envoi la liste des habitants de Trantor*
Message de Hari Seldon	/hs\n		Envoi un message de Hari Seldon
Qu'est-ce que la psychohistoire ?	/psychohistory\n		Définition de la notion
Statut habitant	/getstatus [prénom]:[nom]\n		Envoi le statut de l'habitant
Afficher infos personnelles	/me\n		Envoi information de l'utilisateur authentifié
Changer son statut	/setstatus [nouveau statut]\n	/ok\n	Changement de statut
Votre programme doit quitter proprement via la commande : /bye\n
Cette commande ne doit pas être envoyée au serveur. Elle doit provoquer la déconnexion de votre socket et la fermeture de votre client.
Vous devez ignorer les commandes de plus de 250 charactères. En revanche les réponses serveur peuvent être arbitrairement grandes, vous ne devez pas les tronquer.

Si une commande échoue ou est inconnue, vous recevrez : /ko\n

Le client doit se lancer par le biais de la commande suivante :

$> ./fondation --ip [n'importe quelle ip] --port 4242
*La liste des habitants est représentée par une chaine de charactères dans laquelle les habitants sont séparés par des #
Toutes les réponses du serveur seront terminées par un \n
Les crochets "[]" ne doivent pas être présents, ils symbolisent les données que vous devez fournir.
Vous ne devez pas rajouter vous-mêmes les '\n' à la fin de vos commandes. Ils représentent la touche entrer de votre clavier lors de la saisie.
N'hésitez pas à utiliser telnet ou netcat pour tester le comportement du serveur et adapter le comportement de votre client
Procédez par étape, ne cherchez pas à tout faire d'un coup
Faites des tests unitaires
Utilisez subversion pour faire du versioning et pas seulement pour faire votre rendu
Vérifiez les valeurs de retours de vos fonctions et faites des returns en cascade
N'hésitez pas à utiliser des macros judicieusement pour rendre votre code plus lisible

    Example:

    int     main()
    {
    if ((my_func(42)) == EXIT_FAILURE)
    {
    perror(__FUNCTION__);
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

 Les macros __FUNCTION__ et __LINE__ sont prédéfinies aucune inclusion n'est nécessaire
 Les macros EXIT_FAILURE et EXIT_SUCCESS nécessitent l'inclusion de <stdlib.h>
Vous devez afficher les données envoyées par le serveur. L'esthétisme de l'affichage sera pris en compte dans la notation.
Vous êtes libre de faire un affichage en ligne de commande. Ou pour les plus hardis d'entre vous, de créer une interface graphique.

Bon courage Trantoriens !
