/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnagoshi <tnagoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:28:31 by tnagoshi          #+#    #+#             */
/*   Updated: 2021/03/24 18:28:42 by tnagoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int     main(int ac, char **av)
{
    int     flag_error;

    flag_error = 0;
    // 引数のエラー出力
    if (ac != 2 || (ac == 3 && ft_strncmp(av[2], "--save", 7) == 0))
        arg_error();
    // rtファイルの読み込み
    // raycastingの開始
    // フリーする
    //メッセージを受け取ったら、エラー出力
    return (0);
}