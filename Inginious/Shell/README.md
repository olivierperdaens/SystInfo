# Écrire un shell

Le shell est un outil dans les systèmes UNIX qui vous permet facilement exécuter d’autres programmes, et même de les combiner de façon intelligente : vous pouvez, par exemple, utiliser __grep foo fichier__ pour trouver les lignes qui contiennent __foo__ dans un fichier, __wc -l fichier__ pour compter le nombre de lignes dans un fichier ; mais en les combinant, on peut écrire __grep foo fichier | wc -l__ pour compter le nombre de lignes qui contiennent dans un fichier.

Dans cet exercice, vous allez implémenter la partie du shell qui exécute une commande ou qui en combine deux. (Remarque : toutes les tableaux d’arguments passés à vos fonctions contiennent comme premier élément le chemin vers l’exécutable et comme dernier élément __NULL__).

Question 1: Exécution simple
------
Écrivez le corps de la fonction __int run_command(const char *path, char * const argv[])__ qui lance l’exécutable qui se trouve dans __path__ avec les arguments stockés dans __argv__, et renvoie le code de retour de la commande qui a été exécutée.

Question 2: Pipe
------
L’opérateur __|__ est appelé pipe (ce qui devrait vous aider à trouver une fonction utile pour répondre à cette question…). Il permet de connecter la sortie d’une commande (par exemple __grep foo fichier__) à l’entrée d’une autre (par exemple __wc -l__).

Écrivez le corps de la fonction __int run_pipe(const char *path_a, char * const argv_a[], const char *path_b, char * const argv_b[])__ qui crée un processus A en lance l’exécutable __path_a__ avec les arguments stockés dans __argv_a__ et un processus B (qui utilise __path_b__ et __argv_b__) en connectant la sortie du processus A à l’entrée d’un processus B. La fonction doit renvoyer le code de retour du processus B.

Question 3: ET logique
------
L’opérateur ``&&`` peut servir de ET logique en shell. Il permet de n’exécuter une commande que si le code de retour d’une autre commande est égal à zéro.

Écrivez le corps de la fonction __int run_and(const char *path_a, char * const argv_a[], const char *path_b, char * const argv_b[])__ qui crée un processus A (comme dans la question précédente) puis, si le code de retour est égal à 0, un processus B (à nouveau comme dans la question précédente) et renvoie le code de retour du processus B, ou celui de A s’il n’est pas nul.

Question 4: Rediriger la sortie
------
Parfois, il est utile de rediriger la sortie standard vers un fichier pour sauvegarder le résultat d’une commande. Cela peut se faire en utilisant la syntaxe suivante : __cat file1 file2 > new_file__. Après l’exécution de cette commande, le fichier __new_file__ contient le contenu de __file1__ suivi de celui de __file2__.

Écrivez le corps de la fonction __int run_redirected(const char *path, char * const argv[], const char *output_path)__ qui lance un processus qui exécute le programme __path__ avec les arguments stockés dans __argv__, en redirigeant la sortie vers le fichier __output_path__. La fonction doit renvoyer le code de retour du processus.

Si le fichier __output_path__ existe déjà, la fonction doit remplacer son contenu par la sortie de la commande.
