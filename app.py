# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    app.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 22:18:22 by aaammari          #+#    #+#              #
#    Updated: 2022/04/27 22:18:56 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import itertools
import subprocess

c = itertools.permutations("123", 3)
for i in c:
        p1 = subprocess.getoutput(f"./push_swap {' '.join(i)} | ./checker_Mac {' '.join(i)}")
        p2 = subprocess.getoutput(f"./push_swap {' '.join(i)} | wc -l")
        print(p1 + ": " + p2)