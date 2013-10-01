!SLIDE

MQTT

Message Queue Telemetry Transport

!SLIDE

MQTT est conçu comme SNMP simple, léger et résiliant, conçu par des chercheurs d'IBM et de Cirrus Link Solution. Assymétrique, il prévoit des clients léger qui délèguent tout le travail au serveur.

!SLIDE

#Un protocole

MQTT est un protocole bien spécifié, en version 3.1 implémenté par différents serveurs.
Certains sont libre comme RabbitMQ ou Mosquitto, bien plus léger.

Il existe MQTT-S, spécifique aux capteurs non TCP/IP.

!SLIDE

#Simple

* TCP/IP, mode connecté, orienté message
* Authentification naïve ou certificat SSL
* Sujet en UTF8, corps en blob
* Pas de headers, mais quelques flags
* Abonnement sur des patterns
* Ping des cliens

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
