
<h1 align="center">
  <a href=""><img src="https://i.postimg.cc/rFdFCjvM/img-github-airsens.png" alt="Image GitHub" width="500"></a>
  <br />
  AirSens 🇫🇷
  <br />
</h1>

<p align="center">
La solution aidant les personnes travaillant dans l'agriculture à prendre soin de leur santé.
</p>

## Qu’est-ce que AirSens ?

AirSens est un petit boîtier capable de détecter les **vapeurs** et **gaz chimiques** étant dans l'air ambiant.
Cet appareil a pour but de prévenir des **risques de santé** pouvant apparaître après une trop longue exposition à ce genre de produits.
## Comment fonctionne-t-il ?

AirSens est une solution conçue à base d'un **Arduino UNO R3**. Il se compose d'un **capteur
de qualité d'air** pour mesurer le taux de toxicité dans l'air, ce composant est capable de réagir au **monoxyde de carbone, à l'alcool, à l'acétone, au diluant, au formaldéhyde et à d'autres gaz toxiques**. 
On retrouve également une **led RGB** permettant d'indiquer à l'utilisateur la qualité de l'air par rapport à l'endroit où il se trouve selon la couleur diffusée. Et pour finir d'un
**buzzer** permettant d'avertir l'utilisateur en cas d'extrême toxicité dans l'air.

## Quels sont les composants utilisés ?

| Composants | Description | Prix
| :---         | :---         | :---         |
| [Arduino UNO R3](https://urlz.fr/joH0) | Permet de gérer et piloter les composants externes. | ~3,89 €
| [Led RGB](https://urlz.fr/joH6) | Permet de diffuser une large gamme de couleurs différentes. | ~0.04 €
| [Buzzer](https://urlz.fr/jnTP) | Permet d'émettre un son plus ou moins aigu selon la fréquence. | ~0.70 €
| [Air Quality Sensor](https://urlz.fr/jnTS) | Permet de détecter la qualité de l'air. | ~19.70 €
| [Base shield (optionel)](https://www.mouser.fr/ProductDetail/Seeed-Studio/103030000?qs=SElPoaY2y5JcWXrWV1kCmw%3D%3D&mgh=1&vip=1) | Permet de connecter plusieurs capteurs analogiques. | ~3,38 €

## Quel est le public visé ?
AirSens est principalement conçu pour les personnes traitant souvent dans leur profession
avec des produits chimiques et/ou toxiques. Cette solution a notamment été conçue pour les **agriculteurs**
étant couramment exposé et de **manière répétitive** à ce genre de produits. Nous savons, dû à leur métier que
les agriculteurs ont souvent des problèmes de santé étant provoqués par l'exposition aux produits chimiques agricoles,
tels que les **pesticides et les engrais**, ainsi qu'aux **gaz toxiques** pouvant être produits à
partir de pratiques agricoles courantes comme la **décomposition du fumier et le stockage en silo**.
(cf. [Article sur la santé des agriculteurs par Santé Publique France](https://www.santepubliquefrance.fr/les-actualites/2018/sante-des-agriculteurs-risques-et-expositions-professionnelles)).

## Comment est venue l'idée ?
Tout d'abord, nous avons effectué un brainstorming et une analyse des besoins
et des problèmes auquel les personnes dans l'agriculture pouvaient être exposées. Nous
voulions que notre produit soit **utile** et **bénéfique** pour ces personnes.

Après une analyse du domaine agricole, nous avons remarqué que les métiers composants ce secteur
était fortement exposé à des **risques de santé** multiple comme par exemple : lymphomes non hodgkiniens (LNH), myélome multiple, cancer de la prostate, maladie de Parkinson, troubles cognitifs, bronchopneumopathie chronique obstructive et bronchite chronique.

En remarquant cela, nous nous sommes dit qu'il fallait un produit permettant de **prévenir** l'apparition de toutes
ces maladies pour que nos agriculteurs soient le plus vigilant possible et essaye d'éviter au maximum ces **risques** !

C'est là qu'arrive l'idée d'AirSens ! Placer un capteur permettant de mesurer la toxicité d'air dans la poche d'un agriculteur,
qu'il pourra faire suivre toute la journée dans sa poche et qui lui indiquera si la zone où il se trouve est
trop toxique. Un produit **simple** mais **intuitif** et **facile** à prendre en main. On l'allume, on le met dans la poche et le tour est joué !

## Schéma

<div align="center">
  <img src="https://i.postimg.cc/sDWRfDGp/img-schema-electrique.png" alt="Image schéma platine d'essai" width="500">
</div>

## Librairies

- [Librarie Arduino Grove Air Quality Sensor v1.3](https://github.com/Seeed-Studio/Grove_Air_quality_Sensor)

## Communication

<div align="center">
  <img src="https://i.postimg.cc/MKhRyv33/img-poster-mockup-airsens-png.png" alt="Image schéma platine d'essai" width="500">
</div>

## Articles

- [Article sur la santé des agriculteurs par Santé Publique France (2018)](https://www.santepubliquefrance.fr/les-actualites/2018/sante-des-agriculteurs-risques-et-expositions-professionnelles)
- [Synthèse des chercheurs de l'Inserm sur les pesticides et leur effet sur la santé (2021)](https://www.inserm.fr/expertise-collective/pesticides-et-sante-nouvelles-donnees-2021/)
- [Tableau de l'INRS recensant les maladies professionnelles dans le régime agricoles (2022)](https://www.inrs.fr/publications/bdd/mp/recherche.html?typeRegime=RA&field_activites_nuisances=&field_maladies=&field_numeroCAS=&mot_cles_tableau=&motsCles=&valid_RECHERCHE_MOTSCLES=Rechercher&introspection=)

## Auteurs

> [@ahmosys (H.R)](https://github.com/ahmosys),
> [@yso8 (B.G)](https://github.com/yso8),
> [@Foufou-exe (T.M)](https://github.com/Foufou-exe),
> [@MasWap (L.L)](https://github.com/MasWap)
> [@Yangbird (N.L)](https://github.com/Yangbird)
