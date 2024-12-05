#include "day1.h"

long long   get_similarity(List *list1, List *list2) {
    long long   sim;
    size_t      count;
    List        *lp1;
    List        *lp2;

    lp1 = list1;
    lp2 = list2;
    sim = 0;
    while (lp1) {
        count = 0;
        while (lp2) {
            if (lp1->num == lp2->num) {
                count++;
            }
            lp2 = lp2->next;
        }
        sim += lp1->num * count;
        lp1 = lp1->next;
        lp2 = list2;
    }
    return (sim);
}

int main() {
    FILE        *fp;
    char        *buf;
    size_t      size;
    List        *list1;
    List        *list2;
    long long   res;

    list1 = NULL;
    list2 = NULL;
    fp = fopen("input.txt", "r");
    if (!fp)
        exit(1);
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    buf = calloc(sizeof(char), size + 1);
    if (!buf)
        exit(1);
    rewind(fp);
    fread(buf, 1, size, fp);
    make_lists(buf, &list1, &list2);
    ft_sortlst(list1);
    ft_sortlst(list2);
    res = get_similarity(list1, list2);
    printf("The similarity is %ld\n", res);
    ft_lstfree(&list1);
    ft_lstfree(&list2);
    fclose(fp);
    free(buf);
    return 0;
}
