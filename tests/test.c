/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:10:53 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/23 18:32:39 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/cub3d.h"
# include <criterion/criterion.h>
# include <criterion/internal/assert.h>
# include <criterion/internal/test.h>
# include <criterion/redirect.h>

Test(suite, Test)
{
    // cr_redirect_stdout();
    cr_assert(is_floor_or_ceiling('C'));
}