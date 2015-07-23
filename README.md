L'entity button contient ce qu'il faut pour etre draw

peut etre
  faudrait t'il poser un component drawCube qui aurait accés à l'entity et System Render
  et qui ferait le taff (yorai un héritage entre les diférents type de component draw pr généraliser l'accés)

ou alors
  c le system qui s'en charge avc genre une methode "drawEntity(button)" mais du coup yoré d cas particulier


au dessus c fait
--------
en dessou c pa fai

ensuite les events
  ptet un component event qui reçois la structure et qui fait le taff mais je croi c nul
  faut dans tous les cas SEvent qui garderait l'entity qui est selectionné
  ou alor ya un component qui di si t selectionné

pareil on peut garder le system d'ecs mais ptet laisser d truck commun o nivo de la classe entity
faudrat voir nivo perf

le component Selected il implique qu'on fasse le tour de toutes nos entity chaque fois
apré faut voir si on a une batterie d'entity

un d avantage c que c ptet + facil de gérer les entity qui en contiennent d'autre

otre chose, ptet que le srender devrai mapper les entity pour distribuer les event click sans boucler
fau voir
faut voir


mdr en fait le truck qui map les entity, c une entity psk une entity sa peu map d entity
du cou dans la factory nous faut un buildEngine
et c une entity avc le component container

<------------------>

Ptet que getter un component pourrais remplacer la factory
ou alor la factory sert a initializer ces bails

<---------->
CEvent.cpp rajouter les check pour déléguer au bon event
faire interargir + avec les children au draw et a l'event
rajouter des couleur
affichage texte
bonne nuit