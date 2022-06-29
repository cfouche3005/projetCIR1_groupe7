# projetCIR1_groupe07

## Description

Projet de fin d'année de CIR 1 créé par Clément Fouché et Ryan Collobert

## Instructions d'utilisation

### Pour le programme en C :

* Les commandes suivantes doit être effectué depuis le dossier racine du projet

Pour la compilation du programme, faire ```gcc C/main.c C/Planete.c C/Trajectoire.c C/Point.c C/Vecteur.c -o NomDuProgramme -lm  -Wall```.

Pour l'éxecution, faire ```./NomDuProgramme``` dans une machine sous Linux (WSL, Machine Virtuel ou Bare Metal). Le programme crée le ```planet.json``` dans le même dossier que le programme. Il ne vous reste plus qu'a placer le json dans ```./WEB/data``` effectué les étapes suivantes.

### Pour le Web (HTML, CSS, JavaScript) :

Le projet fournit une version build du site web avec le ```./WEB/data/planet.json``` fournit avec le projet qui peut être visionné en ouvrant le ```./WEB/dist/index.html``` avec un Live-Server (VScode ou Webstorm). Pour changer de ```planet.json```, vous devez faire les étapes suivantes.

Le projet utilisant ```vite```, celui requiert NodeJS supérieur où égal à ```12.2.0```.

* Les commandes suivantes doit être effectué depuis le dossier ```./WEB```.

Effectuer ```npm install``` une seul fois puis selon votre utilisation :

* ```npm run dev``` pour ouvrir le site grace au serveur intégré par ```vite```.
Cet commande permet d'ouvrir le site lors du developement et de voir les changements en direct grace à l'auto-reload (comme Live-Server sur VScode).


* ```npm run build``` pour build le site pour une utilisation en production. Le site utilisant des imports statiques, les processsus de build intègre le JSON directement dans le fichier JS donc le build utillise beaucoup de ram (10g pour environ 60mo de JSON). Les fichiers build sont placés dans ```/WEB/dist``` et peuvent être ouvert via un simple Live-Server (VScode ou Webstorm).
