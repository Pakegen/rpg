/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:18:10 by quenalla          #+#    #+#             */
/*   Updated: 2024/09/06 14:00:03 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

struct	s_barre_de_vie{
	int	joueur;
	int	ennemies;
	int	allies;
};
struct	s_attack{
	int		attack_joueur;
	int		attack_ennemies;
	int	attack_allies;
};
struct	s_heal{
	int	heal_joueur;
	int	heal_ennemies;
	int	heal_allies;
};

typedef struct s_barre_de_vie	st;
typedef struct s_attack			lt;
typedef struct s_heal			rt;

int	main(void)
{
	int i;
	int suicidal_blast;

	i = 1;
	suicidal_blast = 15;

	st	s_barre_de_vie1;
	lt	s_attack1;
	rt	s_heal1;

	s_barre_de_vie1.joueur = 1;
	s_barre_de_vie1.ennemies = 8;
	s_barre_de_vie1.allies = 8;
	s_attack1.attack_joueur = 2;
	s_attack1.attack_ennemies = 2;
	s_attack1.attack_allies = 1;
	s_heal1.heal_joueur = 0;
	s_heal1.heal_ennemies = 0;
	s_heal1.heal_allies = 1;


	while ((s_barre_de_vie1.joueur >= 1 ||  s_barre_de_vie1.allies >= 1) && s_barre_de_vie1.ennemies >= 1)
	{
		printf("\n%d Rounds !\n", i);
		i++;
		printf("\nLe Hero a %dpv\nLes allies ont %dpv\nLes ennemies ont %dpv.\n\n", s_barre_de_vie1.joueur, s_barre_de_vie1.allies, s_barre_de_vie1.ennemies);
		if (s_barre_de_vie1.joueur <= 0 && s_barre_de_vie1.allies > 0 && s_barre_de_vie1.allies < 5 && s_barre_de_vie1.ennemies >= 8)
		{
			s_barre_de_vie1.allies = 0;
			s_barre_de_vie1.ennemies = s_barre_de_vie1.ennemies - suicidal_blast;
			printf("\nLe hero etant vaincu ses compagnons deciderent de lancer 'suicidal blast' surchauffant leurs mana, qui provoqua une explosions magique rasant tous les alentours, ");
			if (s_barre_de_vie1.ennemies < 1)
				return (printf("emportant toutes l armee du mal \n\n[SUICIDAL ENDING]\n"));
			else
				return (printf("cependant le roi Demon survecut mais blesse il retourna dans son chateau pour guerir de ses blessures et pour reformer son armees, les humains ne peuvent qu'esperer qu un nouveau hero emergera avant que le roi demon ne guerisse !\n\n[SEQUEL ENDING]\n"));
		}
		if ((s_barre_de_vie1.joueur > 2 || s_barre_de_vie1.joueur >= 0 )&& s_barre_de_vie1.allies > 0)
		{
			s_barre_de_vie1.ennemies = s_barre_de_vie1.ennemies - s_attack1.attack_allies;
			printf("Les allies utilise 'fire ball' et 'quick shot', les allies font %d de degats, les demons n ont plus que %d.\n", s_attack1.attack_allies, s_barre_de_vie1.ennemies);
		}
		if (s_barre_de_vie1.joueur <= 2 && s_barre_de_vie1.joueur > 0 && s_barre_de_vie1.allies > 0)
		{
			s_barre_de_vie1.joueur = s_barre_de_vie1.joueur + s_heal1.heal_allies;
			printf("les allies utilise 'soin', la vie du hero remonte a %dpv.\n", s_barre_de_vie1.joueur);
		}
		if (s_barre_de_vie1.joueur > 0)
		{
			s_barre_de_vie1.ennemies = s_barre_de_vie1.ennemies - s_attack1.attack_joueur;
			printf("le hero utilise 'slash brave' il fait %d degats.\nles ennemies ne leurs restent que %dpv.\n", s_attack1.attack_joueur, s_barre_de_vie1.ennemies);
		}
		if (s_barre_de_vie1.ennemies > 0)
		{
			if (s_barre_de_vie1.joueur > 0)
			{
				s_barre_de_vie1.joueur = s_barre_de_vie1.joueur - s_attack1.attack_ennemies;
				printf ("Les Demons attaques le hero, ils lui font %d degats, il ne lui reste plus que %dpv.\n",s_attack1.attack_ennemies, s_barre_de_vie1.joueur);
				if (s_barre_de_vie1.joueur <= 0)
					printf("Le Hero est vaincu\n");
			}
			if (s_barre_de_vie1.allies > 0)
			{
				s_barre_de_vie1.allies = s_barre_de_vie1.allies - s_attack1.attack_ennemies;
				printf ("Les Demons attaques les allies du heros, ils font %d degats, les compagnons du hero n ont plus que %dpv.\n",s_attack1.attack_ennemies, s_barre_de_vie1.allies);
				if (s_barre_de_vie1.allies <= 0)
					printf("Les Allies du hero sont vaincus");
			}
		}
	}
	if (s_barre_de_vie1.joueur <= 0 && s_barre_de_vie1.ennemies <= 0)
		return (printf("\nLe Hero se sacrifia pour vaincre les forces du mal, ses compagnons conterent jusqu'a la fin de leurs jours l heroisme du brave\n\n[GLORY ENDING]\n"));
	else if (s_barre_de_vie1.joueur < 1)
		return (printf("\nLe Hero et ses compagnons fut defaits par les forces du mal. Les demons ont envahies le royaumes humains et enslaves la population\n\n[BAD ENDING]\n"));
	else if (s_barre_de_vie1.ennemies < 1 && s_barre_de_vie1.allies < 1)
		return (printf("\nLe Hero Vaincu les forces du mal mais aux prix de la vie de ses allies, 10 ans plus tard il succombera a son tour vaincu par le desespoir\n\n[SAD ENDING]\n"));
	else if (s_barre_de_vie1.ennemies < 1)
		return (printf("\nLe Hero et ses allies vaincurent les forces du mal\n\n[Happy Ending]\n"));
}
