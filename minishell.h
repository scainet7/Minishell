
#ifndef MINISHELL_H
#define MINISHELL_H

# define BLU "\033[34m"
# define GRE "\033[32m"
# define RED "\033[31m"
# define END "\033[0m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft/libft.h"
# include <signal.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_comand
{

}	t_cmd;

typedef struct s_minishell
{
	t_list 	*var;

	int 	exit;
	int 	err;
	int 	*pid;

	char	*line;
}	t_mini;

void	add_history(char *line);
void	ft_freelst(t_list *lst);
void	ft_change_var(t_mini *mini, char *envp);
char	*ft_strjoin_free(char *s1, char *s2, int checkfree);
#endif