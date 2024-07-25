import time
from gfx_pack import GfxPack, SWITCH_A, SWITCH_B, SWITCH_C, SWITCH_D, SWITCH_E
import random
import network
from umqtt_simple import MQTTClient
from wifi_settings import WifiSettings

class Main:

    def __init__(self):
        self.__MQTT_SERVER = "192.168.1.4"
        self.__MQTT_PORT = 1883
        self.__MQTT_USER = "jsdale"
        self.__MQTT_PASSWORD = "wibble"
        self.__MQTT_CLIENT_ID = b'f1-telemetry-wheel'
        self.__MQTT_TOPIC_SUBSCRIBE = 'f1.telemetry.cardata'
        self.set_up()

    def clear(self):
        self.display.set_pen(0)
        self.display.clear()
        self.display.set_pen(self.pen_size)
        
    def initialize_wifi(self):
        settings = WifiSettings()
        wlan = network.WLAN(network.STA_IF)
        wlan.active(True)
        wlan.connect(settings.get_ssid(), settings.get_password)
        connected = False
        while connected is False:
            if wlan.status() >= 3:
                break
            connection_timeout -= 1
            print('Waiting for Wi-Fi connection...')
            sleep(1)
        if wlan.status() == 3:
            connected = True
        print('Connection successful!')
        network_info = wlan.ifconfig()
        print('IP address:', network_info[0])

    def connect_mqtt(self):
        client = MQTTClient(client_id=self.__MQTT_CLIENT_ID, server=self.__MQTT_SERVER, port=self.__MQTT_PORT, user=self.__MQTT_USER, password=self.__MQTT_PASSWORD, keepalive=7200)
        client.connect()
        return client
        
    def subscribe(self, client, topic):
        client.subscribe(topic)
        print('Subscribed to topic:', topic)
        
    def my_callback(topic, message):
        print('Received message on topic:', topic)
        print('Message:', message)
        self.display_gear(message)

    def set_up(self):
        self.lowest = 1
        self.highest = 6
        self.pen_size = 15
        self.width = 0
        self.height = 0

        self.gp = GfxPack()
        self.display = self.gp.display

        self.width, self.height = self.display.get_bounds()
        self.display.set_backlight(0)
        self.display.set_font("bitmap8")

        self.gp.set_backlight(0, 0, 0, 125)
        self.clear()
        self.display.set_pen(self.pen_size)
        self.display.text("Welcome, Jacob.", 0, 0, self.width, 2)
        self.display.update()
        
    def display_gear(self, gear):
        self.display.text(f"{gear}", int(self.width/2)-self.pen_size, int(self.height/2)-self.pen_size, 0, 5)
        self.display.update()
        time.sleep(0.2)
        
    def loop(self):
        try:
            self.initialize_wifi()
            client = self.connect_mqtt()
            client.set_callback(self.my_callback)
            subscribe(client, self.MQTT_TOPIC_SUBSCRIBE)
            while True:
                sleep(0.2)
                client.check_msg()
        except Exception as e:
            print('Error:', e)

main = Main()
main.loop()
