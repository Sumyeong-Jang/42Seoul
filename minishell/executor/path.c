#include "../include/executor.h"

char	*get_cmd_path(t_cmd *cmd, t_env *env_head);
static char	*get_absolute_path(t_cmd *cmd, char *env_path);
static void	free_path(char **path);

char	*get_cmd_path(t_cmd *cmd, t_env *env_head)
{
	char	*ret;
	char	*env_path;

	ret = NULL;
	env_path = ft_getenv(env_head, "PATH");
	if (env_path != NULL)
		ret = get_absolute_path(cmd, env_path);
	if (ret == NULL && is_exist_file(cmd->argv[0]))
		return (ft_strdup(cmd->argv[0]));
	return (ret);
}

static char	*get_absolute_path(t_cmd *cmd, char *env_path)
{
	char	*ret;
	char	*slash;
	char	**path;
	int		i;

	i = 0;
	path = ft_split(env_path, ':');
	slash = ft_strjoin("/", cmd->argv[0]);
	while (path[i])
	{
		ret = ft_strjoin(path[i], slash);
		if (is_exist_file(ret))
			break ;
		free(ret);
		++i;
	}
	free(slash);
	if (path[i] == NULL)
		ret = NULL;
	free_path(path);
	return (ret);
}

static void	free_path(char **path)
{
	size_t	i;

	i = 0;
	while (path[i])
		free (path[i++]);
	free (path);
}