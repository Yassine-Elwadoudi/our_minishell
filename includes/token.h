/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:36:54 by asabri            #+#    #+#             */
/*   Updated: 2023/07/06 01:26:06 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
#define TOKEN_H

#include "./minishell.h"
#include "./ft_malloc.h"

#include <stdbool.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum {
    WORD,
    DOUBLE_QUOTE,
    SINGLE_QUOTE,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    END
} t_flgs;

// Token structure
typedef struct s_token {
    char *token;
    t_flgs type;
    struct s_token *prev;
    struct s_token *next;
    struct s_token *bottom;
    bool hd;
    bool expand;
} t_token;

// typedef enum s_flgs
// {
// 	WORD = 0,
// 	DQ = 1,
// 	SQ = 2,
// 	PIPE = 3,
// 	RIN = 4,
// 	ROUT = 5,
// 	OPAR = 6,
// 	CPAR = 7,
// 	SPACE = 8,
// 	HEREDOC = 11,
// 	APPEND = 12,
// 	SUBSHELL,
// 	REDIR,
// 	SIGHER,
// 	END,
// }					t_flgs;

// typedef struct s_token
// {
//     char *token;
    
//     bool hd;
//     bool  expand;
    
//     t_flgs type;
    
//     struct s_token *next;
//     struct s_token *bottom;
//     struct s_token *prev;

// }               t_token;
typedef struct {
    int i;
    t_token *token;
    bool double_quote;
    bool single_quote;
    bool space;
} t_init;
// typedef struct s_init
// {
//     int i;
//     bool double_quote;
//     bool singl_quote;
//     bool space;
    

//     int unkown;
//     int cp;
//     int op;

    
//     struct s_token *token;
//     struct s_token *bottom;
    
// }               t_init;
#endif