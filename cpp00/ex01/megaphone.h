/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:46:06 by davmoren          #+#    #+#             */
/*   Updated: 2026/01/26 17:50:35 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_MEGAPHONE_H
#define CPP_MEGAPHONE_H

#include "contact.h"

class megaphone
{
private:
  Contact *contact[8];
  int     oldest_index;
public:
  megaphone();
  ~megaphone();
  void searh(std::string name);
  void add(void);
  void deletecontact(int i);
};

#endif // CPP_MEGAPHONE_H