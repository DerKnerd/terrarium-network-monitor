//
// Created by imanuel on 06.09.19.
//

#include <server/PrometheusServer.h>
#include <temperature/Thermometer.h>
#include <humidity/HumiditySensor.h>

auto server = new PrometheusServer();
auto thermometer = new Thermometer();
auto humidity = new HumiditySensor();

void setup() {
    server->setup();
    thermometer->setup(2);
    humidity->setup(3);
}

void loop() {
    server->handleRequest(
            thermometer->getTemperature(1),
            thermometer->getTemperature(0),
            humidity->getHumidity()
    );
}