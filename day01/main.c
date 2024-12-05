#include "day1.h"

void	ft_free(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void    make_lists(char *data, List **list1, List **list2) {
    char    **split_data;
    char    **split_buf;
    List    *new;
    size_t  i;

    i = 0;
    split_data = ft_split(data, '\n');
    while (split_data[i]) {
        split_buf = ft_split(split_data[i], ' ');
        new = ft_lstnew(atoi(split_buf[0]));
        ft_lstadd_back(list1, new);
        new = NULL;
        new = ft_lstnew(atoi(split_buf[1]));
        ft_lstadd_back(list2, new);
        ft_free(split_buf);
        i++;
    }
    ft_free(split_data);
}

long    get_result(List *list1, List *list2) {
    long res;
    List    *lp1;
    List    *lp2;

    res = 0;
    lp1 = list1;
    lp2 = list2;
    while (lp1 && lp2) {
        res += abs(lp1->num - lp2->num);
        lp1 = lp1->next;
        lp2 = lp2->next;
    }
    return (res);
}

int main() {
    FILE    *fp;
    char    *buf;
    size_t  size;
    List    *list1;
    List    *list2;
    long    res;

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
    res = get_result(list1, list2);
    printf("The total distance is %ld\n", res);
    ft_lstfree(&list1);
    ft_lstfree(&list2);
    fclose(fp);
    free(buf);
    return 0;
}