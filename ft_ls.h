/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpytienk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:07:36 by mpytienk          #+#    #+#             */
/*   Updated: 2018/01/11 10:07:39 by mpytienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef	struct ttysize	t_tsize;

# define LS_A	1
# define LS_RA	2
# define LS_L	4
# define LS_R	8
# define LS_T	16
# define LS_D	32
# define LS_S	64
# define LS_1	128
# define LS_O	256

# define SIX_M  15778463

typedef struct			s_file
{
	blkcnt_t			blocks;
	mode_t				mode;
	nlink_t				nbr_link;
	uid_t				user_id;
	gid_t				group_id;
	off_t				size;
	dev_t				st_rdev;
	time_t				time;
	char				*name;
	char				*full_path;
	int					lblocks;
	int					lsize;
	int					lname;
	int					llink;
	int					llen;
	int					luname;
	int					lgname;
}						t_file;

typedef	struct			s_mylist
{
	t_file				*cont;
	struct s_mylist		*next;
}						t_mylist;

int						pars_mod(char **argv, int *mod);
void					display_usage(const char c);
void					display_errno(const char *s);
int						lst_add(char *path, char *name, t_mylist **lst);
void					lst_del(t_mylist *lst);
t_mylist				*init_lst(char **tab, int ac);
t_mylist				*read_folder(char *path, char *name, int options);
int						bypass(t_mylist *ini_list, int flags, int fin, int ar);
void					sort_mod(t_mylist *lst, int flags);
int						ascend_name(t_file *a, t_file *b);
int						descending_name(t_file *a, t_file *b);
int						ascend_time(t_file *a, t_file *b);
int						descending_time(t_file *a, t_file *b);
void					display_path(char *path, int *n, int ac);
void					display(t_mylist *lst, int flags);
void					short_form(t_mylist *lst, int flags);
void					putnchr(int len, char c);
void					strspc(char *str, int n);
void					display_total(t_mylist *lst);
void					display_time(time_t time);
void					put_indent_number(int len, long long int value);
void					set_len(t_mylist *lst, int flags);
int						get_link_len(t_mylist *lst);
int						nmbr_len(long long int i);
void					long_form(t_mylist *tmp, t_mylist *lst, int flag);
void					read_link(t_file *nod);
void					put_indent_str(char *str, int len);
int						get_luname_len(t_mylist *lst);
int						get_lgname_len(t_mylist *lst);
void					display_ltime(t_file *file);
int						init_display(t_mylist *lst, int flags);
long long int			list_len(t_mylist *lst);

#endif
