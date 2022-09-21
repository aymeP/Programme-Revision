# Programme-Revision
## Présentation

Ce projet est un programme de révision pour l'apprentissage des langues en C. 


Les mots en français et leurs traductions (singulier et pluriel) sont enregistrés dans un fichier txt.

Au lancement, le programme charge le fichier txt.



L'utilisateur peut lancer un exercice et choisir le nombre de questions qui lui seront posées. 

Une question consiste à traduire le mot demandé. L'utilisateur a trois tentatives pour trouver la bonne traduction.

A la fin de l'exercice, le score de l'utilisateur est affiché.    





## Personnalisation
### Création du fichier de mots
* Commencer par remplir un fichier avec le format suivant :

  ```MOT_FRANCAIS-MOT_AUTRE_LANGUE-MOT_AUTRE_LANGUE_PLURIEL*```

* Attention à bien séparer les mots par un - et à finir la ligne par *. Si un mot est composé et contient un tiret, il est nécessaire de le remplacer, par un underscore ou autre.


### Ajout du fichier au programme

* Mettre le fichier précédemment créé dans le dossier ```archive mot```.

* Modifier le fichier ```parametres.h``` en remplaçant la valeur de la macro ```adresseFichier``` par le lien vers le fichier précédemment créé et ajouté.

* Il est aussi possible de modifier le nombre de mots contenus dans le fichier (200 max) et leur longueur maximale (50) si ces valeurs ne conviennent pas.

### Modification du fichier 
* Le fichier de mots peut être modifié à la main ou depuis le programme où il est possible d'ajouter et de modifier les mots et leurs traductions.

