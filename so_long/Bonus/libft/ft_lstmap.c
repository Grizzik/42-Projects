
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*tmp;

	if (!f || !del)
		return (NULL);
	new_head = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			del(tmp->content);
		ft_lstadd_back(&new_head, tmp);
		lst = lst->next;
	}
	return (new_head);
}
