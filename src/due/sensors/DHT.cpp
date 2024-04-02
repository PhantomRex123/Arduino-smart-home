#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ArduinoJson.h>
#include "Pinouts.h"
// DHT setup
DHT_Unified dht(DHT_INPUT, DHT_TYPE);

String dht_sensor_info(String type)
{
    sensor_t sensor;
    (type == "temp") ? dht.temperature().getSensor(&sensor) : dht.humidity().getSensor(&sensor);
    JsonDocument temp_info;

    temp_info["name"] = sensor.name;
    temp_info["version"] = (sensor.version);
    temp_info["id"] = (sensor.sensor_id);
    temp_info["values"] = "max:" + String(sensor.max_value) + ";" + "min:" + String(sensor.min_value) + ";";
    temp_info["res"] = (sensor.resolution);
    String output;

    temp_info.shrinkToFit();  // optional

    serializeJson(temp_info, output);
    return output;
}

String dht_sensor_get_data(String type)
{
    sensors_event_t event;
    String data;
    JsonDocument temp_info;
    (type == "temp") ? dht.temperature().getEvent(&event) : dht.humidity().getEvent(&event);
    if (!isnan((type == "temp") ? event.temperature : event.relative_humidity))
    {
        temp_info["data"] = String((type == "temp") ? event.temperature : event.relative_humidity);
    }
    else {
        temp_info["data"] = "E:fail(dht_sensor_get_humidity)";
    }
    temp_info.shrinkToFit();
    serializeJson(temp_info, data);
    return data;
}
