/*
 * Pour cet exercice, on vous fourni une structure représentant une fraction
 * - Vous devez implémenter une fonction permettant de comparer 2 fractions
 *     (fraction_compare() : la signature vous est fournie).
 * - Vous devez ensuite implémenter une autre fonction qui utilisera qsort et
 *     votre fonction de comparaison pour trier un tableau de fraction_t par
 *     ordre croissant (fraction_sort() : signature fournie).
 * - Vous emploierez ensuite votre fonction fraction_sort() pour écrire une
 *     fonction qui trie un tableau de fraction_t en ignorant les 3 premiers
       et derniers éléments (fraction_sortIgnore3fl() : signature fournie).
 *
 * NB : même si des préconditions sont indiquées, il vaut mieux les vérifier.
 */

/* type représentant une fraction : */
typedef struct {
    int numerateur;
    int denominateur;
} fraction_t;


/*
 * Compare 2 fraction_t
 * Précondition : - les 2 paramètres sont des pointeurs sur des fraction_t valides (Non NULL donc)
 *                - aucun dénominateur ne vaut 0
 * Renvoie : &lt; 0 si la première fraction est plus petite que la seconde
 *           &gt; 0 si la première est plus grande
 *           0 si elles ont la même valeur
 */
int fraction_compare(const void *, const void *);

/*
 * Trie un tableau de fraction_t par ordre croissant
 * Params : - tab est un pointeur vers le permier élément d'un tableau de fraction_t
 *          - len indique le nombre d'éléments contenus dans le tableau
 * Précondition : - tab n'est pas NULL et pointe vers un tableau valide
 *                - len &lt;= à la longueur réelle du tableau
 * Postcondition : tab a été trié par qsort dans l'ordre croissant sur la longueur indiquée
 *                  par len.
 */
void fraction_sort(fraction_t * tab, size_t len);

/*
 * Trie un tableau de fraction_t par ordre croissant en ignorant les 3 premiers et
 *   derniers éléments (en laissent ceux là dans l'ordre où ils se trouvent).
 * Params : - tab est un pointeur vers le permier élément d'un tableau de fraction_t
 *          - len indique le nombre d'éléments contenus dans le tableau
 * Précondition : - tab n'est pas NULL et pointe vers un tableau valide
 *                - len &lt;= à la longueur réelle du tableau
 *                - len vaut au moins 6 (3+3)
 * Postcondition : tab a été trié par qsort dans l'ordre croissant sur la longueur indiquée
 *                  par len en ignorant les 3 premiers et derniers éléments.
 */
void fraction_sortIgnore3fl(fraction_t * tab, size_t len);
