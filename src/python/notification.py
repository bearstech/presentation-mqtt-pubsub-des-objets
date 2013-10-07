import mosquitto
from subprocess import Popen

client = mosquitto.Mosquitto("test-python")
client.connect("127.0.0.1")


def on_message(mosq, obj, msg):
    Popen(['terminal-notifier', '-message',
           '"%s: %s"' % (msg.topic, msg.payload)])
client.on_message = on_message

client.subscribe("led/#", 2)
client.publish("hello", "from Python", 1)

client.loop_forever()
