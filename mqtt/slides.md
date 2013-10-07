!SLIDE

#MQTT

Message Queue Telemetry Transport

!SLIDE

MQTT a été initialement conçu par des chercheurs d'IBM et de Cirrus Link Solution
comme un remplaçant de SNMP, simple, léger et résilient.

Il fonctionne à l'envers, on s'abonne pour recevoir des informations, plutôt que l'inefficace polling.

Les clients sont actifs, envoient et reçoivent des évènements.

!SLIDE

##Un protocole

MQTT est un protocole bien spécifié, en version 3.1, implémenté par différents clients et serveurs.
Il souhaiterait devenir un standard OASIS.
Certaines implémentations sont libres et massives comme RabbitMQ ou plus légères, comme Mosquitto.

Il existe MQTT-S, une sous norme spécifique aux capteurs non TCP/IP (Zigbee, par exemple).

!SLIDE

##Simple

* TCP/IP, mode connecté, orienté message
* Authentification naïve ou certificat SSL
* Sujet en UTF8, _payload_ en blob
* Pas de headers, mais quelques flags
* Abonnement sur des patterns
* Ping des clients

!SLIDE

##Léger

* Overhead minimaliste, 2 octets pour un petit message, 5 octets pour 256M.
* _Topic_ de 64k maximum
* Pas de sérialisation imposée, ni même proposée
* Fire and forget possible (QOS 0), ainsi qu'un mode déconnecté
* Modèle évènementiel

!SLIDE

##Résilient

* 3 niveaux de QOS : pas plus d’un, au moins un, juste un.
* Testament et dernière volonté
* Boite à messages
* Routage de messages possible
* Rétention de messages

!SLIDE

##Testament et dernière volonté

Un message est préparé (topic, payload, qos, retain) et ne sera délivré qu'en cas de disparition brutale du client.

## Rétention

Lors d'une publication, il est possible d'activer le bit _retain_.
Les nouveaux venus recevront ce message dès leur abonnement.

!SLIDE

##Monde réel

MQTT a plus de 10 ans et est utilisé dans des contextes variés

* 17 000 km de pipelines pétroliers, 30k capteurs
* Monitoring de pacemakeur
* Applications iOS Facebook

!SLIDE

##Code

* Il possible de l'utiliser sans toucher à du code d'IBM ou même Eclipse
* Son modèle évènementiel fait un peu grincer les langages séquentiels
* Beaucoup de serveurs pour peu de clients. CLI, C, python, lua, Objective-C
* Proxy websockets existant, mais sans normes
* Rien n'est prévu pour découvrir le broker, il faut configurer l'application

!SLIDE

##Démo

Mosquitto comme broker.

Un client Arduino avec une photorésistance et une DEL.

!SLIDE
##Usage possible

La télémétrie n'est qu'un des messages possibles.

* Call back pour des taches longues (Jenkins, Transmission…)
* Ping et alerte
* Hook asynchrone pour un serveur synchrone
* Controle de zombies

MQTT empiète partiellement sur AMQP, XMPP, IRC, SNMP, OSC, etcd…
