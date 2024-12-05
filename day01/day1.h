#ifndef DAY_1_H
#define DAY_1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct list {
    int			num;
    struct list	*next;
}	List;

List	*ft_lstnew(int num);
void	ft_lstadd_back(List **list, List *new);
void	ft_lstfree(List **list);
void	ft_printlst(List *list);
void	ft_sortlst(List	*list);

#endif