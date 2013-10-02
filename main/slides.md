!SLIDE

#MQTT

Message Queue Telemetry Transport

!SLIDE

MQTT a été initialement conçu par des chercheurs d'IBM et de Cirrus Link Solution comme un remplaçant de SNMP, simple, léger et résiliant, pour devenir un outil de pubsub "durci".

Assymétrique, il prévoit des clients légers qui délèguent une large part du travail au serveur.

!SLIDE

#Un protocole

MQTT est un protocole bien spécifié, en version 3.1 implémenté par différents clients et serveurs.
Certains sont libre et massif comme RabbitMQ ou plus léger, comme Mosquitto.

Il existe MQTT-S, une sous norme spécifique aux capteurs non TCP/IP (Zigbee, par exemple).

!SLIDE

#Simple

* TCP/IP, mode connecté, orienté message
* Authentification naïve ou certificat SSL
* Sujet en UTF8, corps en blob
* Pas de headers, mais quelques flags
* Abonnement sur des patterns
* Ping des clients

!SLIDE

#Léger

* Overhead minimaliste, 2 octets pour un petit message, plus pour un divX.
* Pas de sérialisation imposée, ni même proposée
* Fire and forget possible (QOS 0)
* Modèle évènementiel

!SLIDE

#Résiliant

* 3 niveaux de QOS
* Testament
* Boite à messages
* Routage de messages possible
