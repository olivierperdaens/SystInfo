# Listes chaînées: concepts de base
Une liste chaînée est une structure de données permettant de représenter une séquence d’éléments. Dans cet exercice, une liste chaînée sera représentée par un pointeur sur la structure suivante:

```
typedef struct node {
  int value;
  struct node *next;
} node;
```
La liste vide est représentée par un pointeur nul. Le but des questions suivantes est de vous familiariser avec les listes chaînées en C. (Remarque : vous ne devez jamais traiter le cas des listes contenant un cycle.)

Question 1 : longueur d'une liste chainée
------

Écrivez le corps de la fonction __size_t length(node *list)__, qui doit renvoyer le nombre d’éléments se trouvant dans la liste.

Question 2: Compter les éléments d’une liste chaînée
------

Écrivez le corps de la fonction __size_t count(node *list, int value)__, qui doit renvoyer le nombre d’éléments dont la valeur est value se trouvant dans la liste.

Question 3: Rajouter un élément
------
Écrivez le corps de la fonction __int push(node **list, int value)__, permettant de rajouter un élément au début d’une liste.

Le premier argument est un pointeur sur une liste. La fonction doit remplacer la liste pointée par une nouvelle liste où a été rajouté un élément.

La fonction doit renvoyer ``0`` si elle réussit et une valeur négative si elle n’arrive pas à allouer de la mémoire.

Question 4: Supprimer un élément
------
Écrivez le corps de la fonction __int pop(node **list)__, permettant de supprimer le premier élément d’une liste et d’en renvoyer la valeur.

Le premier argument est un pointeur sur une liste. Vous pouvez supposer que cette liste ne sera jamais vide. La fonction doit remplacer la liste pointée par une liste où le premier élément a été supprimé.


Question 5: Libérer une liste chaînée
------
Écrivez le corps de la fonction __void free_list(node *list)__, permettant de libérer tous les nœuds d’une liste.
