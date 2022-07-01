/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupFree_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:38:34 by sumjang           #+#    #+#             */
/*   Updated: 2022/06/30 16:38:35 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dupFree_exit(char *message, int isError, t_arg *arg)
{
	if (ft_strncmp("infile", *message, 6) == 0)
	{
		free(arg->infile);
		arg->infile = NULL; // 댕글링 포인터
		printf("infile 메모리 해제 성공 ~!"); //////삭제 해야함
	}
	else if (ft_strncmp("outfile", *message, 7) == 0)
		free(arg->outfile);
	free(arg);
	perror(message);
	exit(isError);
}
