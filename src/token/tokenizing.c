/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:31:47 by asabri            #+#    #+#             */
/*   Updated: 2023/07/14 18:33:06 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



// // lst 
// t_token	*ft_lstlst(t_token *lst)
// {
// 	while (lst)
// 	{
// 		if (lst->next == NULL)
// 			break ;
// 		lst = lst->next;
// 	}
// 	return (lst);
// }
// t_token	*ft_lstlst_bottom(t_token *lst)
// {
// 	while (lst)
// 	{
// 		if (lst->bottom == NULL)
// 			break ;
// 		lst = lst->bottom;
// 	}
// 	return (lst);
// }
// void	add_token_back(t_token **lst, t_token *new)
// {
	
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	new->prev = ft_lstlst(*lst);
// 	ft_lstlst(*lst)->next = new;
// 	new->next = NULL;
// }

// t_token *newtoken(t_flgs type,char *tok,int hdoc,int expnd)
// {
//     t_token *node;

//     node = ft_malloc(sizeof(t_token), 1);
//     node->token = tok;
//     node->type = type;
//     node->prev = NULL;
//     node->next = NULL;
//     node->bottom = NULL;
//     node->hd = false;
//     node->expand = false;
//     if (hdoc)
//         node->hd = true;
//     if (expnd)
//         node->expand = true;
//     return (node);
// }
// // --------------------utils--------------------
// char *get_word(char *str, int *index)
// {
//     int j;
//     int i;
    
//     i = *index;
//     j = i;
//     while (str[i] && !ft_strchr("\"\'<>() \t", str[i]))
//         i++;
//     return (*index = i - 1,ft_substr(str,j,i - j));
// }

// char *get_qoute(char *str,int *index,char car)
// {
//     int	i;
// 	int	j;

// 	i = *index;
// 	j = i;
// 	while (str[i] && str[i] != car)
// 		i++;
// 	if (!str[i])
// 		return (*index = i - 1, ft_substr(str, j, i - j));
// 	return (*index = i - 1, ft_substr(str, j, i - j));
// }
// int which_flag(char c ,int flg)
// {
//     char	*str;
// 	int		i;

// 	i = -1;
// 	str = "\"\'|<>()";
// 	while (str[++i])
// 		if (str[i] == c)
// 			break ;
// 	if (flg)
//         i += 7;
// 	return (i + 1);
// }
// void ft_initialize(t_init *init)
// {
//     init->i = -1;
//     init->bottom = 0;
//     init->token = 0;
//     init->unkown = 0;
//     init->cp = 0;
//     init->op = 0;
//     init->double_quote = false;
//     init->singl_quote = false;
//     init->space = false;
// }
// int onlyspace(int i, char *str)
// {
//     while(str[i] && str[i] == ' ')
//         i++;
//     if (str[i])
//         return (0);
//     else 
//         return (1);
// }
// //-----------------------functions that give meanig to the line---------------------------

// void lexer_2(t_init *t, char *str)
// {
//     if(str[t->i] == '\'')
//     {
//         t->singl_quote = !t->singl_quote;
//         if (t->singl_quote == true )
//             printf("sq = true\n");
//     }
//     else if(str[t->i] == '\"')
//         t->double_quote = !t->double_quote;
//     else if(ft_strchr("<>",str[t->i]) && str[t->i] == str[t->i + 1])
//         t->unkown = 1;
//     else if (str[t->i] != '\"' || str[t->i] != '\'')
//         t->space = true;
//     else if (str[t->i] == '(')
//         t->op += 1;
//     else if (str[t->i] == ')')
//         t->cp += 1;
//     if (!onlyspace(t->i,str) && str[t->i] != '\'' && str[t->i] != '\"' 
//         && str[t->i] != ' ' && str[t->i] != '\t')
//         add_token_back(&t->token,newtoken(which_flag(str[t->i],t->unkown),ft_substr(str, t->i,
// 					t->unkown + 1), 0, 0));
//     if (str[t->i] == ' ' || str[t->i] == '\t')
// 	{
// 		while ((str[t->i] == ' ' || str[t->i] == '\t') && str[t->i])
// 			t->i++;
// 		t->i--;
// 	}
// 	t->i += t->unkown;
// }
// void lexer_3(t_init *in, char *tok)
// {
//     if (in->space)
//     {   
//         add_token_back(&in->token,newtoken(WORD, get_word(tok, &in->i),1,1));
//         in->space = false;
//     }
//     else if(!in->space)
//     {
//         in->bottom = ft_lstlst(ft_lstlst_bottom(in->token));
//         in->bottom = newtoken(WORD, get_word(tok, &in->i), 1, 1);
//     }
// }
// void lexer_1(t_init *in, char *tok)
// {
//     if (in->space)
//     {   
//         add_token_back(&in->token,newtoken(WORD, get_qoute(tok, &in->i, tok[in->i - 1]),
// 				(in->double_quote == true), 0));
//         in->space = false;
//     }
//     else if(!in->space)
//     {
//         in->bottom = ft_lstlst(ft_lstlst_bottom(in->token));
//         in->bottom = newtoken(WORD, get_qoute(tok, &in->i, tok[in->i - 1]),
// 				(in->double_quote == true), 0);
//     }
// }


// // main function that use everthing 
// t_token *strtoken(char *line)
// {
//     t_init init;

//     ft_initialize(&init);
//     while (line[++(init.i)])
//     {
//         if ((init.double_quote && line[init.i] =='\"') || (init.singl_quote && line[init.i] == '\''))
//             lexer_1(&init,line);
//         else if (ft_strchr("\"\'<>()\t", line[init.i]))
//             lexer_2(&init,line);
//         else if (!ft_strchr("\"\'<>() \t", line[init.i]) && (!init.double_quote|| !init.singl_quote))
//             lexer_3(&init,line);
//         // printf("%s",init.token->token);
//     }
//     if ((!init.singl_quote || init.double_quote) || (init.op != init.cp))
// 		return (ft_putstr_fd("Syntax : Quote Unfound\n", 2), NULL);
// 	if (init.op != init.cp)
// 		return (ft_putstr_fd("Syntax : Need a parantes\n", 2), NULL);
// 	//add_token_back(&init.token, newtoken(END, ft_strdup("newline"), 0, 0));
//     return (init.token);
// }

// // Function to append a new token to the end of a token list
// void add_token_back(t_token **lst, t_token *new)
// {
//     if (*lst == NULL) {
//         *lst = new;
//     } else {
//         t_token *last = *lst;
//         while (last->next != NULL) {
//             last = last->next;
//         }
//         last->next = new;
//         new->prev = last;
//     }
// }

// // Function to create a new token
// t_token *newtoken(t_flgs type, char *tok, bool hdoc, bool expnd)
// {
//     t_token *node = malloc(sizeof(t_token));
//     node->token = strdup(tok);
//     node->type = type;
//     node->prev = NULL;
//     node->next = NULL;
//     node->bottom = NULL;
//     node->hd = hdoc;
//     node->expand = expnd;
//     return node;
// }

// // Utility function to get a word from a string
// char *get_word(char *str, int *index) 
// {
//     int j = *index;
//     int i = j;
//     while (str[i] && !ft_strchr("\"\'<>() \t", str[i])) {
//         i++;
//     }
//     *index = i - 1;
//     return (strndup(&str[j], i - j));
// }

// // Utility function to get a quoted string from a string
// char *get_quote(char *str, int *index, char car)
// {
//     int i = *index;
//     int j = i;
//     while (str[i] && str[i] != car) {
//         i++;
//     }
//     *index = i - 1;
//     return strndup(&str[j], i - j);
// }

// // Function to determine the flag of a character
// t_flgs which_flag(char c, bool unkown) 
// {
//     if (c == '\"') {
//         return DOUBLE_QUOTE;
//     } else if (c == '\'') {
//         return SINGLE_QUOTE;
//     } else if (c == '|') {
//         return PIPE;
//     } else if (c == '<') {
//         return REDIRECT_IN;
//     } else if (c == '>') {
//         return REDIRECT_OUT;
//     } else if (c == '(') {
//         return LEFT_PARENTHESIS;
//     } else if (c == ')') {
//         return RIGHT_PARENTHESIS;
//     } else if (unkown) {
//         return END;
//     } else {
//         return WORD;
//     }
// }

// // Structure for initialization variables


// // Function to initialize the initialization variables
// void initialize(t_init *init) {
//     init->i = -1;
//     init->token = NULL; 
//     init->double_quote = false;
//     init->single_quote = false;
//     init->space = false;
// }

// // Function to check if the string consists of only spaces
// bool only_spaces(int i, char *str)
// {
//     while (str[i] && str[i] == ' ') {
//         i++;
//     }
//     return str[i] == '\0';
// }
// // Main tokenizing function
// t_token *strtoken(char *line) {
//     t_init init;
//     initialize(&init);

//     while (line[init.i]) {
//         if ((init.double_quote && line[init.i] == '\"') || (init.single_quote && line[init.i] == '\'')) {
//             init.double_quote = !init.double_quote;
//             init.single_quote = !init.single_quote;
//         } else if (strchr("\"\'<>()\t", line[init.i])) {
//             init.space = true;
//             if (init.token != NULL && init.token->prev != NULL && init.token->prev->type == WORD && init.token->prev->next == NULL) {
//                 // Append the current token to the previous token when there is no space between them
//                 char *token_str = strndup(&line[init.i], 1);
//                 size_t len = strlen(init.token->prev->token);
//                 init.token->prev->token = realloc(init.token->prev->token, len + 2);
//                 init.token->prev->token[len] = line[init.i];
//                 init.token->prev->token[len + 1] = '\0';
//                 free(token_str);
//             } else {
//                 add_token_back(&(init.token), newtoken(which_flag(line[init.i], false), strndup(&line[init.i], 1), 0, 0));
//             }
//         } else if (!strchr("\"\'<>() \t", line[init.i]) && (!init.double_quote || !init.single_quote)) {
//             init.space = true;
//             char *word = get_word(line, &(init.i));
//             add_token_back(&(init.token), newtoken(WORD, word, 0, 0));
//         }

//         if (line[init.i] == ' ' || line[init.i] == '\t') {
//             while ((line[init.i] == ' ' || line[init.i] == '\t') && line[init.i]) {
//                 init.i++;
//             }
//             init.i--;
//         }
//         init.i++;
//     }

//     if ((init.single_quote && init.double_quote) || (init.token == NULL)) {
//         fprintf(stderr, "Syntax Error: Invalid quoting\n");
//         return NULL;
//     }

//     add_token_back(&(init.token), newtoken(END, strdup("newline"), 0, 0));

//     return init.token;
// }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////




// Function to append a new token to the end of a token list
void add_token_back(t_token **lst, t_token *new) {
    if (*lst == NULL) {
        *lst = new;
    } else {
        t_token *last = *lst;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
        new->prev = last;
    }
}

// Function to create a new token
t_token *newtoken(t_flgs type, const char *tok, bool hdoc, bool expnd) {
    t_token *node = malloc(sizeof(t_token));
    if (node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->token = ft_strdup(tok);
    node->type = type;
    node->prev = NULL;
    node->next = NULL;
    node->bottom = NULL;
    node->hd = hdoc;
    node->expand = expnd;
    return node;
}

// Utility function to get a word from a string
char *get_word(const char *str, int *index) {
    int j = *index;
    int i = j;
    while (str[i] && !strchr("\"\'<>() \t", str[i])) 
        i++;
    *index = i - 1;
    return strndup(&str[j], i - j);
}
char *get_q(char *str,int *index,char c)
{
    int	i;
	int	j;

	i = *index;
	j = i + 1;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (*index = i - 1, ft_substr(str, j, i -1));
	return (*index = i, ft_substr(str, j, i - 1));
}
// Function to determine the flag of a character
t_flgs which_flag(char c, bool unkown) {
    switch (c) {
        case '\"':
            return DOUBLE_QUOTE;
        case '\'':
            return SINGLE_QUOTE;
        case '|':
            return PIPE;
        case '$':
            return ENV;
        case '<':
            return REDIRECT_IN;
        case '>':
            return REDIRECT_OUT;
        case '(':
            return LEFT_PARENTHESIS;
        case ')':
            return RIGHT_PARENTHESIS;
        default:
            return unkown ? END : WORD;
    }
}



// Function to initialize the initialization variables
void initialize(t_init *init) {
    init->i = -1;
    init->token = NULL;
    init->double_quote = false;
    init->single_quote = false;
    init->space = false;
}

// Main tokenizing function
t_token *strtoken(char *line) {
    t_init init;
    initialize(&init);

    while (line[++init.i]) {
        if ((init.double_quote && line[init.i] == '\"') || (init.single_quote && line[init.i] == '\'')) {
            add_token_back(&(init.token), newtoken(WORD, get_q(line, &init.i, line[init.i]), 0, 0));
            init.double_quote = !init.double_quote;
            init.single_quote = !init.single_quote;
        } else if (ft_strchr("\"\'<>()\t", line[init.i])) {
            init.double_quote = !init.double_quote;
            init.single_quote = !init.single_quote;
            init.space = true;
        } else if (!ft_strchr("\"\'<>() \t", line[init.i]) && (!init.double_quote || !init.single_quote)) {
            init.space = true;
            char *word = get_word(line, &(init.i));
            t_flgs flag = (word[0] == '$') ? ENV : which_flag(line[init.i], 0);
            add_token_back(&(init.token), newtoken(flag, word, 0, 0));
        }
        if (line[init.i] == ' ' || line[init.i] == '\t') {
            while ((line[init.i] == ' ' || line[init.i] == '\t') && line[init.i]) {
                init.i++;
            }
            init.i--;
        }
    }
    if ((init.single_quote || init.double_quote))
        return (ft_putstr_fd("Syntax : Quote Unfound\n", 2), NULL);

    // add_token_back(&(init.token), newtoken(END, strdup("newline"), 0, 0));

    return init.token;
}
