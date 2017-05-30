#ifndef MY_STRSEP_H
#define MY_STRSEP_H

/** Fichier d'énoncé à ne pas modifier ! **/

/** Vous devez ré-implémenter la fonction strsep()
 *  en considérant que delim est un pointeur vers un seul caractère **/

char * my_strsep(char ** stringp, const char * delim);

/** MAN STRSEP()
 * DESCRIPTION
 *
 * Si *stringp est NULL, la fonction strsep() renvoie NULL et ne fait rien d'autre.
 * Sinon, cette fonction prend le premier élément lexical (token) dans la chaîne
 * stringp où les éléments sont séparés par les symboles contenus dans delim. Le
 * mot renvoyé est terminé par un caractère nul `\0' (en écrasant le séparateur)
 * et *stringp est mis à jour pour pointer après le mot. Dans le cas où aucun
 * séparateur n'est trouvé, l'élément extrait est constitué de toute la chaîne
 * *stringp, et *stringp vaut NULL.
 *
 * VALEUR RENVOYÉE
 *
 * La fonction strsep() renvoie un pointeur sur l'élément lexical extrait,
 * c'est-à-dire la valeur originelle de *stringp. stringp. La fonction strsep() a
 * été introduite en remplacement de strtok(), qui ne peut pas traiter les champs
 * vides. Néanmoins strtok() est conforme au C ANSI et est donc plus portable.
 * **/
#endif /* MY_STRSEP_H */#ifndef MY_STRSEP_H
#define MY_STRSEP_H

/** Fichier d'énoncé à ne pas modifier ! **/

/** Vous devez ré-implémenter la fonction strsep()
 *  en considérant que delim est un pointeur vers un seul caractère **/

char * my_strsep(char ** stringp, const char * delim);

/** MAN STRSEP()
 * DESCRIPTION
 *
 * Si *stringp est NULL, la fonction strsep() renvoie NULL et ne fait rien d'autre.
 * Sinon, cette fonction prend le premier élément lexical (token) dans la chaîne
 * stringp où les éléments sont séparés par les symboles contenus dans delim. Le
 * mot renvoyé est terminé par un caractère nul `\0' (en écrasant le séparateur)
 * et *stringp est mis à jour pour pointer après le mot. Dans le cas où aucun
 * séparateur n'est trouvé, l'élément extrait est constitué de toute la chaîne
 * *stringp, et *stringp vaut NULL.
 *
 * VALEUR RENVOYÉE
 *
 * La fonction strsep() renvoie un pointeur sur l'élément lexical extrait,
 * c'est-à-dire la valeur originelle de *stringp. stringp. La fonction strsep() a
 * été introduite en remplacement de strtok(), qui ne peut pas traiter les champs
 * vides. Néanmoins strtok() est conforme au C ANSI et est donc plus portable.
 * **/
#endif /* MY_STRSEP_H */
