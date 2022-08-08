# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    test.sh                                            :+:    :+:             #
#                                                      +:+                     #
#    By: mjiam <mjiam@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/11 14:44:51 by mjiam         #+#    #+#                  #
#    Updated: 2022/02/28 12:09:18 by tevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# COLORS
CYAN="\033[0;36m"
PURP="\033[0;35m"
GREEN="\033[0;72m"
BLUE="\033[0;34m"
BLUEBG="\033[44m"
WHITE="\033[1;97m"
RESET="\033[0m"
TNUM=1

if [ ! -f "../cub3D" ]; then
    printf "${GREEN}Error: ./cub3D not found. Run make first${RESET}\n"
else
    printf "\n${BLUEBG}${WHITE}Beginning Invalid Map Test${RESET}\n"
    printf "\n${CYAN}Test ${TNUM}/21: < 0 floor colour values${RESET}\n"
    cd ..; ./cub3D cub3d_tester/maps/col_inv.cub
    ((TNUM+=1))
    printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: > 255 ceiling colour value${RESET}\n"
        ./cub3D cub3d_tester/maps/col_inv2.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: invalid character between colour value${RESET}\n"
        ./cub3D cub3d_tester/maps/col_inv3.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: missing 1 of ceiling colour values${RESET}\n"
        ./cub3D cub3d_tester/maps/col_inv4.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: invalid character between colour values${RESET}\n"
        ./cub3D cub3d_tester/maps/col_inv5.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: valid 0,0,0 floor colour${RESET}\n"
        ./cub3D cub3d_tester/maps/col_valid0.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${PURP}Test ${TNUM}/21: duplicate starting direction${RESET}\n"
        ./cub3D cub3d_tester/maps/dir_dup.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${PURP}Test ${TNUM}/21: invalid starting direction character${RESET}\n"
        ./cub3D cub3d_tester/maps/dir_inv.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${PURP}Test ${TNUM}/21: missing starting direction${RESET}\n"
        ./cub3D cub3d_tester/maps/dir_none.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${BLUE}Test ${TNUM}/21: duplicate wall texture${RESET}\n"
        ./cub3D cub3d_tester/maps/tex_dup.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${BLUE}Test ${TNUM}/21: invalid element identifier${RESET}\n"
        ./cub3D cub3d_tester/maps/tex_inv.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${BLUE}Test ${TNUM}/21: missing East wall texture${RESET}\n"
        ./cub3D cub3d_tester/maps/tex_miss.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${BLUE}Test ${TNUM}/21: space in texture file path. Should run correctly.${RESET}\n"
        ./cub3D cub3d_tester/maps/tex_space.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: newline in map${RESET}\n"
        ./cub3D cub3d_tester/maps/map_nl.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: missing map${RESET}\n"
        ./cub3D cub3d_tester/maps/map_none.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: invalid open map${RESET}\n"
        ./cub3D cub3d_tester/maps/map_open.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: invalid open map #2 ${RESET}\n"
        ./cub3D cub3d_tester/maps/map_opensp.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: invalid open map #3 (start in wall)${RESET}\n"
        ./cub3D cub3d_tester/maps/map_opendir.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: invalid open map #4 (diagonal)${RESET}\n"
        ./cub3D cub3d_tester/maps/map_opendiag.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
        printf "\n${CYAN}Test ${TNUM}/21: valid open map. Should run correctly.${RESET}\n"
        ./cub3D cub3d_tester/maps/map_openvalid.cub
        ((TNUM+=1))
        printf "\n${BLUEBG}${WHITE}Press ENTER for next test${RESET}\n"
    else
        printf "Exiting test\n"
        exit 1
    fi
    read -s -n 1 KEY
    if [$KEY == ""] ; then
    printf "\n${PURP}Test ${TNUM}/21: invalid .cub (folder) as input file. Should error without crash.${RESET}\n"
    ./cub3D cub3d_tester/maps/folder.cub
    ((TNUM+=1))
    fi
fi